//Compile command:
//  gcc main.c -o main -Wall `pkg-config fuse --cflags` `pkg-config fuse --libs` -L. -lrequests -lcurl json.c -lm

//Run the executable command:
//  ./main [nama_folder_untuk_memuat_hasil_mount] [nama_pokemon_yang_hendak_disimpan]

#include <stdio.h>			// Akses ke fungsi input/output
#include <stdlib.h>			// Akses ke utilitas tambahan

#include <sys/types.h>		// Akses ke tipe-tipe data tambahan

// Akses ke fungsi yang mampu mendapatkan informasi/atribut dari file/folder
#include <sys/stat.h>		
#include <unistd.h>			// Akses ke fungsi-fungsi system call
#include <sys/wait.h>		// Akses ke fungsi wait()

#include <string.h>			// Akses ke fungsi manipulasi string
#include "requests.h"		// Akses ke utilitas librequests
#include "json.h"			// Akses ke utilitas json-parser

#define FUSE_USE_VERSION 28	// Menyatakan versi FUSE yang dipakai
#include <fuse.h>			// Akses ke segala keperluan dalam FUSE
#include <fcntl.h>			// Akses ke fungsi rekayasa file
#include <dirent.h>			// Akses ke fungsi pembacaan direktori

// Akses ke variabel errno yang merepresentasikan kesalahan yang terjadi
#include <errno.h>		

// Path dari direktori yang akan di-mount
static  const  char *mount_dir = "/home/pandu/Documents";	

// Akan dipakai sebagai indikasi bahwa file/folder tidak ada
struct stat st = {0};										

// Menyimpan path direktori untuk menyajikan data pokemon kedepannya
char data_dir[255];											

// -----------------------------------------------------------------------------------------------------------

// FUSE operation (.getattr)
// Memungkinkan untuk mendapatkan informasi mengenai file/folder di dalam mounted directory
static int my_getattr(const char *path, struct stat *stbuf)
{
	int res;
	char fpath[1000];

	sprintf(fpath, "%s%s", mount_dir, path);

	res = lstat(fpath, stbuf);

	if (res == -1) return -errno;

	return 0;
}

// FUSE operation (.readdir)
// Memungkinkan untuk mendapatkan/membaca isi direktori di dalam mounted directory
static int my_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi)
{
	char fpath[1000];

	if(strcmp(path, "/") == 0)
	{
		path = mount_dir;
		sprintf(fpath, "%s", path);
	}
	else sprintf(fpath, "%s%s", mount_dir, path);

	int res = 0;

	DIR *dp;
	struct dirent *de;
	(void) offset;
	(void) fi;

	dp = opendir(fpath);

	if (dp == NULL) return -errno;

	while ((de = readdir(dp)) != NULL) {
		struct stat st;

		memset(&st, 0, sizeof(st));

		st.st_ino = de->d_ino;
		st.st_mode = de->d_type << 12;
		res = (filler(buf, de->d_name, &st, 0));

		if(res!=0) break;
	}

	closedir(dp);

	return 0;
}

// FUSE operation (.read)
// Memungkinkan untuk membuka/membaca file di dalam mounted directory
static int my_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi)
{
	char fpath[1000];
	if(strcmp(path, "/") == 0)
	{
		path = mount_dir;

		sprintf(fpath, "%s", path);
	}
	else sprintf(fpath, "%s%s", mount_dir, path);

	int res = 0;
	int fd = 0 ;

	(void) fi;

	fd = open(fpath, O_RDONLY);

	if (fd == -1) return -errno;

	res = pread(fd, buf, size, offset);

	if (res == -1) res = -errno;

	close(fd);

	return res;
}

// Membungkus operasi-operasi yang bisa dilakukan di dalam/pada mounted directory
static struct fuse_operations my_operations = {
    	.getattr = my_getattr,
    	.readdir = my_readdir,
    	.read = my_read,
};

// -----------------------------------------------------------------------------------------------------------

// Mengambil data dari API
json_value *get_data(char *api_url, json_value *data_object)
{
    // req, untuk menyimpan hasil request data
	req_t req;								
	int ret = requests_init(&req);		// Menyiapkan req
	if (ret) {
        // Keluar, jika req gagal/tidak siap menyimpan hasil request
		return NULL;						
	}

    // Mengirim GET Request ke url sekaligus menyimpan hasilnya di req
	requests_get(&req, api_url);			
	printf("Request URL: %s\n", req.url);
	printf("Request Code: %lu\n", req.code);
    // Mengubah text yang didapat menjadi JSON
	data_object = json_parse(req.text, req.size);	

	requests_close(&req);				// Membersihkan req

	return data_object;
}

