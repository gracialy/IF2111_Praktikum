#include "warehouse.h"

void manageWareHouse(Map *wareHouse){
    int menu;
    scanf("%d", &menu);

    while (menu != 4){
        if (menu == 1){
            for (int i=1; i<=(*wareHouse).Count; i++){
                printf("Bahan %d: %d\n", i, Value((*wareHouse), i));
            }
        }
        else if (menu == 2){
            int n; scanf ("%d", &n);
            while (n != 0){
                int modn = n%10;
                n = n/10;

                // if for substract
                if (Value((*wareHouse), modn) != 0){
                    // int i=0;
                    // while (wareHouse->Elements[i].Key != modn){
                    //     i++;
                    // }
                    // wareHouse->Elements[i].Value --;
                    wareHouse->Elements[modn-1].Value --;
                }
                else{
                    printf("Stok bahan %d sudah habis\n", (*wareHouse).Elements[modn-1]);
                }
            }
        }
        else if (menu == 3){
            int n; scanf ("%d", &n);
            while (n != 0){
                int modn = n%10;
                n = n/10;

                // if for substract
                wareHouse->Elements[modn-1].Value ++;
            }
        }
        scanf("%d", &menu);
    }
}
/*
I.S. variable wareHouse sudah terisi dengan bahan-bahan

Buatlah program yang melakukan pengelolaan terhadap gudang bahan makanan. Program akan menerima input sebuah integer antara angka 1 hingga 4. Program akan berhenti apabila input yang diterima bernilai 4.

Untuk keterangan input dan bagaimana proses pengelolaan, dapat dilihat dalam soal
*/

