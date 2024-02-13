#include <stdio.h>
#include "list.h"

// Konstruktor

List MakeList() {
	List L;
	IdxType i;
	for (i = 0; i < MaxEl; i++) {
		L.A[i] = Mark;
	}
	return L;
}

boolean IsEmpty(List L) {
	return (L.A[0] == Mark);
}

int Length(List L) {
	int i = 0;
	while (L.A[i] != Mark) {
		i += 1;
	}
	return i;
}

ElType Get(List L, IdxType i) {
	return L.A[i];
}

void Set(List *L, IdxType i, ElType v) {
	(*L).A[i] = v;
}

IdxType FirstIdx(List L) {
    return 0;
}

IdxType LastIdx(List L) {
	int i = FirstIdx(L);
	while ((i < MaxEl) && (L.A[i+1] != Mark)) {
		i += 1;
	}
	return i;
}

boolean IsIdxValid (List L, IdxType i) {
	return (0 <= i) && (MaxEl >= i);
}

boolean IsIdxEff (List L, IdxType i) {
	return (FirstIdx(L) <= i) && (LastIdx(L) >= i);
}

boolean Search(List L, ElType X) {
	int i = FirstIdx(L);
	int j = LastIdx(L);
	boolean found = false;
	while ((i <= j) && !found) {
		if (L.A[i] == X) {
			found = true;
		}
		i += 1;
	}
    return found;
}

void InsertFirst(List *L, ElType X) {
	IdxType i = LastIdx(*L);
	while (i >= 0) {
		Set(L, i+1, Get(*L, i));
		i--;
	}
	Set(L, 0, X);
}

void InsertAt(List *L, ElType X, IdxType i) {
    IdxType j = LastIdx(*L);
	while (i <= j) {
		Set(L, j+1, Get(*L, j));
        j--;
	}
	Set(L, i, X);
}

void InsertLast(List *L, ElType X) {
    if (IsEmpty(*L)) {
        InsertFirst(L, X);
    } else {
        (*L).A[LastIdx(*L) + 1] = X;
    }
}

void DeleteFirst(List *L) {
	int i = FirstIdx(*L);
	while (i < LastIdx(*L)) {
		(*L).A[i] = (*L).A[i+1];
        i++;
	}
    (*L).A[i] = Mark;
}

void DeleteAt(List *L, IdxType i) {
	int j = LastIdx(*L);
	while (i <= j) {
		(*L).A[i] = (*L).A[i+1];
        i++;
	}
}

void DeleteLast(List *L) {
	(*L).A[LastIdx(*L)] = Mark;
}

List Concat(List L1, List L2) {
	List L3 = MakeList();
	int i = FirstIdx(L1);
	int j = FirstIdx(L2);
	int idx = 0;
	while (i <= LastIdx(L1)) {
		L3.A[idx] = L1.A[i];
        idx++;
        i++;
	}
	while (j <= LastIdx(L2)) {
		L3.A[idx] = L2.A[j];
        idx++;
        j++;
	}

    return L3;
}