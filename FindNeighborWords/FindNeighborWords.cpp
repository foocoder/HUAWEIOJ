/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        FindNeighborWords.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-06 11:17:47
 * @last update: 2017-04-06 12:10:44
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int nWordCount;
    cin>>nWordCount;
    map<string, set<string>> mapDictionary;
    for( int i=0; i<nWordCount; ++i ){
        string strDicWord;
        cin>>strDicWord;
        string strIndexWord(strDicWord);
        sort( strIndexWord.begin(), strIndexWord.end() );
        mapDictionary[strIndexWord].insert( strDicWord );
    }
    string queryWord;
    cin>>queryWord;
    string queryIndexWord( queryWord );
    sort( queryIndexWord.begin(), queryIndexWord.end() );
    int nQueryNum;
    cin>>nQueryNum;

    int nQuerySize = mapDictionary[queryIndexWord].size();
    string strResultWord;
    set<string>::iterator setIterator = mapDictionary[queryIndexWord].find(queryWord);
    if( setIterator != mapDictionary[queryIndexWord].end() ){
        nQuerySize--;
    }
    for( const auto &i : mapDictionary[queryIndexWord] ){
        if( i.compare(queryWord) == 0 ){
            continue;
        }
        nQueryNum--;
        if( nQueryNum == 0 ) {
            strResultWord = i;
            break;
        }
    }

    if( nQueryNum==0 ){
        cout<<nQuerySize<<endl;
        cout<<strResultWord<<endl;
    }
    else{
        cout<<nQuerySize<<endl;
    }
    return 0;
}
