/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        MergeString.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-03 20:07:08
 * @last update: 2017-04-03 20:48:56
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <cstdio>
#include <cctype>
#include <cstdlib>

#define MAX_STR_LEN 100

char cDigitMirrors[16] = {
    '0','8','4','C','2','A','6','E','1','9','5','D','3','B','7','F'
};
int main(int argc, char *argv[])
{
    char cStrArr0[MAX_STR_LEN] = { 0 };
    char cStrArr1[MAX_STR_LEN] = { 0 };
    int nEvenTable[128] = { 0 }, nOddTable[128] = { 0 };
    scanf( "%s", cStrArr0 );
    scanf( "%s", cStrArr1 );
    int nCount = 0;
    char * pStr = cStrArr0;
    while( *pStr != '\0' ){
        nCount++;
        if( nCount & 1 ){
            nOddTable[*pStr] ++;
        }
        else{
            nEvenTable[*pStr] ++;
        }
        pStr++;
    }
    pStr = cStrArr1;
    while( *pStr != '\0' ){
        nCount++;
        if( nCount & 1 ){
            nOddTable[*pStr] ++;
        }
        else{
            nEvenTable[*pStr] ++;
        }
        pStr++;
    }
    char nEvenCount = 0, nOddCount = 0;
    for( int i=0; i<nCount; ++i ){
        if( i & 1 ){//Process Even
            while( nEvenTable[nEvenCount++] == 0 );
            nEvenCount--;
            nEvenTable[nEvenCount]--;
            if( isxdigit(nEvenCount) ){
                char cHexStr[2] = { nEvenCount, 0 };
                printf( "%c", cDigitMirrors[ strtoul(cHexStr, NULL, 16) ] );
            }
            else{//No hexdigit, Print out.
                printf( "%c", nEvenCount );
            }
        }
        else{//Process Odd
            while( nOddTable[nOddCount++] == 0 );
            nOddCount--;
            nOddTable[nOddCount]--;
            if( isxdigit(nOddCount) ){
                char cHexStr[2] = { nOddCount, 0 };
                printf( "%c", cDigitMirrors[ strtoul(cHexStr, NULL, 16) ] );
            }
            else{//No hexdigit, Print out.
                printf( "%c", nOddCount );
            }
        }
    }

    return 0;
}
