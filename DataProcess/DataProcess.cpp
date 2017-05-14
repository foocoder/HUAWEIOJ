/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        DataProcess.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-05-14 19:31:06
 * @last update: 2017-05-14 20:05:08
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

vector<pair<int, int>> fnProcessInclude( const vector<int> & inputNumbers, int nRule ){
    string strRule = to_string( nRule );
    int nSize = inputNumbers.size();
    vector<pair<int,int>> retData;
    for( int i=0; i<nSize; ++i ){
        string strNum = to_string( inputNumbers[i] );
        if( strNum.find(strRule) != string::npos ){
            retData.push_back(make_pair( i, inputNumbers[i] ));
        }
    }
    return retData;
}

int main(int argc, char *argv[])
{
    set<int> inputRules;

    int nNumbers;
    cin>>nNumbers;
    vector<int> inputNumbers(nNumbers);
    for( int i=0; i<nNumbers; ++i ){
        cin>>inputNumbers[i];
    }

    int nRules;
    cin>>nRules;
    for( int i=0; i<nRules; ++i ){
        int rule;
        cin>>rule;
        inputRules.insert( rule );
    }

    vector<int> results;
    for( auto i : inputRules ){
        vector<pair<int, int>> vecRes =
            fnProcessInclude( inputNumbers, i );
        if( !vecRes.empty() ){
            results.push_back( i );
            results.push_back( vecRes.size() );
            for( auto j : vecRes ){
                results.push_back( j.first );
                results.push_back( j.second );
            }
        }
    }

    int nSize = results.size();
    cout<<nSize;
    for( int i=0; i<nSize; ++i ){
        cout<<" "<<results[i];
    }
    cout<<endl;

    return 0;
}
