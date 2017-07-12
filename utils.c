#include <stdlib.h>

int getRandomIntBetween(int min, int max)
{
    return rand() % (max - min) + min;
}