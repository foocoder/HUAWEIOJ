/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        ErrorRecord.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-19 20:02:45
 * @last update: 2017-04-19 21:08:54
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

#define MAX_LEN 16

int main(int argc, char *argv[])
{
    string strLine;
    vector<pair<pair<string, int>, int>> que;
    int nQueStart = 0, nQueEnd = 0;

    while( getline(cin, strLine) ){
        istringstream istr( strLine );
        string filePath;
        int lineNo;
        istr>>filePath>>lineNo;
        int nFileNameSize = filePath.size();
        int nIdx;

        //parse file name;
        for( nIdx=nFileNameSize-1; nIdx>=0 && (filePath[nIdx] != '\\'); nIdx-- );
        nIdx++;
        int nStart = (nFileNameSize - nIdx >= MAX_LEN) ? (nFileNameSize - MAX_LEN) : nIdx;
        string fileName;
        fileName = filePath.substr( nStart, nFileNameSize - nStart );

        if( nQueEnd == 0 ){
            que.push_back( make_pair(make_pair( fileName, lineNo ), 1) );
            nQueEnd++;
        }
        else if( nQueEnd - nQueStart < 8 ){
            bool bFlag = false;
            for( int i=nQueStart; i<nQueEnd; ++i ){
                if( que[i].first.first.compare( fileName ) == 0 && que[i].first.second == lineNo ){
                    que[i].second++;
                    bFlag = true;
                    break;
                }
            }
            if( !bFlag ){
                que.push_back( make_pair(make_pair( fileName, lineNo ), 1) );
                nQueEnd++;
            }
        }
        else{
            bool bFlag = false;
            for( int i=nQueStart; i<nQueEnd; ++i ){
                if( que[i].first.first.compare( fileName ) == 0 && que[i].first.second == lineNo ){
                    que[i].second++;
                    bFlag = true;
                    break;
                }
            }
            if( !bFlag ){
                que.push_back( make_pair(make_pair( fileName, lineNo ), 1) );
                nQueEnd++;
                nQueStart++;
            }
        }
    }
    for( int i=nQueStart; i<nQueEnd; i++ ){
        cout<<que[i].first.first<<" "<<que[i].first.second<<" "<<que[i].second<<endl;
    }
    return 0;
}
