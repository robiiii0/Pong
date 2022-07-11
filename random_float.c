#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float random_float()
{
    int x;
    float fr;

    srand((unsigned)time(NULL));
    for(x=0;x<10;x++)
    {
        fr = (float)rand()/RAND_MAX;
    }
    return(fr);
}