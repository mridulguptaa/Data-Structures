#include<iostream>
using namespace std;

int subsetsum(int j,int ar[],int n)
{
    int i,tempsum=0;

    for(i=0;i<n;i++)
        {
            if((j&1)==1)
                tempsum+=ar[i];

            j>>=1;
        }

    if(tempsum==0)
        return 1;
    else return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n,i,ar[5],flag=0;
        cin>>n;

        for(i=0;i<n;i++)
            cin>>ar[i];

        for(int j=1;j<16;j++)
            {
                if(subsetsum(j,ar,n))
                    {
                     flag++;
                     break;
                    }
            }
        if(flag==1)
            cout<<"Yes";
        else cout<<"No";

    }

    return 0;
}
