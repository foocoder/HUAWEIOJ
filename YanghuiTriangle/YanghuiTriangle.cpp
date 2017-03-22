// ---- Program Info Start----
//FileName:     YanghuiTriangle.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-21 20:16:54
// ---- Program Info End  ----

#include <stdio.h>

unsigned long fnGetTriangle( unsigned long ulLineNo, unsigned long ulLinePos ){
    if( ulLineNo == 0 ){
        if( ulLinePos == 0 ){
            return 1;
        }
        else{
            return 0;
        }
    }
    if( ulLinePos >= (2*ulLineNo+1) ){
        return 0;
    }
    else{
        ulLinePos--;
        return fnGetTriangle( ulLineNo-1, ulLinePos-1 )
             + fnGetTriangle( ulLineNo-1, ulLinePos )
             + fnGetTriangle( ulLineNo-1, ulLinePos+1 );
    }
}
int main(int argc, char *argv[])
{
    int nNum;
    scanf( "%d", &nNum );
    /* for( int i=0; i<nNum; ++i ){ */
    /*     for( int j=0; j<2*i+1; ++j ){ */
    /*         printf( "%6d ", fnGetTriangle( i, j ) ); */
    /*     } */
    /*     printf("\n"); */
    /* } */
    if( nNum == 1 || nNum == 2 ){
        printf( "-1" );
        return 0;
    }
    for( int i=0; i<2*(nNum-1)+1; ++i ){
        unsigned long ulNumber = fnGetTriangle( (nNum-1), i );
        if( !(ulNumber & 1) ){
            printf( "%d", i+1 );
            break;
        }
    }
    return 0;
}
