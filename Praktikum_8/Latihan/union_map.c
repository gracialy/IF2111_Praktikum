#include "union_map.h" 

Map UnionMap(Map m1, Map m2, boolean key_based ){
    Map m3; 
    CreateEmpty(&m3);

    for (int i=0; i<m1.Count; i++){
        Insert(&m3, m1.Elements[i].Key, m1.Elements[i].Value);
    }

    int i=0;
    while (i<m2.Count && !IsFull(m3)){
        Insert(&m3, m2.Elements[i].Key, m2.Elements[i].Value);
        i++;
    }
    
    // sorting
    if (key_based){
        for (int i=0; i<m3.Count-1; i++){
            boolean swapped = false;
            for (int j=0; j<m3.Count-i-1; j++){
                if (m3.Elements[j].Key>m3.Elements[i].Key){
                    swapped = true;
                    keytype keytemp = m3.Elements[i].Key;
                    valuetype valtemp = m3.Elements[i].Value;
                    m3.Elements[i].Key = m3.Elements[j].Key;
                    m3.Elements[i].Value = m3.Elements[j].Value;
                    m3.Elements[j].Key = keytemp;
                    m3.Elements[j].Value = valtemp;
                }
            }    
            if (!swapped){
                break;
            }
        }
    }
    else{
        for (int i=0; i<m3.Count-1; i++){
            boolean swapped = false;
            for (int j=0; j<m3.Count-i-1; j++){
                if (m3.Elements[j].Value>m3.Elements[i].Value){
                    swapped = true;
                    keytype keytemp = m3.Elements[i].Key;
                    valuetype valtemp = m3.Elements[i].Value;
                    m3.Elements[i].Key = m3.Elements[j].Key;
                    m3.Elements[i].Value = m3.Elements[j].Value;
                    m3.Elements[j].Key = keytemp;
                    m3.Elements[j].Value = valtemp;
                }
            }    
            if (!swapped){
                break;
            }
        }
    }
    return m3;
}

    /* Menggabungkan m1 dengan m2 pada sebuah map baru dengan urutan yang ditentukan berdasarkan key_based
    apabila key_based true maka elemen dalam map baru ditambahkan mengurut membesar berdasarkan keynya
    apabila key_based false maka elemen dalam map baru ditambahkan mengurut membesar berdasarkan valuenya*/

    /*I.S : Map m1 dan m2 terdefinisi. m1 dan m2 TIDAK kosong dan TIDAK penuh
    F.S : Map m3 yang merupakan gabungan isi dari m1 dan m2 yang diisi berdasarkan nilai key_based. Jumlah elemen m3 TIDAK mungkin melebihi MaxEl*/

    /*Notes: 
        1. Apabila terdapat nilai key yg sama pada m1 dan m2, value yang akan ditambah pada map baru adalah value dari m1 pada key tersebut
        2. Ingat yang unik adalah key, bukan value
    Hint: Lakukan penambahan semua elemen dari m1 dan m2 ke m3 terlebih dahulu kemudian urutkan isinya menggunakan algoritma sorting*/
    
    /*
    Contoh:
        1.Input(format <key,value>):
            m1: {<7,1>,<1,2>,<20,3>}
            m2: {<8,100>,<11,10>}
            key_based: true
          Output:
            m3: {<1,2>,<7,1>,<8,100>,<11,10>,<20,3>}
        2.Input(format <key,value>):
            m1: {<7,1>,<1,2>,<20,3>}
            m2: {<8,100>,<11,10>}
            key_based: false
          Output:
            m3: {<7,1>,<1,2>,<20,3>,<11,10>,<8,100>}
    */