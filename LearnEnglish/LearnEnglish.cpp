// ---- Program Info Start----
//FileName:     LearnEnglish.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-21 11:27:57
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>

#define MAX_ENG_LEN 1000
#define MAX_WORD_LEN 100

char cOnesAlphets[10][6] = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};
char cTeensAlphets[10][10] = {
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
};
char cTensAlphets[10][8] = {
    "",
    "ten",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};
char cHighPlace[4][9] = {
    "",
    "thousand",
    "million",
    "billion",
};
int fnParseUnsignedInt( unsigned int nNum, char cEngArr[] ){
    if( nNum > 999 )
        return -1;
    if( nNum == 0 ){
        return 1;
    }
    char cHundreds, cTens, cOnes;
    int nHundred, nTens;

    //Process Hundreds Place
    cHundreds = (nNum / 100) + '0';
    nHundred = nNum / 100;
    nNum %= 100;
    nTens = nNum;
    /* printf( "%c\t", cHundreds ); */

    //Process Tens Place
    cTens = (nNum / 10) + '0';
    nNum %= 10;
    /* printf( "%c\t", cTens ); */

    //Process Ones Place
    cOnes = nNum + '0';
    /* printf( "%c\t", cOnes ); */

    if( cHundreds != '0' ){
        strncat( cEngArr, cOnesAlphets[cHundreds-'0'], 6 );
        strncat( cEngArr, " hundred", 8 );
    }

    //Process and
    if( nHundred && nTens ){
        strncat( cEngArr, " and ", 5 );
    }

    switch( cTens ){
        case '0':
            break;
        case '1':
            strncat( cEngArr, cTeensAlphets[cOnes-'0'], 10 );
            return 0;
        default:
            strncat( cEngArr, cTensAlphets[cTens-'0'], 8 );
            break;
    }

    //Process blank
    if( (cTens-'0') && (cOnes-'0') ){
        strncat( cEngArr, " ", 1 );
    }

    if( cOnes != '0' ){
        strncat( cEngArr, cOnesAlphets[cOnes-'0'], 6 );
    }

    return 0;
}
void fnParseUnsignedLong( unsigned long ulNum, char cEngArr [] ){
    if( ulNum == 0 ){
        strncat( cEngArr, "zero", 5 );
        return;
    }
    unsigned int nNumSegment [ 4 ] = {0};
    int nIndex = 0;
    while( ulNum / 1000 ){
        nNumSegment[nIndex++] = ulNum % 1000;
        ulNum /= 1000;
    }
    nNumSegment[nIndex++] = ulNum;

    char cWordArr[MAX_WORD_LEN];
    for( int i = nIndex-1; i>=0; --i ){
        if( nNumSegment[i] == 0 ) continue;
        memset( cWordArr, 0, sizeof( cWordArr ) );
        fnParseUnsignedInt( nNumSegment[i], cWordArr );
        strncat( cEngArr, cWordArr, MAX_WORD_LEN );
        if( i != 0 ){
            strncat( cEngArr, " ", 1 );
            strncat( cEngArr, cHighPlace[i], 9 );
            strncat( cEngArr, " ", 1 );
        }
    }

}

int main(int argc, char *argv[])
{
    char cEngArr[MAX_ENG_LEN];
    unsigned long ulNum;
    memset( cEngArr, 0, sizeof( cEngArr ) );
    scanf( "%lu", &ulNum );
    fnParseUnsignedLong( ulNum, cEngArr );
    printf( "%s\n", cEngArr );
    return 0;
}
