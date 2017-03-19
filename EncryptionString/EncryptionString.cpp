// ---- Program Info Start----
//FileName:     EncryptionString.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-19 19:17:34
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>


#define MAX_STR_LEN 100

#define ISDIGIT( letter ) ( (letter >= '0') && (letter <= '9') )
#define ISCAPITAL( letter ) ( (letter>= 'A') && (letter <= 'Z') )
#define ISLOWERCASE( letter ) ( (letter>= 'a') && (letter <= 'z') )

char cCapitalArr [26];
char cLowerCaseArr [26];
char cDigitArr [10];

//
void fnInitArr(){
    char upperChar = 'A';
    char lowerChar = 'a';
    char digitChar = '0';
    for( int i=0; i<26; ++i ){
        cCapitalArr[i]   = upperChar + i;
        cLowerCaseArr[i] = lowerChar + i;
    }
    for( int i=0; i<10; ++i ){
        cDigitArr[i] = digitChar + i;
    }

}

// 字符串加密
void fnEncrypt( char aucPassword [], char aucResult[] ){
    if( aucPassword == NULL || *aucPassword == '\0' )
        return;
    if( aucResult == NULL )
        return;

    char charIndex;
    while( (charIndex = *aucPassword++) != '\0' ){
        if( ISDIGIT(charIndex) ){
            *aucResult++ = cDigitArr[ ((charIndex-'0')+1) % 10 ];
        }
        else if( ISCAPITAL(charIndex) ){
            *aucResult++ = cLowerCaseArr[ ((charIndex-'A')+1) % 26 ];
        }
        else if( ISLOWERCASE(charIndex) ){
            *aucResult++ = cCapitalArr[ ((charIndex-'a')+1) % 26 ];
        }
        else{
            *aucResult++ = charIndex;
        }
    }
    *aucResult = '\0';
}

// 字符串解密
int fnUnencrypt( char aucResult[], char aucPassword[] ){
    if( aucResult == NULL || *aucResult == '\0' )
        return -1;
    if( aucPassword == NULL )
        return -1;

    char charIndex;
    while( (charIndex = *aucResult++) != '\0' ){
        if( ISDIGIT(charIndex) ){
            *aucPassword++ = cDigitArr[ ((charIndex-'0')+9) % 10 ];
        }
        else if( ISCAPITAL(charIndex) ){
            *aucPassword++ = cLowerCaseArr[ ((charIndex-'A')+25) % 26 ];
        }
        else if( ISLOWERCASE(charIndex) ){
            *aucPassword++ = cCapitalArr[ ((charIndex-'a')+25) % 26 ];
        }
        else{
            *aucPassword++ = charIndex;
        }
    }
    *aucPassword = '\0';
    return 0;

}

int main(int argc, char *argv[])
{
    fnInitArr();
    char cPasswordArr[MAX_STR_LEN];
    char cResultArr[MAX_STR_LEN];
    memset( cPasswordArr, sizeof( cPasswordArr ), 0 );
    memset( cResultArr, sizeof( cResultArr ), 0 );
    scanf("%s", cPasswordArr);
    fnEncrypt( cPasswordArr, cResultArr );
    printf("%s\n", cResultArr);

    memset( cPasswordArr, sizeof( cPasswordArr ), 0 );
    memset( cResultArr, sizeof( cResultArr ), 0 );
    scanf("%s", cResultArr);
    fnUnencrypt( cResultArr, cPasswordArr );
    printf("%s\n", cPasswordArr);

    return 0;
}
