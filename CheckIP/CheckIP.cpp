// ---- Program Info Start----
//FileName:     CheckIP.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 21:02:33
// ---- Program Info End  ----

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ISDIGIT(letter) ( (letter)>='0' && (letter)<='9' )
#define ISSEPARATE(letter) ( (letter) == '.' )
#define ISVALID(letter) ( ISDIGIT(letter) || ISSEPARATE(letter) )

int main(int argc, char *argv[])
{
    char strLine[100];
    scanf( "%s", strLine );
    int nStrLen = strlen( strLine );
    int nSeparateArr[3] = { -1 };
    int nSepCount = 0;

    if( nStrLen > 15 || nStrLen < 7 ){
        printf( "NO" );
        return 0;
    }
    for( int i=0; i<nStrLen; ++i ){
        if( !ISVALID(strLine[i]) ){
            printf( "NO" );
            return 0;
        }
        if( ISSEPARATE(strLine[i]) ){
            nSeparateArr[nSepCount++] = i;
        }
    }

    if( nSepCount != 3 ){
        printf( "NO" );
        return 0;
    }

    char cStrNum0[15] = { 0 };
    char cStrNum1[15] = { 0 };
    char cStrNum2[15] = { 0 };
    char cStrNum3[15] = { 0 };

    strncat( cStrNum0, strLine, nSeparateArr[0] );
    strncat( cStrNum1, strLine+nSeparateArr[0]+1, nSeparateArr[1]-nSeparateArr[0]-1 );
    strncat( cStrNum2, strLine+nSeparateArr[1]+1, nSeparateArr[2]-nSeparateArr[1]-1 );
    strncat( cStrNum3, strLine+nSeparateArr[2]+1, nStrLen-nSeparateArr[2] );

    if(strlen( cStrNum0 ) == 0){
        printf("NO");
        return 0;
    }
    if(strlen( cStrNum1 ) == 0){
        printf("NO");
        return 0;
    }
    if(strlen( cStrNum2 ) == 0){
        printf("NO");
        return 0;
    }
    if(strlen( cStrNum3 ) == 0){
        printf("NO");
        return 0;
    }
    unsigned long ulNum0 = strtoul(cStrNum0, NULL, 0);
    unsigned long ulNum1 = strtoul(cStrNum1, NULL, 0);
    unsigned long ulNum2 = strtoul(cStrNum2, NULL, 0);
    unsigned long ulNum3 = strtoul(cStrNum3, NULL, 0);
    if( ulNum0>255 ){
        printf( "NO" );
        return 0;
    }
    if( ulNum1>255 ){
        printf( "NO" );
        return 0;
    }
    if( ulNum2>255 ){
        printf( "NO" );
        return 0;
    }
    if( ulNum3>255 ){
        printf( "NO" );
        return 0;
    }

    printf( "YES" );
    /* printf( "%s\n", cStrNum0); */
    /* printf( "%s\n", cStrNum1); */
    /* printf( "%s\n", cStrNum2); */
    /* printf( "%s\n", cStrNum3); */

    return 0;
}
