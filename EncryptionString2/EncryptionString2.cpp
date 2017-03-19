// ---- Program Info Start----
//FileName:     EncryptionString2.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-19 20:35:55
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100

#define ISCAPITAL( letter ) ( (letter >= 'A') && (letter <= 'Z') )
#define ISLOWERCASE( letter ) ( (letter >= 'a') && (letter <= 'z') )

int alphet[26] = {0};
char capitalTable[26];
char lowercaseTable[26];

void fnEncrypt( char * key, char * data, char * encrypt ){
    if( key == NULL || data == NULL || encrypt == NULL )
        return;
    if( *key == '\0' || *data == '\0' )
        return;
    char charIndex;
    int index = 0;
    memset( capitalTable, sizeof( capitalTable ), 0 );
    memset( alphet, sizeof( alphet ), 0 );

    while( (charIndex = *key++) != '\0' ){
        // To Upper Case
        if( ISLOWERCASE(charIndex) ){
            charIndex -= 'a' - 'A';
        }
        if( alphet[ charIndex-'A' ] == 0 ){
            capitalTable[ index++ ] = charIndex;
            alphet[ charIndex-'A' ] = 1;
        }
    }
    for( int i=0; i<26; ++i ){
        if( alphet[i] == 0 ){
            capitalTable[index++] = 'A'+i;
        }
    }
    for( int i=0; i<26; ++i ){
        lowercaseTable[i] = capitalTable[i] + 'a' - 'A';
    }

    //Encrypt String
    while( (charIndex = *data++) != '\0' ){
        if( ISLOWERCASE(charIndex) ){
            *encrypt++ = lowercaseTable[charIndex - 'a'];
        }
        else if( ISCAPITAL(charIndex) ){
            *encrypt++ = capitalTable[charIndex - 'A'];
        }
    }
    *encrypt = '\0';

}

int main(int argc, char *argv[])
{
    char key[MAX_STR_LEN], data[MAX_STR_LEN], encrypt[MAX_STR_LEN];
    memset( key, sizeof( key ), 0 );
    memset( data, sizeof( data ), 0 );
    memset( encrypt, sizeof( encrypt ), 0 );
    scanf( "%s", key );
    scanf( "%s", data );
    fnEncrypt( key, data, encrypt );
    printf( "%s\n", encrypt );
    return 0;
}
