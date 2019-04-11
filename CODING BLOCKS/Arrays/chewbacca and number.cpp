#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int i,len=0;
    len=s.length();
    if(s[0]!='9')
    {
        if(s[0]=='9')
            s[0]='0';
        else if(s[0]=='8')
            s[0]='1';
        else if(s[0]=='7')
            s[0]='2';
        else if(s[0]=='6')
            s[0]='3';
        else if(s[0]=='5')
            s[0]='4';
    }
    for(i=1;i<len;i++)
    {
        if(s[i]=='9')
            s[i]='0';
        else if(s[i]=='8')
            s[i]='1';
        else if(s[i]=='7')
            s[i]='2';
        else if(s[i]=='6')
            s[i]='3';
        else if(s[i]=='5')
            s[i]='4';
    }

    cout<<s<<endl;

    return 0;
}
