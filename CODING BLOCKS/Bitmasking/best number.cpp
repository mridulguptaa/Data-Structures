#include<iostream>
using namespace std;
int main()
{
    unsigned int n;
    int t;
    cin>>t;
    while(t--)
    {
        int n,temp,maxx=0,index=0;
        cin>>n;
        int NOS[n],ar[32]={0};
        for(int i=0;i<n;i++)
            cin>>NOS[i];
        for(int i=0;i<n;i++)
        {
            temp=NOS[i];
            for(int j=0;j<32 && temp!=0;j++)
            {
                if((1&temp)!=0)
                    ar[j]++;
                temp=temp>>1;
            }

        }
    for(int i=0;i<32;i++)
        if(ar[i]>maxx)
            {index=i;
             maxx=ar[i];
            }


    cout<<index<<endl;

    }
	return 0;
}
