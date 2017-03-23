// ---- Program Info Start----
//FileName:     CombineBySort.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-23 23:41:39
// ---- Program Info End  ----

#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
    set<int> setOutput;
    int n,m;
    cin>>n;
    int nNum;
    for( int i=0; i<n; ++i ){
        cin>>nNum;
        setOutput.insert( nNum );
    }
    cin>>m;
    for( int i=0; i<m; ++i ){
        cin>>nNum;
        setOutput.insert( nNum );
    }
    for( auto i : setOutput){
        cout<<i;
    }

    return 0;
}
