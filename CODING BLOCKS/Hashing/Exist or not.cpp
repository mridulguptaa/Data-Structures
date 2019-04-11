
using namespace std;
#include<bits/stdc++.h>
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
	    map<long long int,long long int>m;
	    long long int n;
	    cin>>n;
	    long long int ar[n];
	    for(long long int i=0;i<n;i++)
	    {
	        cin>>ar[i];
	        m[ar[i]]=1;

	    }
	    long long int q,temp;
	    cin>>q;
	    while(q--)
	    {
	        cin>>temp;
	        if(m[temp]==1)
	            cout<<"YES"<<endl;
	       else cout<<"NO"<<endl;
	    }

	}

	return 0;
}
