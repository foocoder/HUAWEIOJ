// ---- Program Info Start----
//FileName:     DeleteLeastCharactors.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-29 20:41:10
// ---- Program Info End  ----

#include <cstdio>

#define MAX_LEN 21
#define ISLOWER(letter) ( (letter)>='a' && (letter)<='z' )
int main(int argc, char *argv[])
{
    char cStringArr[MAX_LEN] = { 0 };
    int nAlphetTable[26] = { 0 };
    scanf( "%s", cStringArr );
    int nCount = 0;
    char * pStr = cStringArr;
    int nMinNum = MAX_LEN;

    bool flag = false;
    char cIndex;
    while( (cIndex = *pStr++) != '\0' ){
        if( !ISLOWER(cIndex) ){
            flag = true;
            break;
        }
        nCount++;
        ++nAlphetTable[ cIndex-'a' ];
    }

    if( nCount>20 || flag ){
        printf( "%s", cStringArr );
        return 0;
    }
    for( int i=0; i<26; ++i ){
        if( nAlphetTable[i] && nAlphetTable[i]<nMinNum )
            nMinNum = nAlphetTable[i];
    }
    for( int i=0; i<nCount; ++i ){
        if( nAlphetTable[cStringArr[i]-'a'] > nMinNum )
            printf( "%c", cStringArr[i] );
    }

    return 0;
}
