// ---- Program Info Start----
//FileName:     GetCubeRoot.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-25 11:00:19
// ---- Program Info End  ----

#include <stdio.h>

#define ERR 1e-6
#define CUBEPOWER( n ) ((n) * (n) * (n))
#define POWER( n ) ((n) * (n) )

int main(int argc, char *argv[])
{
    double dInputNumber;
    scanf("%lf", &dInputNumber);

    double dCubeRoot, dCurrentVal = dInputNumber;

    while( 1 ){
        dCubeRoot = dCurrentVal - (CUBEPOWER(dCurrentVal)-dInputNumber) / ( 3*POWER(dCurrentVal));
        if( CUBEPOWER(dCubeRoot) - dInputNumber < ERR && CUBEPOWER(dCubeRoot) - dInputNumber > -ERR ){
            printf("%.1f", dCubeRoot);
            return 0;
        }
        else{
            dCurrentVal = dCubeRoot;
        }
    }

    return 0;
}
