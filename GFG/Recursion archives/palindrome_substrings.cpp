#include<bits/stdc++.h>
using namespace std;

bool palindromecheck(string s,int i,int j)
{
    for( ; i<=j;i++,j--)
        if(s[i]!=s[j])
            return false;
    return true;
}
void substring(string s,int length,int start)
{
    int i,j,k;
    for(i=0;i<length;i++)
        for(j=i;j<length;j++)
            if(palindromecheck(s,i,j))
            {   for(k=i;k<=j;k++)
                    cout<<s[k];
                cout<<" ";
            }

}

int main()
{
    string s;
    int len;
    cin>>s;
    for(len=0;s[len]!=NULL;len++);
    substring(s,len,0);
    return 0;
}
