/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        SignalInter.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-28 16:43:24
 * @last update: 2017-04-28 17:08:00
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>

using namespace std;

#define MAX_M 1000

int main(int argc, char *argv[])
{
    int m,n;
    cin>>m>>n;
    int nArr[MAX_M] = { 0 };
    int nStart, nEnd;
    for( int i=0; i<m; ++i ){
        int nNo, nVal;
        cin>>nNo>>nVal;
        if( i==0 ){
            nStart = nNo;
        }
        else if( i==m-1 ){
            nEnd = nNo;
        }
        if( !nArr[nNo] )
            nArr[nNo] = nVal;
    }
    #ifdef DEBUG
    cout<<"Print Array Before:"<<endl;
    for( int i=nStart; i<=nEnd; ++i ){
        cout<<i<<","<<nArr[i]<<endl;
    }
    cout<<endl;
    #endif
    int nM = nStart;
    for( int i=nStart+1; i<=nEnd; ++i ){
        if( !nArr[i] ){
            int nN = i;
            while( nArr[++nN] == 0 );
            int nDelta = ( nArr[nN] - nArr[nM] ) / ( nN - nM );
            for( int j=i; j<nN; ++j ){
                nArr[j] = nArr[nM] + nDelta * ( j-nM );
            }
            i = nN-1;
        }
        else{
            nM = i;
        }
    }
    for( int i=nStart; i<=nEnd; ++i ){
        cout<<i<<" "<<nArr[i]<<endl;
    }

    return 0;
}
