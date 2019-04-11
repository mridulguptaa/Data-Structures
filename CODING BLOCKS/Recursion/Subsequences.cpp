#include<bits/stdc++.h>
using namespace std;
int countt=0;

void subsequence(string s,int len,char temp[],int x,int pushed) // x is the n-1th function called
{
    //base case to be written
    if(x>=len)
        {
            countt++;
            cout<<countt<<" "<<temp<<endl;
            return;
        }

    {
        subsequence(s,len,temp,x+1,pushed);
        temp[pushed]=s[x];
        temp[pushed+1]='\0';
        subsequence(s,len,temp,x+1,pushed+1);

    }


}

int main()
{
    string s;
    int len;
    cin>>s;
    len=s.length();
    char temp[len]={'\0'};
    subsequence(s,len,temp,0,0);

    return 0;
}
