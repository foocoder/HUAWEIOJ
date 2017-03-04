// ---- Program Info Start----
//FileName:     MingZiDePiaoLiangDu.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-02-20 19:02:50
// ---- Program Info End  ----

#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

int getBeauty( string & strWord ){
    int alpha [26] = {0};
    int iLen = strWord.size();
    for( int i=0; i<iLen; ++i ){
        if(strWord[i] >= 'a' )
            alpha[ strWord[i]-'a' ] ++;
        else
            alpha[ strWord[i]-'A' ] ++;
    }
    sort( alpha, alpha+26);
    int res = 0;
    for( int i=25; i>=0 && alpha[i]>0; --i ){
        res += alpha[i] * (i+1);
    }
    return res;
}

int main(int argc, char *argv[])
{
    int iNum;
    cin >> iNum;
    for( int i=0; i<iNum; ++i ){
        string strWord;
        cin >> strWord;
        cout<< getBeauty(strWord) <<endl;
    }
    return 0;
}
