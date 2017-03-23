// ---- Program Info Start----
//FileName:     WildCard.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 14:22:03
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100
#define ISDIGIT( letter ) ( (letter)>='0' && (letter)<='9' )
#define ISUPPER( letter ) ( (letter)>='A' && (letter)<='Z' )
#define ISLOWER( letter ) ( (letter)>='a' && (letter)<='z' )
#define ISCHAR( letter ) ( (ISDIGIT(letter) || (ISUPPER(letter)) || (ISLOWER(letter))) )

bool fnCheckMatch( char cPatternString[], char cMatchString[] ){
    int nPatternLen = strlen( cPatternString );
    int nMatchLen   = strlen( cMatchString );


}

int main(int argc, char *argv[])
{
    char cPatternString[MAX_STR_LEN] = { 0 };
    char cMatchString[MAX_STR_LEN] = { 0 };
    scanf( "%s", cPatternString );
    scanf( "%s", cMatchString );


    return 0;
}
