// ---- Program Info Start----
//FileName:     CombineRecords.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-25 11:23:56
// ---- Program Info End  ----

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int nNum;
    cin>>nNum;
    int nKey, nVal;
    map<int, int> mapRecords;
    vector<int> vectorKeys;
    for(int i=0; i<nNum; ++i){
        cin>>nKey>>nVal;
        if( mapRecords.find(nKey) != mapRecords.end() ){
            mapRecords[nKey] += nVal;
        }
        else{
            mapRecords[nKey] = nVal;
            vectorKeys.push_back( nKey );
        }
    }
    for( auto i:vectorKeys ){
        cout<<i<<endl;
        cout<<mapRecords[i]<<endl;
    }
    return 0;
}
