#include "aritmatika.h"
#include <assert.h>

void testTambah() {
    assert(Tambah(2, 3) == 5);
    assert(Tambah(-2, 3) == 1);
    assert(Tambah(0, 0) == 0);
}

void testKurang() {
    assert(Kurang(2, 3) == -1);
    assert(Kurang(-2, 3) == -5);
    assert(Kurang(0, 0) == 0);
}

void testKali() {
    assert(Kali(2, 3) == 6);
    assert(Kali(-2, 3) == -6);
    assert(Kali(0, 0) == 0);
}

void testBagi() {
    assert(Bagi(6, 3) == 2);
    assert(Bagi(-6, 3) == -2);
    assert(Bagi(0, 3) == 0);
}

int main() {
    testTambah();
    testKurang();
    testKali();
    testBagi();
    printf("All tests passed!\n");
    return 0;
}