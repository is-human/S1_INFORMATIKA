#include <stdio.h>
#include <string.h>

typedef struct Stack{
    char data[100];
    int top;
}stack;

void ubah_postfix(stack *notasi){
    stack operand, operator, operator_temp, postfix;
    operand.top = -1;
    operator.top = -1;
    operator_temp.top = -1;
    postfix.top = -1;
    for(int i = notasi->top; i >= 0; i--){
        //saring ke stack operand
        if(
            notasi->data[i] != '+' &&
            notasi->data[i] != '-' &&
            notasi->data[i] != '*' &&
            notasi->data[i] != '/' &&
            notasi->data[i] != '%'
        ){
            operand.top++;
            operand.data[operand.top] = notasi->data[i];
        }
        //saring ke stack operator
        if(
            notasi->data[i] == '(' ||
            notasi->data[i] == ')' ||
            notasi->data[i] == '+' ||
            notasi->data[i] == '-' ||
            notasi->data[i] == '*' ||
            notasi->data[i] == '/' ||
            notasi->data[i] == '%'
        ){
            operator.top++;
            operator.data[operator.top] = notasi->data[i];
        }
    }
    printf("operand: %s", operand.data);
    printf("\ntopnya: %i", operand.top);
    printf("\noperator: %s", operator.data);
    printf("\ntopnya: %i", operator.top);

    int count = operand.top;

    for(int i = count; i >= 0; i--){        
        if(operand.data[operand.top] == '('){
            operand.top--;
            if(operator.data[operator.top] != '(' && operator.data[operator.top] != ')'){
                operator_temp.top++;
                operator_temp.data[operator_temp.top] = operator.data[operator.top];
                operator.top--;
            }
            if(operator.data[operator.top] == '(') operator.top--;
        }
        else if(operand.data[operand.top] == ')'){
            operand.top--;
            if(operator.data[operator.top] != '(' && operator.data[operator.top] != ')'){
                postfix.top++;
                postfix.data[postfix.top] = operator.data[operator.top];
                operator.top--;
            }
            if(operator.data[operator.top] == ')') operator.top--;
        }
        else if(operand.data[operand.top] != '(' && operand.data[operand.top] != ')'){
            postfix.top++;
            postfix.data[postfix.top] = operand.data[operand.top];
            operand.top--;
        }
        if(i-1 < 0 && (operator_temp.top >= 0 || operator.top >= 0)){
            while(1){
                printf("\ntemp: %s", operator_temp.data);
                if(operator.top >= 0){
                    postfix.top++;
                    postfix.data[postfix.top] = operator.data[operator.top];
                    operator.top--;
                }
                if(
                    operator_temp.data[operator_temp.top] == '+' ||
                    operator_temp.data[operator_temp.top] == '-' ||
                    operator_temp.data[operator_temp.top] == '*' ||
                    operator_temp.data[operator_temp.top] == '/' ||
                    operator_temp.data[operator_temp.top] == '%'
                ){
                    postfix.top++;
                    postfix.data[postfix.top] = operator_temp.data[operator_temp.top];
                    operator_temp.top--;
                }
                if(operator.top < 0 && operator_temp.top < 0) break;
            }
        }
        //wes
    }

    printf("\npostfix: %s", postfix.data);
    printf("\ntop: %d", postfix.top);
}
int main(){
    stack notasi;
    printf("Ekspresi Infix : ");
    // fflush(stdin); gets(notasi.data);
    scanf("%s", &notasi);
    notasi.top = strlen(notasi.data) - 1;
    printf("len : %i\n", notasi.top);
    ubah_postfix(&notasi);
}