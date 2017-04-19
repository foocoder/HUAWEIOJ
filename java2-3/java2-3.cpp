/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        java2-3.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-19 19:48:26
 * @last update: 2017-04-19 19:56:12
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int n, m;
    cin>>n>>m;
    n++;
    m++;
    vector<vector<int>> dp( m, vector<int>(n, 0) );
    for( int i=0; i<n; ++i ){
        dp[0][i] = 1;
    }
    for( int i=0; i<m; ++i ){
        dp[i][0] = 1;
    }
    for( int i=1; i<m; ++i ){
        for( int j=1; j<n; ++j ){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    cout<<dp[m-1][n-1]<<endl;

    return 0;
}
