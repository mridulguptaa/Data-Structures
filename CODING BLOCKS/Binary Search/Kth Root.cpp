#include<bits/stdc++.h>
using namespace std;

int squareRoot(int n){
	int s= 0;
	int e = n;

	float ans = -1;
	while(s<=e){
		int mid = (s+e)/2;

		if(mid*mid==n){
			ans = mid;
			break;
		}
		else if(mid*mid<n){
			ans = mid;
			s = mid + 1;
		}
		else{
			e = mid  - 1;
		}

	}
	return ans;

}

int findextra(int n,int extra,int k,int rem)
{
    for(int i=extra;i<n;i++)
        if(pow(i,k)>rem)
            return (i-1);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
	int n,k,temp,extra,rem;
	cin>>n>>k;
	temp=k;
	rem=n;
	while(temp>1)
	{
	    temp/=2;
	    n=squareRoot(n);
	}
	if(k%2==1)
    {
        extra=squareRoot(n);
        cout<<findextra(n,extra,k,rem);
    }
    else cout<<n;
    }
return 0;
}
