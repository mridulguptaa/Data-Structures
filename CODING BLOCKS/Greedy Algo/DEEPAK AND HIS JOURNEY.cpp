#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int price[n];
        for(long long int i=0;i<n;i++)
            cin>>price[i];
        long long int req[n];
        for(long long int i=0;i<n;i++)
            cin>>req[i];
        long long int ans=0;
        long long int z=0,left=0;
        while(z<n)
        {
            //cout<<ans<<endl;

            //if(left<req[z]) //yaha se bharwana hai

                long long int temp=price[z];
                ans+=temp*req[z]; //atleast itna to chahiye hi
                //left+=req[z];
                z++;

                while(temp<price[z] && z<n)  //next wale se price kam hai
                {
                    ans+=temp*req[z++];
                }

        }
        cout<<ans<<endl;

    }

    return 0;
}