// Membuat folder/directory
int make_directory(char *path)
{
    // Jika direktori tidak ditemukan
	if (stat(path, &st) == -1)			
	{
		if (mkdir(path, 0777) == 0)		// Buat direktori
		{
			printf("\n--> Direktori [%s] berhasil dibuat\n", path);
			return 0;
		}
		else
		{
			printf("\n--> Direktori [%s] gagal dibuat\n", path);
			return -1;
		}
	}
	// Jika direktori ditemukan, return 1
	return 1;
}

// Mengunduh gambar dan menyimpannya dalam path direktori yang diberikan
void download_image(char* url, char* cwd, char* name, char* format)
{
    // Bersiap untuk membuat child process
	pid_t child_id;					
	int status;

	child_id = fork();	// Membuat fork
	wait(&status);

    // Child process akan mengunduh gambar secara async
	if (child_id == 0)
	{
        // curl, untuk mendownload data gambar
		CURL* curl;
        // fptr, untuk file yang akan diisi data gambar					
		FILE* fptr;

        // Menyiapkan path dan nama dari file
		char file_path[64];
		strcpy(file_path, cwd);
		strcat(file_path, "/");
		strcat(file_path, name);
		strcat(file_path, format);
		int result;

        // Buka/buat file dalam mode "write-binary"
		fptr = fopen(file_path, "wb"); 		

		curl = curl_easy_init();    // Menyiapkan curl

        // Mengunduh data dari url
		curl_easy_setopt(curl, CURLOPT_URL, url);			

        // Menulis data ke file
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fptr);	

        // Menyiapkan pesan error yang akan ditampilkan jika gagal
		curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);	

		result = curl_easy_perform(curl);

        // Tampilkan peringatkan sesuai hasil dari proses di atas
		if (result == CURLE_OK)					
			printf("\nDownload [%s] berhasil\n\n", file_path);
		else
			printf("\nGagal Download Gambar: %s\n\n", curl_easy_strerror(result));

        // Matikan proses async ini (child process)
		kill((int)getpid(), SIGKILL);			
	}
}

// Mengunduh semua gambar/sprite dari url-url dalam object form
static void collect_form_sprites(char* api_url, char* cwd)
{
    // Untuk menyimpan data JSON
	json_value *pokemon_form;

    // Mengambil data forms		
	pokemon_form = get_data(api_url, pokemon_form);	

    // Jika data didapatkan, maka jelajahi data
	if (pokemon_form != NULL)
	{
		int dataLen = pokemon_form->u.object.length;
		printf("pokemon_form [dataLen: %d] berhasil didapatkan\n", dataLen);

        // Menjelajahi data yang didapatkan ..
		for (int x = 0; x < dataLen; x++)
		{
            // ..hingga menemukan object bernama "sprites"
			if (strcmp(pokemon_form->u.object.values[x].name, "sprites") == 0)
			{
                // Menjelajahi tiap properti
				int sprites_num = pokemon_form->u.object.values[x].value->u.object.length;
				for (int y = 0; y < sprites_num; y++)			
				{
					// Jika properti merupakan string, pada kasus ini menyimpan url gambar, maka download gambar
					switch (pokemon_form->u.object.values[x].value->u.object.values[y].value->type) {
						case json_string:
							download_image(pokemon_form->u.object.values[x].value->u.object.values[y].value->u.string.ptr, 
											cwd, 
											pokemon_form->u.object.values[x].value->u.object.values[y].name, 
											".png");
							break;
					}
				}

				break;
			}
		}
        // Membebaskan variabel pokemon_form yang menyimpan data JSON
		json_value_free(pokemon_form);
	}
}

// Prototype fungsi process_value (Deklarasi fungsi)
static void process_value(json_value* value, char* cwd);

