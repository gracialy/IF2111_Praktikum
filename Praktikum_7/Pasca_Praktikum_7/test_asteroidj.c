#include <stdio.h>
#include "asteroid.h"

void testCollision()
{
    infotype asteroids1[] = {3, -5, 2, -4, 1};
    Stack remaining1; CreateEmpty(&remaining1);
    collision(5, asteroids1, &remaining1);
    displayAsteroids(remaining1); // expected output: [3,-5,1]

    infotype asteroids2[] = {2, 6, -2, -7, -4, 5};
    Stack remaining2; CreateEmpty(&remaining2);
    collision(5, asteroids2, &remaining2);
    displayAsteroids(remaining2); // expected output: [1,-2,3,-4,5]

    infotype asteroids3[] = {1, -1, 2, -2, 3, -3};
    Stack remaining3; CreateEmpty(&remaining3);
    collision(6, asteroids3, &remaining3);
    displayAsteroids(remaining3); // expected output: [1,-1,2,-2,3,-3]
}

int main()
{
    testCollision();
    return 0;
}