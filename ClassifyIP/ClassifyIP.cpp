/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        ClassifyIP.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-23 15:35:00
 * @last update: 2017-04-23 17:09:04
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

void fnProcessStr( const string & strLine, string & strIP, string & strMask ){
    int nLineLen = strLine.size();
    int nIdx;
    for( nIdx = 0; strLine[nIdx] != '~'; nIdx++ );
    strIP = strLine.substr( 0, nIdx );
    strMask = strLine.substr( nIdx+1, nLineLen-nIdx-1 );
}

void fnProcessIP( const string & strIP, vector<int> & vecIP ){
    int nIdx = 0;
    char charIdx;
    string strInt;
    while( ( charIdx = strIP[nIdx++] ) != '\0' ){
        if( charIdx == '.' ){
            if( strInt.empty() ){
            }
            else{
                int nTempIP = stoi( strInt );
                vecIP.push_back( nTempIP );
                strInt.clear();
            }
        }
        else if( isdigit(charIdx) ){
            strInt += charIdx;
        }
    }
    if( !strInt.empty() ){
        vecIP.push_back( stoi(strInt) );
    }
    return;
}

bool fnCheckIP( const vector<int> & vecIP ){
    if( vecIP.size() != 4 ){
        return false;
    }
    if( vecIP[0] == 0 )
        return false;
    for( int i=0; i<4; ++i ){
        if( vecIP[i] > 255 || vecIP[i] < 0 ){
            return false;
        }
    }
    return true;
}

bool fnCheckMask( const vector<int> & vecIP ){
    if( !fnCheckIP( vecIP ) ){
        return false;
    }
    int i;
    for( i=0; i<4 && vecIP[i] == 255; ++i );
    if( vecIP[i] != 254 &&
        vecIP[i] != 252 &&
        vecIP[i] != 248 &&
        vecIP[i] != 240 &&
        vecIP[i] != 224 &&
        vecIP[i] != 192 &&
        vecIP[i] != 128 &&
        vecIP[i] != 0 ){
        return false;
    }
    for( i=i+1; i<4; ++i ){
        if( vecIP[i]!=0 )
            return false;
    }
    return true;

}

void fnClassify( const vector<int> & vecIP, const vector<int> & vecMask, vector<int> & vecType ){
    if( !fnCheckIP( vecIP ) ){
        vecType[5] += 1;
        return;
    }
    if( !fnCheckMask( vecMask ) ){
        vecType[5] += 1;
        return;
    }
    //判断ABCDE
    vector<int> vecAnd( 4 );
    for( int i=0; i<4; ++i ){
        vecAnd[i] = vecIP[i] & vecMask[i];
    }
    if( vecAnd[0]<= 127  ){
        vecType[0] ++;
        if( vecAnd[0] == 10 )
            vecType[6]++;
    }
    else if( vecAnd[0] <= 191 ){
        vecType[1] ++;
        if( vecAnd[0] == 172 && vecAnd[1] >= 16 && vecAnd[1] <= 32 )
            vecType[6]++;
    }
    else if( vecAnd[0] <= 223 ){
        vecType[2] ++;
        if( vecAnd[0] == 192 && vecAnd[1] == 168 )
            vecType[6]++;
    }
    else if( vecAnd[0] <= 239 ){
        vecType[3] ++;
    }
    else{
        vecType[4]++;
    }
}

int main(int argc, char *argv[])
{
    string strLine;
    vector<int> vecType( 7 );
    while( cin>>strLine ){
        string strIP, strMask;
        fnProcessStr( strLine, strIP, strMask );
        /* cout<<strIP<<endl; */
        /* cout<<strMask<<endl; */
        vector<int> vecIP, vecMask;
        fnProcessIP( strIP, vecIP );
        fnProcessIP( strMask, vecMask );
        fnClassify(vecIP, vecMask, vecType);
    }
    for( int i=0; i<7; ++i ){
        if( i!=6 )
            cout<<vecType[i]<<" ";
        else
            cout<<vecType[i]<<endl;
    }

    return 0;
}
