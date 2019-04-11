#include<bits/stdc++.h>
using namespace std;

int main()

{
    int g,b;
    cin>>g>>b;
    int girls[g],boys[b];
    for(int i=0;i<g;i++)
        cin>>girls[i];
    for(int i=0;i<b;i++)
        cin>>boys[b];

     //make the matrix

    int**mat=new int*[g];
    int**DP=new int*[g];
    for(int i=0;i<g;i++)
    {
        mat[i]=new int[b];
        DP[i]=new int[b];
    }

    for(int i=0;i<g;i++)
        for(int j=0;j<b;j++)
        {
            mat[i][j]=girls[i]*boys[j];
        }

    return 0;
}
