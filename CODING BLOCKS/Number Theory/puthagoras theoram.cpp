#include<bits/stdc++.h>
using namespace std;
void findkaro(int n)
{
    map<int,int>mappy;
    for(int i=0;i<=sqrt(n);i++)
    {
        for(int j=0;j<=sqrt(n);j++)
    {
        if((i*i)+(j*j)==n &&mappy[i]<1&&mappy[j]<1)
        {
        cout<<"("<<i<<","<<j<<")"<<" ";
        mappy[i]++;
        mappy[j]++;
        }


    }
    }
}
int main()
         {
             int t;
             cin>>t;
             while(t--)
             {
                 int n;
                 cin>>n;
                 findkaro(n);
                 cout<<endl;
             }
         }
