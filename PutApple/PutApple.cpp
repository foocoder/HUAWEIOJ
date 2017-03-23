// ---- Program Info Start----
//FileName:     PutApple.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 11:14:12
// ---- Program Info End  ----

#include <stdio.h>

#define MAX_NUM 10

int fnPutApple( int nApple, int nBox ){
    if( nBox <= 1 || nApple <= 1 ){
        return 1;
    }
    if( nApple < nBox ){
        return fnPutApple( nApple, nApple );
    }
    else{
        return fnPutApple( nApple, nBox-1 ) + fnPutApple( nApple-nBox, nBox );
    }
}
int fnPutAppleDP( int nApple, int nBox ){
    int nDPMatix[MAX_NUM+1][MAX_NUM+1];
    for( int i=0; i<=nBox; ++i )
        for( int j=0; j<=nApple; ++j )
            nDPMatix[i][j] = 0;
    for( int i=0; i<=nBox; ++i ){
        nDPMatix[i][0] = 1;
        nDPMatix[i][1] = 1;
    }
    for( int j=0; j<=nApple; ++j ){
        nDPMatix[0][j] = 1;
        nDPMatix[1][j] = 1;
    }
    for( int i=2; i<=nBox; ++i ){
        for( int j=2; j<=nApple; ++j ){
            if( j>=i )
                nDPMatix[i][j] = nDPMatix[i-1][j] + nDPMatix[i][j-i];
            else
                nDPMatix[i][j] = nDPMatix[j][j];

        }
    }
    return nDPMatix[nBox][nApple];

}

int main(int argc, char *argv[])
{
    /* for( int i=0; i<10; ++i ){ */
    /*     for( int j=0; j<10; ++j ){ */
    /*         printf( "%d, %d : %d - %d \n", i, j, fnPutApple( i, j ), fnPutAppleDP( i, j ) ); */
    /*     } */
    /* } */
    int nApple, nBox;
    scanf( "%d", &nApple );
    scanf( "%d", &nBox );
    printf( "%d", fnPutAppleDP( nApple, nBox ) );
    return 0;
}
