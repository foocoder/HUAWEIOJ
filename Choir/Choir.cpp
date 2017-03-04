// ---- Program Info Start----
//FileName:     Choir.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-02-19 15:26:50
// ---- Program Info End  ----

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

void GetRLIS(const vector<int> & vNumbers, vector<int> & vDP){
    int iLen = vNumbers.size();
    for( int i=iLen-1; i>=0; --i ){
        vDP[i] = 1;
        for( int j=iLen-1; j>i; --j ){
            if( vNumbers[i] > vNumbers[j] && vDP[i] < vDP[j]+1 )
                vDP[i] = vDP[j] + 1;
        }
    }
}
void GetLIS(const vector<int> & vNumbers, vector<int> & vDP){
    int iLen = vNumbers.size();
    for( int i=0; i<iLen; ++i ){
        vDP[i] = 1;
        for( int j=0; j<i; ++j ){
            if( vNumbers[i] > vNumbers[j] && vDP[i] < vDP[j]+1 )
                vDP[i] = vDP[j] + 1;
        }
    }
}
int main(int argc, char *argv[])
{
    // 130 150 160 186 186 197 200 200
    /* while( getline(cin, strLine)){ */
        int iNum;
        cin>>iNum;
        vector<int> vNumbers( iNum );
        for( int i=0; i<iNum; ++i){
            cin >> vNumbers[i];
        }
        vector<int> vAscendingDP(iNum), vDescendingDP(iNum);
        GetLIS(vNumbers, vAscendingDP);
        GetRLIS(vNumbers, vDescendingDP);
        int iMaxLen = 0;
        for( int i=0; i<iNum; ++i ){
            if(vAscendingDP[i]+vDescendingDP[i]-1 > iMaxLen)
                iMaxLen = vAscendingDP[i]+vDescendingDP[i]-1;
        }
        cout<<iNum - iMaxLen<<endl;
    /* } */

    return 0;
}
