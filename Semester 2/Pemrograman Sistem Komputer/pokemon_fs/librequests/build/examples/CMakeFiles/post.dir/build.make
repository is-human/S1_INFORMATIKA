# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pandu/pokemon_fs/librequests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pandu/pokemon_fs/librequests/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/post.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/post.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/post.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/post.dir/flags.make

examples/CMakeFiles/post.dir/post.c.o: examples/CMakeFiles/post.dir/flags.make
examples/CMakeFiles/post.dir/post.c.o: ../examples/post.c
examples/CMakeFiles/post.dir/post.c.o: examples/CMakeFiles/post.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pandu/pokemon_fs/librequests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/post.dir/post.c.o"
	cd /home/pandu/pokemon_fs/librequests/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/post.dir/post.c.o -MF CMakeFiles/post.dir/post.c.o.d -o CMakeFiles/post.dir/post.c.o -c /home/pandu/pokemon_fs/librequests/examples/post.c

examples/CMakeFiles/post.dir/post.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/post.dir/post.c.i"
	cd /home/pandu/pokemon_fs/librequests/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pandu/pokemon_fs/librequests/examples/post.c > CMakeFiles/post.dir/post.c.i

examples/CMakeFiles/post.dir/post.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/post.dir/post.c.s"
	cd /home/pandu/pokemon_fs/librequests/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pandu/pokemon_fs/librequests/examples/post.c -o CMakeFiles/post.dir/post.c.s

# Object files for target post
post_OBJECTS = \
"CMakeFiles/post.dir/post.c.o"

# External object files for target post
post_EXTERNAL_OBJECTS =

examples/post: examples/CMakeFiles/post.dir/post.c.o
examples/post: examples/CMakeFiles/post.dir/build.make
examples/post: src/librequests.a
examples/post: examples/CMakeFiles/post.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pandu/pokemon_fs/librequests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable post"
	cd /home/pandu/pokemon_fs/librequests/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/post.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/post.dir/build: examples/post
.PHONY : examples/CMakeFiles/post.dir/build

examples/CMakeFiles/post.dir/clean:
	cd /home/pandu/pokemon_fs/librequests/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/post.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/post.dir/clean

examples/CMakeFiles/post.dir/depend:
	cd /home/pandu/pokemon_fs/librequests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pandu/pokemon_fs/librequests /home/pandu/pokemon_fs/librequests/examples /home/pandu/pokemon_fs/librequests/build /home/pandu/pokemon_fs/librequests/build/examples /home/pandu/pokemon_fs/librequests/build/examples/CMakeFiles/post.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/post.dir/depend

