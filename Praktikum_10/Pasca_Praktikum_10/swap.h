#ifndef swap_H
#define swap_H
#include "listdp.h"
#include <stdio.h>

address AddressAtIndex(List L, infotype x);
/* 
Mencari address suatu node pada element ke- X
*/
void Swap(List *L1);
/*
Kondisi awal: L1 sudah terisi dengan beberapa node.
Lakukan swap node pada node yang ada di tengah dari suatu List
*/
#endif