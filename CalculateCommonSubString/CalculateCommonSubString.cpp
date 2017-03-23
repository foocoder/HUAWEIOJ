// ---- Program Info Start----
//FileName:     CalculateCommonSubString.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 16:01:44
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>

#define ISUPPER(letter) ( (letter)>='A' && (letter)<='Z' )
#define MAX_STR_LEN 100

int g_nNextArr[ 100 ] = { -2 };
void fnLowerString( char * pString ){
    int nIndex = 0;
    while( pString[nIndex] != '\0' ){
        if( ISUPPER(pString[nIndex]) ){
            pString[nIndex] += 'a' - 'A';
        }
        nIndex++;
    }
}

void fnGetNextArray( char * pPattern, int nPatternLength ){
    if( nPatternLength == 1 ){
        g_nNextArr[0] = -1;
        return;
    }
    g_nNextArr[0] = -1;
    g_nNextArr[1] = 0;
    int nPos = 2;
    int nCount = 0;
    while( nPos < nPatternLength ){
        if( pPattern[nPos-1] == pPattern[nCount] ){
            g_nNextArr[nPos++] = ++nCount;
        }
        else if( nCount>0 ){
            nCount = g_nNextArr[nCount];
        }
        else{
            g_nNextArr[nPos++] = 0;
        }
    }
}

bool fnKMP( char * pString, char * pPattern ){
    int nStringLength = strlen( pString );
    int nPatternLength = strlen( pPattern );

    int nStringIndex = 0, nPatternIndex = 0;

    fnGetNextArray( pPattern, nPatternLength );

    while( nStringIndex < nStringLength && nPatternIndex < nPatternLength ){
        if( pString[ nStringIndex ] == pPattern[ nPatternIndex ] ){
            nStringIndex++;
            nPatternIndex++;
        }
        else if( g_nNextArr[ nPatternIndex ] == -1 ){
            nStringIndex++;
        }
        else{
            nPatternIndex = g_nNextArr[nPatternIndex];
        }
    }
    return nPatternIndex == nPatternLength;

}

//暴力求解
int fnGetCommonStringLength( char * pLHS, char * pRHS, int nRHSLen ){
    char cStrPattern [MAX_STR_LEN];
    for( int i=nRHSLen-1; i>=0; --i ){
        for( int j=0; j<nRHSLen-i; j++ ){
            memset( cStrPattern, 0, sizeof( cStrPattern ) );
            strncat( cStrPattern, pRHS+j, i+1 );
            if( fnKMP( pLHS, cStrPattern ) )
                return i+1;
        }

    }

    return 0;
}

int main(int argc, char *argv[])
{
    char cStringArr1 [ MAX_STR_LEN ] = { 0 };
    char cStringArr2 [ MAX_STR_LEN ] = { 0 };
    scanf( "%s", cStringArr1 );
    scanf( "%s", cStringArr2 );

    fnLowerString( cStringArr1 );
    fnLowerString( cStringArr2 );

    int nStringLength1 = strlen( cStringArr1 );
    int nStringLength2 = strlen( cStringArr2 );

    if( nStringLength1 > nStringLength2 )
        printf( "%d", fnGetCommonStringLength( cStringArr1, cStringArr2, nStringLength2 ) );
    else
        printf( "%d", fnGetCommonStringLength( cStringArr2, cStringArr1, nStringLength1 ) );

    return 0;
}
