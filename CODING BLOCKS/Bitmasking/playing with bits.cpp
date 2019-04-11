#include<bits/stdc++.h>
using namespace std;

void karocount(int a,int b)
{
    int countt=0;
    for(int i=a;i<=b;i++)
    {
        int temp=i,k;
        while(temp!=0)
        {
            if((1&(temp))!=0)
                countt++;

            temp=temp>>1;
        }
    }
    cout<<countt<<endl;

}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        karocount(a,b);
    }

    return 0;
}
