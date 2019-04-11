#include<iostream>
using namespace std;

void lcs(int a[], int b[],int n,int m,int k){
    int mins=min(n,m);
    int dp[2005][2005]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int q;
                if(a[i-1]==b[j-1]) q=1+dp[i-1][j-1];
                else{
                    q=max(dp[i-1][j],dp[i][j-1]);
                }
                dp[i][j]=q;
            }
    }
    cout<<min(mins,dp[n][m]+k);
    return ;
}

int main() {
        int n,m,k,a[2005]={0},b[2005]={0};
        cin>>n>>m>>k;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        lcs(a,b,n,m,k);
        // cout<<ans;


	return 0;
}
