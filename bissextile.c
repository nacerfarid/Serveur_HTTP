#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int bissextile (int annee)
{
     if (((annee % 4) == 0 && (annee % 100) != 0) || (annee % 400 ) == 0)
     {
           return  1 ;
     } else {
           return 0 ;
     }
}

