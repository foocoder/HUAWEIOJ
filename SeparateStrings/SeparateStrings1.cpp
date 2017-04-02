/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        SeparateStrings.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-02 11:49:07
 * @last update: 2017-04-02 12:01:20
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <cstdio>
#include <cstring>

#define MAX_STR_LEN 100
#define SEP_LEN 8

void fnProcessString( char * pString ){
    char cCurIndex;
    char * pStrIndex = pString;
    char cSubString [ SEP_LEN+1 ] = { 0 };
    int nSubIndex = 0;
    while( (cCurIndex=*pStrIndex++) != '\0' ){
        if( nSubIndex < SEP_LEN )
            cSubString[ nSubIndex++ ] = cCurIndex;
        else{
            printf( "%s\n", cSubString );
            nSubIndex = 0;
            memset( cSubString, 0, sizeof(cSubString) );
            cSubString[ nSubIndex++ ] = cCurIndex;
        }
    }
    while( nSubIndex<SEP_LEN ){
        cSubString[ nSubIndex++ ] = '0';
    }
    printf("%s\n", cSubString);
}
int main(int argc, char *argv[])
{
    char cStringArr[ MAX_STR_LEN ] = { 0 };
    int nNum;
    scanf( "%d", &nNum );
    for( int i=0; i<nNum; ++i ) {
        scanf( "%s", cStringArr );
        fnProcessString( cStringArr );
        memset( cStringArr, 0, sizeof( cStringArr ) );
    }

    return 0;
}
