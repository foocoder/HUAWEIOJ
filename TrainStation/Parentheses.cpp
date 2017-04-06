/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        Parentheses.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-06 16:54:33
 * @last update: 2017-04-06 16:59:28
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/
#include <stdio.h>

#ifndef N
    #define N 2
#endif

char str[N * 2 + 1];

void foo(int left, int leftopen, int depth)
{
    int index = depth - 1;

    if (depth == N * 2)
    {
        str[index] = ')';
        puts(str);
        return;
    }
    else
    {
        if (left < N)
        {
            str[index] = '(';
            foo(left+1, leftopen+1, depth+1);
        }

        if (leftopen > 0)
        {
            str[index] = ')';
            foo(left, leftopen-1, depth+1);
        }
    }
}

int main()
{
    str[0] = '(';
    str[N * 2] = '\0';
    foo(1, 1, 2);
    return 0;
}
