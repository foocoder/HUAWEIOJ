/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        Rabbit.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-02 11:43:48
 * @last update: 2017-04-02 11:43:50
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>

using namespace std;
class Solution {
    public:
        int Fibonacci(int n) {// recursive version
            if(n==0 || n==1)
                return n;
            else
                return (Fibonacci(n-1)+Fibonacci(n-2));
        }

        int Fibonacci0(int n){// non-recursive version
            if(n==0 || n==1)
                return n;
            int lastNum = 1, lastOfLast = 0;
            int currentNum;
            for(int i=2; i<=n; i++){
                currentNum = lastNum + lastOfLast;
                lastOfLast = lastNum;
                lastNum    = currentNum;
            }
            return currentNum;
        }

};

int main(int argc, char *argv[])
{
    Solution test;
    int nMonths;
    cin>>nMonths;
    cout<<test.Fibonacci0( nMonths )<<endl;
    return 0;
}
