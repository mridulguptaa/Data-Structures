#include<bits/stdc++.h>
using namespace std;

bool check(string s)
{
    stack<char>st;
    for(long long int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
            st.push(s[i]);
        if(s[i]==')')
            if(st.empty())
                return false;
            st.pop();
    }
    if(st.empty())
        return true;
    return false;
}
int main()
{
    string s;
    cin>>s;
    if(check(s))
        cout<<"Yes";
    else cout<<"No";
    return 0;
}
