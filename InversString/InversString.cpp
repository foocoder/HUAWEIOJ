// ---- Program Info Start----
//FileName:     InversString.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-22 21:14:16
// ---- Program Info End  ----


#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string strLine;
    getline( cin, strLine );
    int szLen = strLine.size();
    for( int i=szLen-1; i>=0; --i ){
        cout<<strLine[i];
    }
    cout<<endl;
    return 0;
}
