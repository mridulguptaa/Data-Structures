#include<bits/stdc++.h>
using namespace std;
int dp[100][100]={0};


int sum(int *a,int i,int j){
	int ans = 0;
	for(int k=i;k<=j;k++){
		ans += a[k];
	}
	return ans%100;
}

int smoke(int *a,int i,int j)
{
	if(i==j||i>j)
		return 0;

    if(dp[i][j]!=0)
        return dp[i][j];

	//Rec Case
	for(int k=i;k<j;k++){
		int firstPart = smoke(a,i,k);
		int secondPart = smoke(a,k+1,j);

		int total_smoke = firstPart + secondPart + sum(a,i,k)*sum(a,k+1,j);
		 dp[i][j]=total_smoke ;
	}
	return dp[i][j];

}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
        cin>>a[i];

    /*for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            dp[i][j]=-1;*/
	cout<<smoke(a,0,n-1);
}
