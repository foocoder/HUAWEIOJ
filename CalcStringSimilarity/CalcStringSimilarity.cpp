/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        CalcStringSimilarity.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-17 19:06:13
 * @last update: 2017-04-17 19:12:47
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <string>

using namespace std;

#define N 100
#define M 100
int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
    // write code here‘
    int dp[N][M];
    for( int i=0; i<=m; ++i ){
        dp[0][i] = c0 * i;
    }
    for( int i=1; i<=n; ++i ){
        dp[i][0] = c1 * i;
    }
    int replace = c0+c1 > c2 ? c2 : c0+c1;
    for( int i=1; i<=n; ++i ){
        for( int j=1; j<=m; ++j ){
            int up = dp[i-1][j]+c1;
            int left = dp[i][j-1]+c0;
            int leftup = A[i-1] == B[j-1] ? dp[i-1][j-1] : dp[i-1][j-1]+ replace;
            int min = up < left ? up : left;
            min = leftup < min ? leftup : min;
            dp[i][j] = min;
        }
    }
    return dp[n][m];
}

int main(int argc, char *argv[])
{
    string strA, strB;
    cin>>strA>>strB;
    int nDis = findMinCost(strA, strA.size(), strB, strB.size(), 1, 1, 1);
    cout<<"1/"<<nDis+1<<endl;
    return 0;
}
