// ---- Program Info Start----
//FileName:     FindFirstSingleChar.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-22 14:51:24
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1000

int main(int argc, char *argv[])
{
    char cStrArr[ MAX_STR_LEN ];
    int nAlphet[256] = {0};
    memset( cStrArr, 0, sizeof( cStrArr ) );
    scanf( "%s", cStrArr );

    char * pIndex = cStrArr;
    char cChar;
    while( ( cChar = *pIndex++ ) != '\0' ){
        nAlphet[ cChar ] ++;
    }
    pIndex = cStrArr;
    while( ( cChar = *pIndex++ ) != '\0' ){
        if (nAlphet[ cChar ] == 1){
            printf( "%c", cChar );
            return 0;
        }
    }
    printf( "." );

    return 0;
}
