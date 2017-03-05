// ---- Program Info Start----
//FileName:     CalculateCapitals.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-05 18:31:08
// ---- Program Info End  ----

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string strLine;
    getline(cin, strLine);
    char cChar;
    istringstream ssLine(strLine);
    int iCount = 0;
    while(ssLine>>cChar){
        if(cChar >= 'A' && cChar <= 'Z'){
            iCount++;
        }
    }
    cout<<iCount<<endl;
    return 0;
}
