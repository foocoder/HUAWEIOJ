// ---- Program Info Start----
//FileName:     StringSort.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-29 21:11:57
// ---- Program Info End  ----

#include <cstdio>
#include <cstring>
#include <cctype>

#define MAX_STR_LEN 1024
#define MAX_CHAR_LEN 100

int main(int argc, char *argv[])
{
    char cStringArr[ MAX_STR_LEN ] = { 0 };
    char cValidArr[ MAX_STR_LEN ] = { 0 };
    char cAlphetTabel [26][ MAX_CHAR_LEN ] = { 0 };
    int nAlphetCount [26] = {0};
    scanf( "%[^\n]", cStringArr );

    char * pStr = cStringArr;
    char cIndex;
    while( (cIndex = *pStr++) != '\0' ){
        if( isalpha(cIndex) ){
            int nAlphaIndex = isupper(cIndex) ? cIndex - 'A' : cIndex - 'a';
            cAlphetTabel[nAlphaIndex][nAlphetCount[nAlphaIndex]++] = cIndex;
        }
    }

    for( int i=0; i<26; ++i ){
        strncat( cValidArr, cAlphetTabel[i], MAX_CHAR_LEN );
    }
    pStr = cStringArr;
    int nValidIndex = 0;
    while( (cIndex = *pStr++) != '\0' ){
        if( isalpha(cIndex) ){
            printf("%c", cValidArr[nValidIndex++]);
        }
        else{
            printf( "%c", cIndex );
        }
    }



    return 0;
}
