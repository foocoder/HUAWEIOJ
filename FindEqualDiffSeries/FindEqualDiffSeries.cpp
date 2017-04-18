/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        FindEqualDiffSeries.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-18 15:51:03
 * @last update: 2017-04-18 18:24:35
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

#define MAX_ARR_LEN 10000
#define MAX 1000

using namespace std;

void fnFindPrime( long nNum, bool bIsPrime [] ){

    bIsPrime[0] = false;
    bIsPrime[1] = false;

    int nSqrt = sqrt( (double) nNum );
    int nCount = 0;
    for( int i=2; i<=nSqrt; ++i ){
        if( bIsPrime[i] ){
            for( int j=2; i*j<=nNum; ++j ){
                bIsPrime[ j*i ] = false;
            }
        }
    }
    return ;
}

int main(int argc, char *argv[])
{
    int nLower, nUpper;
    cin>>nLower>>nUpper;

    bool bIsPrime [ MAX_ARR_LEN ];
    memset( bIsPrime, 1, sizeof( bIsPrime ) );

    fnFindPrime( nUpper, bIsPrime );

    vector<int> vecPrime;
    for( int i=nLower; i<=nUpper; ++i ){
        if( bIsPrime[i] ){
            vecPrime.push_back( i );
        }
    }

    int dp[MAX][MAX];
    for( int i=0; i<MAX; ++i ){
        for( int j=0; j<MAX; ++j ){
            dp[i][j] = 1;
        }
    }
    int nSize = vecPrime.size();
    int nMaxLen = 1;
    int nLastNum=1000, nDiff=0;
    for( int i=1; i<nSize; ++i ){
        for( int j=i-1; j>=0; --j ){
            int nDelta = vecPrime[i] - vecPrime[j];
            dp[i][nDelta] = dp[j][nDelta] + 1;
            if( nMaxLen < dp[i][nDelta] ){
                nMaxLen = dp[i][nDelta];
                nLastNum = vecPrime[i];
                nDiff = nDelta;
            }
            else if( nMaxLen == dp[i][nDelta] ){
                if( nLastNum > vecPrime[i] ){
                    nDiff = nDelta;
                    nLastNum = vecPrime[i];
                }
            }
        }
    }
    if( nLastNum == 0 || nDiff == 0 ){
        cout<<"Error"<<endl;
        return 0;
    }
    int nStart = nLastNum - (nDiff*(nMaxLen-1));
    for( int i=nStart; i<=nLastNum; i += nDiff ){
        if( i != nLastNum )
            cout<<i<<" ";
        else
            cout<<i<<endl;
    }

    return 0;
}
