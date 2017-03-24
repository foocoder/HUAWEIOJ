// ---- Program Info Start----
//FileName:     CountNegtiveAveragePositive.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-24 12:50:53
// ---- Program Info End  ----

#include <stdio.h>


int main(int argc, char *argv[])
{
    int nNum;
    /* scanf( "%d", &nNum ); */
    int nInput;
    int nSum = 0;
    int nNegCount = 0, nPosCount = 0;
    while( ~(scanf( "%d", &nInput )) ){
        if( nInput >= 0 ){
            nSum += nInput;
            nPosCount++;
        }
        else if( nInput < 0 ){
            nNegCount++;
        }
    }

    if( nPosCount == 0 )
        printf( "%d\n0.0", nNegCount );
    else
        printf( "%d\n%.1f", nNegCount, (float)nSum / (float) nPosCount );
    /* for( int i=0; i<nNum; ++i ){ */
    /*     scanf( "%d", &nInput ); */
    /*     if( nInput > 0 ){ */
    /*         nSum += nInput; */
    /*         nPosCount++; */
    /*     } */
    /*     else if( nInput < 0 ){ */
    /*         nNegCount++; */
    /*     } */
    /* } */
    /* if( nSum % nPosCount == 0 ){ */
    /*     printf( "%d %d", nNegCount, (nSum/nPosCount) ); */
    /* } */
    /* else{ */
    /*     printf( "%d %.1f", nNegCount, (float)nSum / (float) nPosCount ); */
    /* } */
    return 0;
}
