#include "oddevenlist.h"
#include <assert.h>
#include <stdio.h>

int main() {
    List L, Odd, Even;
    CreateEmpty(&L);
    CreateEmpty(&Odd);
    CreateEmpty(&Even);

    // Test case 1: L is empty
    OddEvenList(L, &Odd, &Even);
    assert(IsEmpty(Odd));
    assert(IsEmpty(Even));

    // Test case 2: L has only odd numbers
    InsVLast(&L, 1);
    InsVLast(&L, 3);
    InsVLast(&L, 5);
    OddEvenList(L, &Odd, &Even);
    assert(IsEmpty(Even));
    assert(!IsEmpty(Odd));
    assert(First(Odd) != Nil);
    assert(Info(First(Odd)) == 1);
    assert(Info(Next(First(Odd))) == 3);
    assert(Info(Next(Next(First(Odd)))) == 5);
    PrintInfo(Even);
    PrintInfo(Odd);

    // Test case 3: L has only even numbers
    CreateEmpty(&L);
    CreateEmpty(&Odd);
    CreateEmpty(&Even);
    InsVLast(&L, 0);
    InsVLast(&L, 2);
    InsVLast(&L, 4);
    OddEvenList(L, &Odd, &Even);
    assert(IsEmpty(Odd));
    assert(!IsEmpty(Even));
    assert(First(Even) != Nil);
    assert(Info(First(Even)) == 0);
    assert(Info(Next(First(Even))) == 2);
    assert(Info(Next(Next(First(Even)))) == 4);
    PrintInfo(Even);
    PrintInfo(Odd);

    // Test case 4: L has both odd and even numbers
    CreateEmpty(&L);
    CreateEmpty(&Odd);
    CreateEmpty(&Even);
    InsVLast(&L, 0);
    InsVLast(&L, 3);
    InsVLast(&L, 1);
    InsVLast(&L, 4);
    InsVLast(&L, 5);
    OddEvenList(L, &Odd, &Even);
    assert(!IsEmpty(Odd));
    assert(!IsEmpty(Even));
    assert(First(Odd) != Nil);
    assert(First(Even) != Nil);
    assert(Info(First(Odd)) == 1);
    assert(Info(Next(First(Odd))) == 3);
    assert(Info(Next(Next(First(Odd)))) == 5);
    assert(Info(First(Even)) == 0);
    assert(Info(Next(First(Even))) == 4);
    PrintInfo(Even);
    PrintInfo(Odd);
    return 0;
}