// ---- Program Info Start----
//FileName:     FindPrimeFactor.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-24 11:59:04
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_ARR_LEN 1000000

int g_lPrimeNumber[ 10000 ] = { 0 };

void fnFindPrime( long nNum, bool bIsPrime [] ){

    /* bool bIsPrime [ MAX_ARR_LEN ] = { 0 }; */

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
    for( long i=2; i<nNum; ++i ){
        if( bIsPrime[i] ){
            g_lPrimeNumber[nCount++] = i;
        }
    }
    return ;
}

int fnFindPrimeFactor( long nNum, long nPrimeFactorArr[] ){
    bool bIsPrime [ MAX_ARR_LEN ];
    memset( bIsPrime, 1, sizeof( bIsPrime ) );
    fnFindPrime( nNum, bIsPrime );

    int nFactorCount = 0;
    int nPrimeCount = 0;
    while( !bIsPrime[nNum] ){
        long nPrime = g_lPrimeNumber[nPrimeCount];
        if( nNum % nPrime == 0 ){
            nPrimeFactorArr[nFactorCount++] = nPrime;
            nNum /= nPrime;
        }
        else{
            nPrimeCount++;
        }
    }
    nPrimeFactorArr[ nFactorCount++ ] = nNum;
    return nFactorCount;
}

int main(int argc, char *argv[])
{
    long nNum;
    scanf( "%ld", &nNum );
    long nPrimeFactorArr[ 1000 ] = { 0 };
    int nCount = fnFindPrimeFactor( nNum, nPrimeFactorArr );
    for( int i=0; i<nCount; ++i ) {
        if( i!=nCount-1 )
            printf( "%ld ", nPrimeFactorArr[i] );
        else
            printf( "%ld", nPrimeFactorArr[i] );
    }
    return 0;
}
