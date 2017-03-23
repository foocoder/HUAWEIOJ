// ---- Program Info Start----
//FileName:     StringMatch.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 17:16:11
// ---- Program Info End  ----

#include <stdio.h>
#include <string.h>

bool nASCIIAlphet[ 256 ] = { 0 };

bool fnIsAllCharExist( char * pShortString, char * pLongString ){
    int nShortLength = strlen( pShortString );
    int nLongLength = strlen( pLongString );
    for( int i=0; i<nShortLength; ++i ){
        if( !nASCIIAlphet[ pShortString[i] ] ){
            nASCIIAlphet[ pShortString[i] ] = true;
        }
    }
    for( int i=0; i<nLongLength; ++i ){
        if( nASCIIAlphet[ pLongString[i] ] ){
            nASCIIAlphet[ pLongString[i] ] = false;
        }
    }
    for( int i=0; i<256; ++i ){
        if( nASCIIAlphet[i] )
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    char cShortString [ 100 ] = { 0 };
    char cLongString [ 100 ] = { 0 };
    scanf( "%s", cShortString );
    scanf( "%s", cLongString );

    fnIsAllCharExist( cShortString, cLongString ) ? printf( "true" ) : printf( "false" );
    return 0;
}
