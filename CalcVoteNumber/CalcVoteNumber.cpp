// ---- Program Info Start----
//FileName:     CalcVoteNumber.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-29 19:42:28
// ---- Program Info End  ----

#include <cstdio>

#define MAX_LEN 100


int main(int argc, char *argv[])
{
    int nNumCandidate, nNumVote;
    scanf( "%d", &nNumCandidate );
    char cNameArr[MAX_LEN] = { 0 };
    int nVoteArr[128] = { 0 };
    for( int i=0; i<nNumCandidate; ++i ){
        char cName;
        getchar();
        scanf( "%c", &cName );
        cNameArr[i] = cName;
    }
    scanf( "%d", &nNumVote );
    for( int i=0; i<nNumVote; ++i ){
        char cName;
        getchar();
        scanf( "%c", &cName );
        nVoteArr[cName] ++;
    }
    int nValidCount = 0;
    for( int i=0; i<nNumCandidate; ++i ){
        printf( "%c : %d\n", cNameArr[i], nVoteArr[cNameArr[i]] );
        nValidCount+=nVoteArr[cNameArr[i]];
        nVoteArr[cNameArr[i]] = 0;
    }
    printf( "Invalid : %d", nNumVote-nValidCount );
    return 0;
}
