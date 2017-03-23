// ---- Program Info Start----
//FileName:     MarkNumber.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 21:55:56
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>

#define ISDIGIT(letter) ( (letter)>='0' && (letter)<='9' )
int main(int argc, char *argv[])
{
    char cStringArr[100];
    scanf( "%s", cStringArr);

    int nStrLength = strlen( cStringArr );
    bool flag = false;
    for( int i=0; i<nStrLength; ++i ){
        if( ISDIGIT(cStringArr[i]) && !flag ){
            printf("*%c", cStringArr[i]);
            flag = true;
        }
        else if( !ISDIGIT(cStringArr[i]) && flag ){
            printf("*%c", cStringArr[i]);
            flag = false;
        }
        else{
            printf("%c", cStringArr[i]);
        }
    }
    if( flag ) printf( "*" );

    return 0;
}
