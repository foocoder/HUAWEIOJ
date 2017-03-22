// ---- Program Info Start----
//FileName:     GCD.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-22 15:27:51
// ---- Program Info End  ----

#include <stdio.h>

int gcd( int lhs, int rhs ){
    if( lhs % rhs == 0 )
        return rhs;
    return gcd( rhs, lhs % rhs );
}

int main(int argc, char *argv[])
{
    int nNum1, nNum2;
    scanf( "%d", &nNum1 );
    scanf( "%d", &nNum2 );
    if( nNum1 > nNum2 ){
        printf( "%d", ( nNum1 * nNum2 ) / gcd( nNum1, nNum2 ) );
    }
    else{
        printf( "%d", ( nNum1 * nNum2 ) / gcd( nNum2, nNum1 ) );
    }
    return 0;
}
