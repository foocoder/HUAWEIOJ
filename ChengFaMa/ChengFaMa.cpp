// ---- Program Info Start----
//FileName:     ChengFaMa.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-05 14:38:23
// ---- Program Info End  ----

#include <iostream>
#include <vector>

using namespace std;

int ChengFaMa( int N, const vector<int> & vWeight, const vector<int> & vNumbers ){
    int iSum = 0;
    for( int i=0; i<N; ++i ){
        iSum += vWeight[i] * vNumbers[i];
    }
    vector<int> dp(iSum+1);
    dp[0] = 1;
    int iCount = 0;
    for( int i=0; i<N; ++i ){
        for( int j=0; j<vNumbers[i]; ++j ){
            for( int k=iSum; k>=vWeight[i]; k--){
                if( dp[k-vWeight[i]] == 1 ) {
                    dp[k] = 1;
                }
            }
        }
    }
    for( int i=0; i<=iSum; ++i){
        if( dp[i] == 1 )
            iCount ++;
    }
    return iCount;
}
int main(int argc, char *argv[])
{
    int N;
    cin>>N;

    vector<int> vWeight(N), vNumbers(N);
    for( int i=0; i<N; ++i){
        cin>>vWeight[i];
    }
    for( int i=0; i<N; ++i){
        cin>>vNumbers[i];
    }
    cout<<ChengFaMa(N, vWeight, vNumbers)<<endl;
    return 0;
}
