#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,m,num,flag=0;
    cin>>n>>m;
    int ar[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>ar[i][j];
    cin>>num;
    int x=0,y=m-1;
    while(x<n&&y>=0)
    {
        if(ar[x][y]==num)
        {flag++;
         break;
        }
        if(ar[x][y]<num)
            x++;
        if(ar[x][y]>num)
            y--;
    }
    if(flag>0)
        cout<<"1"<<endl;
    else cout<<"0"<<endl;
    }
    return 0;
}