// Memproses data JSON bertipe object
static void process_object(json_value* value, char* cwd)
{
    // Variabel yang diperlukan dalam scope ini
    int length, x, is_dir, infofile = 0, infofile_newname = 0;
	char temp_dir[512];

    // Nama default untuk file text
	char infofile_old[64] = "additional_information.txt";
	char info_dir[512];
	char info_dir_new[512];
	FILE* fptr;

    // Keluar jika value(object) kosong
	if (value == NULL) {
			return;
	}

    // Jumlah property object
	length = value->u.object.length;

    // Jelajahi isi/tiap property object
	for (x = 0; x < length; x++)
	{
		is_dir = 0;
            // Merikasa apakah property object ke-x merupakan object/array
	        switch (value->u.object.values[x].value->type) {
			case json_object:
				is_dir = 1;
				break;
			case json_array:
				is_dir = 1;
				break;
		}

        // Jika property ke-x merupakan sebuah object atau array, maka buat folder sesuai namanya
        if (is_dir == 1)			
        {
            strcpy(temp_dir, cwd);
            strcat(temp_dir, "/");
            strcat(temp_dir, value->u.object.values[x].name);
            make_directory(temp_dir);
            printf("object[%d].name = %s\n", x, value->u.object.values[x].name);

            // Prosess lagi isinya, karena isinya masih berupa object/array
            process_value(value->u.object.values[x].value, temp_dir);
        }
        else if (is_dir == 0)
        {
            // Jika property ke-x bukan merupakan object/array, maka buat file untuk menampung infromasinya

            // Jika infofile belum dibuat, maka buat
            if (infofile == 0)		
            {
                strcpy(info_dir, cwd);
                strcat(info_dir, "/");
                strcat(info_dir, infofile_old);
                fptr = fopen(info_dir, "w");
                infofile = 1;
            }
            if (infofile == 1)
            {
                // Jika infofile sudah tersedia, maka tambahkan isinya dengan infomasi dari property ke-x

                // Menulis informasi ke infofile berdasarkan tipe dari informasinya
                switch (value->u.object.values[x].value->type) {
                    case json_integer:
						fprintf(fptr, "%s: %ld\n", value->u.object.values[x].name, value->u.object.values[x].value->u.integer);
						break;
					case json_double:
						fprintf(fptr, "%s: %f\n", value->u.object.values[x].name, value->u.object.values[x].value->u.dbl);
						break;
					case json_string:
						fprintf(fptr, "%s: %s\n", value->u.object.values[x].name, value->u.object.values[x].value->u.string.ptr);

						// Jika property ke-x merupakan "name", pakai value-nya sebagai nama infofile
						if (strcmp(value->u.object.values[x].name, "name") == 0)
						{
							strcpy(info_dir_new, cwd);
							strcat(info_dir_new, "/");
							strcat(info_dir_new, value->u.object.values[x].value->u.string.ptr);
							infofile_newname = 1;
						}
						// Jika value merupakan url gambar PNG, maka download gambar
						if (strstr(value->u.object.values[x].value->u.string.ptr, ".png") != NULL)
						{
							download_image(value->u.object.values[x].value->u.string.ptr, cwd, value->u.object.values[x].name, ".png");
						}

						// Jika value merupakan url gambar SVG, maka download gambar
						if (strstr(value->u.object.values[x].value->u.string.ptr, ".svg") != NULL)
						{
							download_image(value->u.object.values[x].value->u.string.ptr, cwd, value->u.object.values[x].name, ".svg");
						}

						break;
					case json_boolean:
						fprintf(fptr, "%s: %d\n", value->u.object.values[x].name, value->u.object.values[x].value->u.boolean);
						break;
                }
            }
        }

        printf("[Tulis ke file text di CWD: %s]> object[%d].property = %s \n", cwd, x, value->u.object.values[x].name);

        // Jika CWD merupakan isi dari "forms" ..
		if (strstr(cwd, "forms/") != NULL)
		{
            // ..dan property ke-x merupakan url, ..
			if (strcmp(value->u.object.values[x].name, "url") == 0)
			{
                // ..maka download semua gambar/sprites.
				collect_form_sprites(value->u.object.values[x].value->u.string.ptr, cwd);
			}
		}
	}

    // Jika dalam direktori ini dibuat/dibuka infofile, maka tutup pointernya
	if (infofile == 1)
	{
		fclose(fptr);
        // Setelah ditutup, jika ada porperty name (ada nama baru), maka pakai sebagai nama infofile
		if (infofile_newname == 1)
		{
			strcat(info_dir_new, ".txt");
			rename(info_dir, info_dir_new);
		}
	}
}

