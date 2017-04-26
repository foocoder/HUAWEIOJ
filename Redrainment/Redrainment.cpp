/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        Redrainment.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-26 15:26:35
 * @last update: 2017-04-26 15:46:58
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int nNum;
    cin>>nNum;
    vector<int> nSeq(nNum);
    for( int i=0; i<nNum; ++i ){
        cin>>nSeq[i];
    }
    vector<int> nDP(nNum, 0);
    nDP[0] = 1;
    //i表示当前处理节点
    for( int i=1; i<nNum; ++i ){
        //J表示已经处理好节点
        nDP[i] = 1;
        for( int j=0; j<i; ++j ){
            if( nSeq[i] > nSeq[j] ){
                nDP[i] = nDP[i] > (nDP[j]+1) ? nDP[i] : (nDP[j]+1);
            }
        }
    }
    cout<<nDP[nNum-1]<<endl;
    return 0;
}
