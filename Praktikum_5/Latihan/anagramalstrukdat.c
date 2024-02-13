#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"
#include <stdio.h>

/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string){
    int len = 0;
    while (string[len]!='\0'){
        len ++;
    }
    return len;
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command){
    Word retval;
    retval.Length = stringLength(command);
    for (int i=0; i<stringLength(command); i++){
        retval.TabWord[i] = command[i];        
    }
    return retval;
}

/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2){
    boolean found;
    if (string1.Length == string2.Length){
        int len = string1.Length;
        int freq1[26]={0};
        int freq2[26]={0};

        for (int i=0; i<len; i++){
            freq1[string1.TabWord[i]-'a'] ++;
        }
        
        for (int i=0; i<len; i++){
            freq2[string2.TabWord[i]-'a'] ++;
        }

        boolean found = true;
        for (int i=0; i<26; i++){
            if(freq1[i]!=freq2[i]){
                found = false;
            }
        }
        return found;
    }
    return false;
}

/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek){
    Word alstrukdat = toKata("alstrukdat");
    int NbAnagram = 0;
    STARTWORD();
    while (! EndWord){
        if (isAnagram(alstrukdat, currentWord)){
            NbAnagram ++;
        }
        ADVWORD();
    }
    *frek = NbAnagram;
}

int main(){
    int frek;
    anagramalstrukdat(&frek);
    printf("%d\n", frek);
    return 0;
}