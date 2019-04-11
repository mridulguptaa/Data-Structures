
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ar[]={2,4,1,56,76,11,100};
    int mi,ma;
    mi=1;
    ma=100;
    int range=ma-mi-1;

    int holes[range];
    memset(holes,-1,sizeof(holes));

    for(int i=0;i<7;i++)
    {
        holes[ar[i]-mi]=ar[i];

    }
    for(int i=0;holes[i]!=NULL;i++)
        if(holes[i]!=-1)
            cout<<holes[i]<<" ";

}
