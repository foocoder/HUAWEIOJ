// ---- Program Info Start----
//FileName:     FindLongestDigitString.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-25 08:42:21
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>

#define ISDIGIT(letter) ( (letter)>='0' && (letter)<='9' )
int main(int argc, char *argv[])
{
    char cStringArr[100] = { 0 };
    scanf( "%[^\n]", cStringArr);
    /* fgets(cStringArr, sizeof(cStringArr), stdin); */

    char * pStr = cStringArr;
    int nMaxCount = 0;
    int nCount = 0;
    int nArr = 0;
    /* char * pMaxStr = NULL; */
    char * pMaxStrArr [ 5 ] = { NULL };
    //For Linux
    /* if( *pStr == '\n' ){ */
    /*     printf("%s", pStr+1); */
    /*     return 0; */
    /* } */
    //For Windows
    /* if( strlen(cStringArr) == 2 ){ */
    /*     printf("%s", pStr+1); */
    /*     return 0; */
    /* } */
    while( *pStr != '\0' ){
        if( ISDIGIT(*pStr) ){
            nCount++;
        }
        else{
            if( nCount > nMaxCount ){
                nMaxCount = nCount;
                nArr = 0;
                pMaxStrArr[nArr++] = pStr-nCount;
            }
            else if( nCount == nMaxCount ){
                pMaxStrArr[nArr++] = pStr - nCount;
            }
            nCount=0;
        }
        pStr++;
    }
    if( pStr == cStringArr ){
        printf("%s", pStr+1);
        return 0;
    }
    if( nMaxCount == 0 ){
        printf("0");
    }
    else{
        for( int i=0; i<nArr; ++i) {
            for( int j=0; j<nMaxCount; ++j ){
                printf( "%c", pMaxStrArr[i][j] );
            }
            printf(",");
        }
        printf("%d", nMaxCount);
    }

    return 0;
}
