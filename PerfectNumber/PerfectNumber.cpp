// ---- Program Info Start----
//FileName:     PerfectNumber.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-22 14:04:48
// ---- Program Info End  ----

#include <stdio.h>
#include <math.h>

int fnCalcAliquaotDivisor( int nNum ){
    if( nNum == 1 )
        return 0;
    int res = 0;
    int nBound = sqrt( (double)nNum );
    for( int i=1; i<= nBound; ++i ){
        if( nNum % i == 0 )
        {
            res += i;
            /* printf( "%d ", i ); */
            if( nNum/i != nBound && i != 1){
                res += nNum / i;
                /* printf( "%d ", nNum/i ); */
            }
        }
    }
    return res;

}
int main(int argc, char *argv[])
{
    int nCount = 0;
    int nNum;

    scanf( "%d", &nNum );

    for( int i=1; i<=nNum; ++i ){
        /* printf( "%d:%d\n", i, fnCalcAliquaotDivisor( i ) ); */
        if( i == fnCalcAliquaotDivisor(i) ){
            /* printf( "%d\t", i ); */
            nCount ++;
        }
    }
    printf( "%d", nCount );
    return 0;
}
