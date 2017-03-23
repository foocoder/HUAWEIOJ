// ---- Program Info Start----
//FileName:     DNA.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 12:20:05
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>

#define MAX_SEQ_LEN 100

#define ISCG( letter ) ( (letter=='C') || (letter=='G') )

int fnCalcRatio( int nSubStringLen, char cSubString[] ){
    int nCount = 0;
    for( int i=0; i<nSubStringLen; ++i ){
        if( cSubString[i] == '\0' ) return -1;
        if( ISCG(cSubString[i]) )
            nCount++;
    }
    return nCount;
}

char * fnFindMaxRatio( int nSubStringLen, char cDNASeqArr[] ){
    int nMaxCount = -100;
    char * pSubStringHead = cDNASeqArr;
    int nIndex = 0;
    int nCount = 0;
    while( (nCount = fnCalcRatio(nSubStringLen, cDNASeqArr+nIndex)) > 0 ){
        if( nCount > nMaxCount ){
            nMaxCount = nCount;
            pSubStringHead = cDNASeqArr + nIndex;
        }
        nIndex ++;
    }
    return pSubStringHead;

}

//快速O(n)方法
int fnFastFindMax( int nSubStringLen, char cDNASeqArr[], int nStrLen ){
    int nIndex = 0;
    int nCount = 0;
    int nMaxIndex = 0;
    int nMaxCount = 0;
    for( ; nIndex<nSubStringLen; ++nIndex ){
        if( ISCG(cDNASeqArr[nIndex]) ){
            nCount ++;
        }
    }
    nMaxCount = nCount;
    nMaxIndex = 0;
    for( ; nIndex<nStrLen; ++nIndex ){
        if( ISCG( cDNASeqArr[nIndex] ) ){
            nCount++;
        }
        if( ISCG( cDNASeqArr[nIndex-nSubStringLen] ) ){
            nCount--;
        }
        if( nCount > nMaxCount ){
            nMaxCount = nCount;
            nMaxIndex = nIndex-nSubStringLen;
        }
    }
    return nMaxIndex+1;
}

//前提:nSubStringLen <= nStringLen
int main(int argc, char *argv[])
{
    int nSubStringLen;
    char cDNASeqArr[MAX_SEQ_LEN] = { 0 };
    scanf( "%s", cDNASeqArr );
    scanf( "%d", &nSubStringLen );

    int nStrLen = strlen( cDNASeqArr );
    if( nSubStringLen > nStrLen ) return 0;

    /* char * pSubStringHead = fnFindMaxRatio( nSubStringLen, cDNASeqArr ) ; */
    int nIndex = fnFastFindMax( nSubStringLen, cDNASeqArr, nStrLen );

    for( int i=nIndex; i<nIndex+nSubStringLen; ++i ){
        printf( "%c", cDNASeqArr[i] );
    }

    return 0;
}
