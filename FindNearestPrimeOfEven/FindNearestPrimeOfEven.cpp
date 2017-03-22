// ---- Program Info Start----
//FileName:     FindNearestPrimeOfEven.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-22 19:17:53
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_ARR_LEN 10000
void fnFindPrime( int nNum, bool bIsPrime[] ){
    bIsPrime[0] = false;
    bIsPrime[1] = false;

    int nSqrt = sqrt( (double) nNum );
    int nCount = 0;
    for( int i=2; i<=nSqrt; ++i ){
        if( bIsPrime[i] ){
            for( int j=2; i*j<=nNum; ++j ){
                bIsPrime[ j*i ] = false;
            }
        }
    }
    return ;

}
void fnFindPrimeNumber( int nEven, int * nPrimePairArr ){

    bool bIsPrime[ MAX_ARR_LEN ];
    memset( bIsPrime, 1, sizeof( bIsPrime ) );
    fnFindPrime( nEven, bIsPrime );

    int nMiddle = nEven / 2;
    int nLeftIndex = nMiddle, nRightIndex = nMiddle;

    while( nLeftIndex >= 2  ){
        if( bIsPrime[nLeftIndex] && bIsPrime[nRightIndex] ){
            nPrimePairArr[0] = nLeftIndex;
            nPrimePairArr[1] = nRightIndex;
            return;
        }
        nLeftIndex--;
        nRightIndex++;

    }

}

int main(int argc, char *argv[])
{
    int nEven;
    scanf( "%d", &nEven );
    int nPrimePairArr[2] = { 0, 0 };
    fnFindPrimeNumber( nEven, nPrimePairArr );
    printf( "%d\n%d\n", nPrimePairArr[0], nPrimePairArr[1] );

    /* for( int i=6; i<=10000; i+=2 ) */
    /* { */
    /*     fnFindPrimeNumber( i, nPrimePairArr ); */
    /*     printf( "%d:", i ); */
    /*     printf( "%d %d\n", nPrimePairArr[0], nPrimePairArr[1] ); */
    /* } */

    return 0;
}
