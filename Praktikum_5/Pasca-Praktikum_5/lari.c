#include "mesinkarakter.h"
#include "lari.h"
#include <stdio.h>

int energy;
boolean punch = false, dead = false;

void IsBlock(char currentChar)
{
    if(currentChar == '#')
    {
        if(punch)
        {
            punch = !punch;
            energy--;
        }
        else {energy = -1; dead = true;}
    }
}

void IsPunch(char currentChar)
{
    if(currentChar == '@')
    {
        punch = true;
        energy--;
    }
}

void IsPokari(char currentChar)
{
    energy += (currentChar == '>');
}

void IsPath(char currentChar)
{
    energy -= (currentChar == '-');
}

void Running()
{
    scanf("%d\n", &energy); 
    START();
    do
    {
        dead = (energy > 0)? false : true;
        if(!dead)
        {
            IsBlock(currentChar);
            IsPunch(currentChar);
            IsPokari(currentChar);
            IsPath(currentChar);
        }
        ADV();
    } while (!EOP);
    if(energy < 1) dead = true;
    else energy--;
    printf("%s\nENERGY %d\n", ((dead)? "FAIL" : "FINISH"), energy);   
}