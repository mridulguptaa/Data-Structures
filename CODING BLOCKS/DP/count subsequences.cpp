#include<bits/stdc++.h>
using namespace std;

void subsequence(set<string>&s1,string s,int len,char temp[],int x,int pushed) // x is the n-1th function called
{
    //base case to be written
    if(x>=len)
        {
            /*countt++;
            cout<<countt<<" "<<temp<<endl;*/
            s1.insert(temp);
            return;
        }

        subsequence(s1,s,len,temp,x+1,pushed);
        temp[pushed]=s[x];
        temp[pushed+1]='\0';
        subsequence(s1,s,len,temp,x+1,pushed+1);

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    string s;
    set<string>s1;
    int len,countt=0;
    cin>>s;
    len=s.length();
    int dp[len+1]={0};
    char temp[len]={'\0'};
    subsequence(s1,s,len,temp,0,0);
     for (set<string>::iterator it=s1.begin(); it!=s1.end(); ++it)
        countt++;
    cout<<countt;

    }
    return 0;
}
