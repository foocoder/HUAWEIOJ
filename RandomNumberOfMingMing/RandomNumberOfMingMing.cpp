// ---- Program Info Start----
//FileName:     RandomNumberOfMingMing.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-24 12:44:27
// ---- Program Info End  ----

#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
    int nNum;
    cin >> nNum;
    set<int> siSortSet;
    int nInput;
    for( int i=0; i<nNum; ++i ){
        cin>>nInput;
        siSortSet.insert( nInput );
    }
    for( auto i:siSortSet ){
        cout<<i<<endl;
    }
    return 0;
}
