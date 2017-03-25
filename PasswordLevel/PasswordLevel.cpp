// ---- Program Info Start----
//FileName:     PasswordLevel.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-25 11:43:55
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>

#define ISUPPER(letter) ( (letter)>='A' && (letter)<='Z' )
#define ISLOWER(letter) ( (letter)>='a' && (letter)<='z' )
#define ISDIGIT(letter) ( (letter)>='0' && (letter)<='9' )
#define ISSPE01(letter) ( (letter)>=0x21 && (letter)<=0x2F)
#define ISSPE02(letter) ( (letter)>=0x3A && (letter)<=0x40)
#define ISSPE03(letter) ( (letter)>=0x5B && (letter)<=0x60)
#define ISSPE04(letter) ( (letter)>=0x7B && (letter)<=0x7E)
#define ISSPECIAL(letter) ( ISSPE01(letter) || ISSPE02(letter) || ISSPE03(letter) || ISSPE04(letter) )


int fnGetPasswordScore( char * cPasswordArr ){
    int nLen = strlen(cPasswordArr);
    int nScore = 0;
    //长度
    if( nLen <= 4 ){
        nScore += 5;
    }
    else if( nLen <=7 ){
        nScore += 10;
    }
    else{
        nScore += 25;
    }
    int nUpper=0, nLower=0, nDigit=0, nSepcial=0;
    for( int i=0; i<nLen; ++i ){
        if( ISUPPER(cPasswordArr[i]) ){
            nUpper++;
        }
        else if( ISLOWER(cPasswordArr[i]) ){
            nLower++;
        }
        else if( ISDIGIT(cPasswordArr[i])){
            nDigit++;
        }
        else if( ISSPECIAL(cPasswordArr[i]) ){
            nSepcial++;
        }
    }
    //数字
    if( nDigit == 1 ){
        nScore += 10;
    }
    else if( nDigit > 1 ){
        nScore += 20;
    }
    //符号
    if( nSepcial == 1){
        nScore += 10;
    }
    else if( nSepcial > 1) {
        nScore += 25;
    }
    //字母
    if( nUpper ==0 || nLower == 0 ){
        nScore += 10;
    }
    else if( nUpper > 0 && nLower > 0 ){
        nScore += 20;
    }
    //附加分
    if( nUpper>0 && nLower>0 && nDigit>0 && nSepcial>0 ){
        nScore += 5;
    }
    else if( (nUpper>0 || nLower>0) && nDigit>0 && nSepcial>0 ){
        nScore += 3;
    }
    else if( (nUpper>0 || nLower>0) && nDigit>0 && nSepcial==0 ){
        nScore += 2;
    }
    return nScore;

}

int main(int argc, char *argv[])
{
    char cPasswordArr[100];
    scanf( "%s", cPasswordArr );
    int nScore = fnGetPasswordScore( cPasswordArr );
    /* printf("%d", nScore); */
    if( nScore >= 90 ){
        printf("VERY_SECURE");
    }
    else if( nScore >= 80 ){
        printf( "SECURE" );
    }
    else if( nScore >= 70 ){
        printf( "VERY_STRONG" );
    }
    else if( nScore >= 60 ){
        printf( "STRONG" );
    }
    else if( nScore >= 50 ){
        printf( "AVERAGE" );
    }
    else if( nScore >= 25 ){
        printf( "WEAK" );
    }
    else{
        printf( "VERY_WEAK" );
    }
    return 0;
}
