#include<bits/stdc++.h>
using namespace std;
char temp[100];

void print()
{
    cout<<temp<<endl;

}

int combine(char ar[],int k,int n,int p)
{
    if(p==k)
    {
        print();
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        temp[p]=ar[i];
        combine(ar,k,n,p+1);
    }


}


int main()
{
   /* int k, n;
    cin>>n;
    char ar[n];     //n is number pf elements
    for(int i=0;i<n;i++)
        cin>>ar[i];
    cout<<"enter K \n";
    cin>>k;
    combine(ar,k,n,0);
    return 0;*/

    char a='2';
    cout<<a+2;

}
