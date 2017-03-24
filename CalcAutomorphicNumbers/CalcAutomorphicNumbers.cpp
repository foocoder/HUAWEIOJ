// ---- Program Info Start----
//FileName:     CalcAutomorphicNumbers.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-24 12:31:27
// ---- Program Info End  ----

#include <stdio.h>

bool IsAutomorphicNumber( long nNum ){
    long lPower = nNum * nNum;
    while( (nNum > 0) && (lPower % 10) == (nNum % 10) ){
        lPower /= 10;
        nNum /= 10;
    }
    if( nNum == 0 ) return true;
    else return false;
}

int main(int argc, char *argv[])
{
    /* for( int i=0; i<200000; ++i ){ */
    /*     if( IsAutomorphicNumber( i ) ){ */
    /*         printf( "%d ", i ); */
    /*     } */
    /* } */
    long nNum;
    scanf( "%ld", &nNum );
    int nCount = 0;
    for( int i=0; i<=nNum; ++i ){
        if( IsAutomorphicNumber(i) ){
            nCount++;
        }
    }
    printf( "%d", nCount );
    return 0;
}
