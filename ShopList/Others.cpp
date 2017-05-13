#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAX_N 3200
#define MAX_M 60

using namespace std;

/* int Knapsack(int v[],int w[],int pro[],int N,int m) */
/* { */
/*     int c[MAX_M][MAX_N],i,j; */
/*     bool flag[MAX_M][MAX_N]; */
/*     memset(c,0,sizeof(c)); */
/*     memset(flag,false,sizeof(flag)); */
/*     for(i=1;i<=m;i++) */
/*     { */
/*         for(j=0;j<=N;j++) */
/*         { */
/*             if(pro[i]==0) */
/*             { */
/*                 c[i][j]=c[i-1][j]; */
/*                 if(v[i]<=j&&c[i][j]<c[i-1][j-v[i]]+v[i]*w[i]) */
/*                 { */
/*                     c[i][j]=c[i-1][j-v[i]]+v[i]*w[i]; */
/*                     flag[i][j]=true; */
/*                 } */
/*             } */
/*             else */
/*             { */
/*                     c[i][j]=c[i-1][j]; */
/*                     if(v[i]<=j&&c[i][j]<c[i-1][j-v[i]]+v[i]*w[i]) */
/*                     { */
/*                         if(flag[pro[i]][j-v[i]]) */
/*                             c[i][j]=c[i-1][j-v[i]]+v[i]*w[i]; */
/*                     } */
/*             } */
/*         } */
/*     } */
/*     return c[m][N]; */
/* } */

int main()
{
    int v[MAX_M],w[MAX_M],pro[MAX_M];
    int N, m;
    cin>>N>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>v[i]>>w[i]>>pro[i];
    }
    /* cout<<Knapsack( v, w, pro, N, m ); */
    int c[MAX_M][MAX_N],i,j;
    bool flag[MAX_M][MAX_N];
    memset(c,0,sizeof(c));
    memset(flag,false,sizeof(flag));
    for(i=1;i<=m;i++)
    {
        for(j=0;j<=N;j++)
        {
            if(pro[i]==0)
            {
                c[i][j]=c[i-1][j];
                if(v[i]<=j&&c[i][j]<c[i-1][j-v[i]]+v[i]*w[i])
                {
                    c[i][j]=c[i-1][j-v[i]]+v[i]*w[i];
                    flag[i][j]=true;
                }
            }
            else
            {
                c[i][j]=c[i-1][j];
                if(v[i]<=j&&c[i][j]<c[i-1][j-v[i]]+v[i]*w[i])
                {
                    if(flag[pro[i]][j-v[i]])
                        c[i][j]=c[i-1][j-v[i]]+v[i]*w[i];
                }
            }
        }
    }
    cout<<c[m][N]<<endl;
    return 0;
}
