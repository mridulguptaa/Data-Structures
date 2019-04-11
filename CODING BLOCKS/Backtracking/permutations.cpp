#include<bits/stdc++.h>
using namespace std;


void permute(char ar[],int n,int x)
{
    if(ar[x]=='\0' || x>=n) //base case
    {
        ar[x]='\0';
        cout<<ar<<endl;
        return;
    }

    for(int i=x;i<n;i++)
    {
        swap(ar[x],ar[i]);
        permute(ar,n,x+1);
        swap(ar[x],ar[i]);
    }

}



int main()
{
    int i,n;
    cin>>n;
    char ar[n];
    for(i=0;i<n;i++)
        cin>>ar[i];
    permute(ar,n,0);

    return 0;
}
