// ---- Program Info Start----
//FileName:     CheckNetSegment.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-20 20:10:37
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fnGetToken( char * cArr, unsigned long * nULArr ){
    char * word;
    word = strtok( cArr, "." );
    int nIndex = 0;
    while( word != NULL ){
        nULArr[nIndex ++] = strtoul( word, NULL, 0 );
        /* printf( "%d ", nULArr[nIndex-1] ); */
        word = strtok( NULL, "." );
    }
}
int fnCheckNetSegment( unsigned long nMaskArr[], unsigned long nIP1Arr[], unsigned long nIP2Arr[] ){
    for( int i=0; i<4; ++i ){
        if( nMaskArr[i] > 255 || nIP1Arr[i] > 255 || nIP2Arr[i] > 255 )
            return 1;
    }
    for( int i=0; i<4; ++i ){
        if( (nMaskArr[i] & nIP1Arr[i]) != (nMaskArr[i] & nIP2Arr[i]) )
            return 2;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char cMaskArr [20];
    char cIP1Arr [20];
    char cIP2Arr [20];
    scanf( "%s", cMaskArr );
    scanf( "%s", cIP1Arr );
    scanf( "%s", cIP2Arr );
    unsigned long nMaskArr[4], nIP1Arr[4], nIP2Arr[4];
    fnGetToken( cMaskArr, nMaskArr );
    fnGetToken( cIP1Arr, nIP1Arr );
    fnGetToken( cIP2Arr, nIP2Arr );
    printf( "%d\n", fnCheckNetSegment( nMaskArr, nIP1Arr, nIP2Arr ) );

    return 0;
}
