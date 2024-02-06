#ifndef BALIK_STRING
#define BALIK_STRING

// Menerima argumen pointer yang merupakan sebuah string
// Mengembalikan panjang string
int panjangString(char* ch);

// Menerima argumen pointer yang merupakan sebuah string (diasumsikan tidak ada huruf kapital)
// Parameter str merupakan string yang akan dibalik
// Contoh : str adalah "slevel" maka akan terubah menjadi "levels"
void membalikString(char* str);

#endif