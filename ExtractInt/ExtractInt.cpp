// ---- Program Info Start----
//FileName:     ExtractInt.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 22:27:42
// ---- Program Info End  ----

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool cDigitAlphet[10] = {0};
int main(int argc, char *argv[])
{
    char cStrLine [100] = {0};
    scanf( "%s", cStrLine);
    char cInt [100] = {0};
    int nStrSize = strlen( cStrLine );
    if( cStrLine[0] == '-'){
        strncat( cInt, cStrLine+1, nStrSize-1);
        nStrSize--;
    }
    else{
        strncat( cInt, cStrLine, nStrSize);
    }
    char cNewInt [100] = { 0 };
    int nCount = 0;
    for( int i=nStrSize-1; i>=0; --i ){
        if( !cDigitAlphet[cInt[i]-'0'] ){
            cNewInt[nCount++] = cInt[i];
            cDigitAlphet[cInt[i]-'0'] = true;
        }
    }
    printf( "%ld", strtoul(cNewInt, NULL, 0) );

    return 0;
}
