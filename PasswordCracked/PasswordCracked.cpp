/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        PasswordCracked.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-01 20:35:27
 * @last update: 2017-04-01 20:53:47
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <cstdio>
#include <cstring>
#include <cctype>

#define MAX_STR_LEN 100

char cLowerMap [ 26 ] = {
    '2', /* a */
    '2', /* b */
    '2', /* c */
    '3', /* d */
    '3', /* e */
    '3', /* f */
    '4', /* g */
    '4', /* h */
    '4', /* i */
    '5', /* j */
    '5', /* k */
    '5', /* l */
    '6', /* m */
    '6', /* n */
    '6', /* o */
    '7', /* p */
    '7', /* q */
    '7', /* r */
    '7', /* s */
    '8', /* t */
    '8', /* u */
    '8', /* v */
    '9', /* w */
    '9', /* x */
    '9', /* y */
    '9', /* z */
};
int main(int argc, char *argv[])
{
    char cPasswordArr [ MAX_STR_LEN ] = { 0 };
    char cCrackedArr [ MAX_STR_LEN ] = { 0 };
    scanf( "%s", cPasswordArr );

    char * pStr = cPasswordArr;
    char cIndex;
    int nIndex = 0;

    while( (cIndex = *pStr++) != '\0' ){
        if( isupper(cIndex) ){
            cCrackedArr[ nIndex++ ] = tolower( 'A' + (cIndex-'A'+1)%26 );
        }
        else if( islower(cIndex) ){
            cCrackedArr[ nIndex++ ] = cLowerMap[ cIndex-'a' ];
        }
        else{
            cCrackedArr[ nIndex++ ] = cIndex;
        }
    }
    printf("%s\n", cCrackedArr);

    return 0;
}