// Memproses data JSON bertipe array
static void process_array(json_value* value, char* cwd)
{
    // Variabel yang diperlukan dalam scope ini
    int length, x, prop_num, prop_prop_num, folder_name_ext = 0;
	char temp_dir[512], str_index[5];
	char folder_name[64];

    // Keluar jika value(array) kosong
	if (value == NULL) {
			return;
	}

    // Jumlah object yang disimpan array
	length = value->u.array.length

    // Menjelajahi tiap object di dalamm array
	for (x = 0; x < length; x++) {
		folder_name_ext = 0;
		prop_num = value->u.array.values[x]->u.object.length;

        // Menjelajari tiap property dari object dalam array
		for (int y = 0; y < prop_num; y++) {
            // Jika nama yang dicari sudah didapat dari iterasi seblumnya, keluar
			if (folder_name_ext == 1)
			{
				break;
			}
            // Jika ditemukan property name, simpan value-nya
			if (strcmp(value->u.array.values[x]->u.object.values[y].name, "name") == 0)
			{
                // menyimpan value dari name ke folder_name
				strcpy(folder_name, value->u.array.values[x]->u.object.values[y].value->u.string.ptr);
                // Tanda bahwa nama yang dicari telah ditemukan
				folder_name_ext = 1;
				break;
			}
				switch (value->u.array.values[x]->u.object.values[y].value->type) {
				case json_object:
					// Mencari property name lebih dalam
					prop_prop_num = value->u.array.values[x]->u.object.values[y].value->u.object.length;
					for (int z = 0; z < prop_prop_num; y++)
					{
						// Jika ditemukan property name, simpan value-nya
						if (strcmp(value->u.array.values[x]->u.object.values[y].value->u.object.values[z].name, "name") == 0)
						{
                            // simpan isi properti "name"
							strcpy(folder_name, value->u.array.values[x]->u.object.values[y].value->u.object.values[z].value->u.string.ptr);
                            // Tanda bahwa nama yang dicari telah ditemukan
							folder_name_ext = 1;
							break;
						}
					}
					break;
			}
		}

        // Menyiapkan nama folder dan path-nya
		strcpy(temp_dir, cwd);
		strcat(temp_dir, "/");

        // Jika dalam 1 sampai 2 object ke dalam ditemukan property name, ..
		if (folder_name_ext == 1)
		{
            // .. maka pakai name tersebut sebagai nama folder untuk object ke-x
			strcat(temp_dir, folder_name);
		}
		else
		{
            // Jika dalam 1 sampai 2 object ke dalam tidak ditemukan property name, ..
            // .. maka pakai nomor indeks (x) sebagai nama folder untuk object ke-x
			sprintf(str_index, "%d", x);
			strcat(temp_dir, str_index);
		}
        // Membuat folder untuk object ke-x
		make_directory(temp_dir);
        // Prosess lagi isinya, karena isinya masih berupa object
		process_value(value->u.array.values[x], temp_dir);
	}
}

// Mengarahkan value untuk di olah fungsi yang tepat
static void process_value(json_value* value, char *cwd)
{
        // Keluar jika value kosong
        if (value == NULL) {
                return;
        }
        // Memeriksa tipe value
        switch (value->type) {
                case json_object:
                        // Jika value bertipe object, ..
                        // .. maka olah value sebagai object
                        process_object(value, cwd);	
                        break;
                case json_array:
                        // Jika value bertipe array, ..
                        // .. maka olah value sebagai array
                        process_array(value, cwd);
                        break;
        }
}

// Fungsi utama yang menerima 2 argumen yaitu [nama_folder] dan [nama_pokemon]
int main(int argc, char *argv[])
{
    // Argumen 0 = path dari dokumen executable
    // Argumen 1 = nama folder yang akan memuat hasil mount
    // Argumen 2 = nama pokemon yang datanya hendak didapatkan
    if (argc > 1 && argc <= 3)
    {
        // Menyiapkan URL API dan path CWD
        char api_url[255] = "https://pokeapi.co/api/v2/pokemon/";
        strcat(api_url, argv[2]);			
        sprintf(data_dir, "%s/%s", mount_dir, argv[2]);	

        // Jika direkori data pokemon yang dimaksud sudah ada
        if (stat(data_dir, &st) == 0)
        {
            printf("PERINGATAN: Data pokemon [%s] sudah tersedia dalam [%s].\n", argv[2], data_dir);
            return 0;
        }

        // Mengambil data dari api_url dan menyimpannya dalam pokemon
        json_value *pokemon;
        pokemon = get_data(api_url, pokemon);

        // Jika data pokemon tidak kosong/berhasil didapatkan
        if (pokemon != NULL)
        {
            // Buat direktori dengan nama pokemon yang didapat
            make_directory(data_dir);

            // Dalam diretori tersebut, sajikan data yang didapat folder/file memuat informasi pokemon
            process_value(pokemon, data_dir);

            // Membebaskan variabel pokemon yang menyimpan data JSON
            json_value_free(pokemon);

            // Keluar dan jalankan FUSE
            return fuse_main(argc - 1, argv, &my_operations, NULL);
        }
        else
        {
            // Jika data pokemon kosong/tidak didapatkan
            printf("GAGAL: Data pokemon [%s] tidak bisa ditemukan atau didapatkan dari [%s].\n", argv[2], api_url);
        }
    }
	return 0;
}
