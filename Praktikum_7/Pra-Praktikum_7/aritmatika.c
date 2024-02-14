#include "aritmatika.h"

boolean isOperator(char input){
    if (input=='+' || input=='-' || input=='*' || input=='/'){
        return true;
    }
    else{
        return false;
    }
}
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/

int hitung(int angka1, int angka2, char op){
    if (op=='+'){
        return angka1+angka2;
    }
    else if (op=='-'){
        return angka1-angka2;
    }
    else if (op=='*'){
        return angka1*angka2;
    }
    else if (op=='/'){
        return angka1/angka2;
    }
}
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/

int eval(char *input, int length){
    int firstToken, op1, op2;
    Stack arit;
    CreateEmpty(&arit);

    for (int i=0; i<length; i++){
        if (!isOperator(input[i])){
            Push(&arit, input[i]-'0');
        }
        else{
            Pop(&arit, &op2);
            Pop(&arit, &op1);
            Push(&arit, hitung(op1, op2, input[i]));
        }
    }
    Pop(&arit, &firstToken);
    return firstToken;
}
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/