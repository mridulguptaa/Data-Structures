#include<iostream>
#include<math.h>
using namespace std;

int subsetsum(int j,int ar[],int n,int sum)
{
    int i,tempsum=0;

    for(i=0;i<n;i++)
        {
            if((j&1)==1)
                tempsum+=ar[i];

            j>>=1;
        }

    if(tempsum==sum)
        return 1;
    else return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n,sum,i,flag=0;
        cin>>n>>sum;
        int ar[n];

        for(i=0;i<n;i++)
            cin>>ar[i];

        for(int j=1;j<pow(2,n);j++)
            {
                if(subsetsum(j,ar,n,sum))
                    {
                     flag++;
                     break;
                    }
            }
        if(flag==1)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }

    return 0;
}
