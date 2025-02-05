//
// Created by Emma on 2025/1/18.
//
#include<iostream>
#include<cstdio>
using namespace std;
int shuzu[10001][10001];
int main()
{
    int n,x,y;
    int b=1;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int ii=1;ii<=4;++ii)
            cin>>shuzu[i][ii];                               //输入数据
    }
    cin>>x>>y;
    for(int q=n;q>=1;--q)
    {
        if((shuzu[q][1]<=x)&&(shuzu[q][3]+shuzu[q][1]>=x)&&(shuzu[q][2]<=y)&&(shuzu[q][2]+shuzu[q][4]>=y))
        {
            cout<<q;
            b=2    ;
        }
        if(b==2)
            break;
        if(q==1)
        {
            cout<<-1;
            break;
        }
    }
    return 0;
}