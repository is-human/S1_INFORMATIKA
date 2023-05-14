int count = operand.top;

    // for(int i = count; i >= 0; i--){
    //     if(operand.data[i] == '('){
    //         operand.top--;
    //         continue;
    //     }else if(operand.data[i] == ')'){
    //         postfix.top++;
    //         postfix.data[postfix.top] = operator.data[operator.top];
    //         operator.top--;
    //         operand.top--;
    //     }else if(
    //         operand.data[i] != '+' &&
    //         operand.data[i] != '-' &&
    //         operand.data[i] != '*' &&
    //         operand.data[i] != '/' &&
    //         operand.data[i] != '%'
    //     ){
    //         postfix.top++;
    //         postfix.data[postfix.top] = operand.data[operand.top];
    //         operand.top--;
    //     }
    //     if(i-1 < 0 && operator.top >= 0){
    //         for(int j = operator.top; j >= 0; j--){
    //             postfix.top++;
    //             postfix.data[postfix.top] = operator.data[operator.top];
    //             operator.top--;
    //         }
    //     }
    // }

    // printf("\npostfix: %s", postfix.data);
    // printf("\ntop: %d", postfix.top);
