#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
bool check(string s,int start,int end)
{
    for(int i=start,j=end;i<j;i++,j--)
        if(s[i]!=s[j])
            return false;
    return true;
}

int palindromepartition(string s,int start,int end)
{
    if(start>=end)  //base case
        return 0;
    if(check(s,start,end))  //already palindrome
        return 0;
    if(dp[start][end]!=-1)
        return dp[start][end];
    for(int i=start;i<=end-1;i++)
    {
        int ans1=palindromepartition(s,start,i);
        int ans2=palindromepartition(s,i+1,end);
        int ans3=ans1+ans2+1;
        if(dp[start][end]==-1)
            dp[start][end]=ans3;
        else
            dp[start][end]=min(dp[start][end],ans3);
    }
    return dp[start][end];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp[0][0])*1000*1000);
        string s;
        int len;
        cin>>s;
        len=s.length();
        if(check(s,0,len-1))
            cout<<"0"<<endl;
        else
            cout<<palindromepartition(s,0,len-1)<<endl;
    }
    return 0;
}
