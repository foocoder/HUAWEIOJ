/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        ParseParameter.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-23 14:12:28
 * @last update: 2017-04-23 14:51:22
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string strLine;
    getline( cin, strLine );
    int nLen = strLine.size();
    int nIdx = 0;
    char charIdx;
    bool bIsFinish = true;
    bool bIsQuote = false;

    vector<string> vecParameters;
    string strPara;
    while( ( charIdx = strLine[nIdx++] ) != '\0' ){
        if( charIdx == ' ' ){
            if( bIsQuote ){
                strPara += ' ';
                continue;
            }
            else{
                if( !strPara.empty() ) {
                    vecParameters.push_back( strPara );
                    strPara.clear();
                }
                /* bIsFinish = true; */
            }
        }
        else if( charIdx == '\"' ){
            if( bIsQuote ){
                bIsQuote = false;
            }
            else{
                bIsQuote = true;
            }
        }
        else{
            strPara += charIdx;
        }
    }
    if( !strPara.empty() ){
        vecParameters.push_back( strPara );
    }
    cout<<vecParameters.size()<<endl;
    for( auto i : vecParameters ){
        cout<<i<<endl;
    }
    /* for( int i=0; i<nLen; ++i ){ */
    /*     if( strLine[i]  ){ */

    /*     } */
    /* } */

    return 0;
}
