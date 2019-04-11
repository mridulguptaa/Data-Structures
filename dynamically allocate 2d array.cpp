#include<bits/stdc++.h>
using namespace std;

void print(int**ar,int k,int n)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
            cout<<ar[i][j]<<" ";
        cout<<endl;
    }

}
int main()
{
    int n,k;
    cin>>k>>n;
    int**ar=new int*[k];
    for(int i=0;i<k;i++)
    {
        ar[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>ar[i][j];
    }
    print(ar,k,n);



    //delete the array.
    for(int i = 0; i <k; ++i)
    {
    delete []ar[i];
    }
    delete [] ar;
    return 0;
}
