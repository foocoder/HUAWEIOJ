// ---- Program Info Start----
//FileName:     GetMinK.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-05 18:39:45
// ---- Program Info End  ----

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(int argc, char *argv[])
{
    int N, K;
    cin>>N>>K;
    priority_queue<int, vector<int>, greater<int>> pq;
    int iNum;
    for( int i=0; i<N; ++i){
        cin>>iNum;
        pq.push(iNum);
    }
    for( int i=0; i<K; ++i ){
        if( i != K-1 )
            cout<<pq.top()<<" ";
        else
            cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}
