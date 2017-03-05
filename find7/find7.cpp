// ---- Program Info Start----
//FileName:     find7.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-04 17:43:23
// ---- Program Info End  ----

#include <iostream>

using namespace std;

int has7(int iNumber){
    if( iNumber % 7 == 0 ){
        return 1;
    }
    while( iNumber / 10 ){
        if( iNumber % 10 == 7 ){
            return 1;
        }
        iNumber /= 10;
    }
    if( iNumber % 10 == 7 )
        return 1;
    return 0;
}

int find7(int N){
    int cnt = 0;
    for(int i=7; i<=N; ++i){
        cnt += has7(i);
    }
    return cnt;
}
int main(int argc, char *argv[])
{
    int N;
    cin>>N;
    cout<<find7(N);
    return 0;
}
