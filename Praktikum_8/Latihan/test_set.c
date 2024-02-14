#include "set.h"
#include <stdio.h>

int main() {
    Set S;
    infotype Elmt;
    boolean result;

    // Test 1: Empty set
    CreateEmpty(&S);
    Elmt = 5;
    result = IsMember(S, Elmt);
    if (result == false) {
        printf("Test 1 passed\n");
    } else {
        printf("Test 1 failed\n");
    }

    // Test 2: Single element set
    Insert(&S, 10);
    Elmt = 10;
    result = IsMember(S, Elmt);
    if (result == true) {
        printf("Test 2 passed\n");
    } else {
        printf("Test 2 failed\n");
    }

    // Test 3: Multiple element set
    Insert(&S, 20);
    Insert(&S, 30);
    Elmt = 30;
    result = IsMember(S, Elmt);
    if (result == true) {
        printf("Test 3 passed\n");
    } else {
        printf("Test 3 failed\n");
    }

    // Test 4: Element not in set
    Elmt = 40;
    result = IsMember(S, Elmt);
    if (result == false) {
        printf("Test 4 passed\n");
    } else {
        printf("Test 4 failed\n");
    }

    return 0;
}