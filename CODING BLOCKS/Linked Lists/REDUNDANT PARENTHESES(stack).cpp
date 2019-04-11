#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    stack<char>st;
    while(t--)
    {
        string s;
        cin>>s;
        int len=s.length(),flag2=0;
        int i=0;
        while(i<len)
        {
            if(s[i]!=')')
                st.push(s[i]);
            if(s[i]==')')
            {
               int flag=0;
               while(1)
               {
                   if(st.top()!='(')
                        {st.pop();
                         flag++;
                        }
                   if(st.top()=='(')
                   {
                       st.pop();
                       break;
                   }

               }
               if(flag==0)
               {cout<<"Duplicate"<<endl;
                flag2++;
                break;
               }
            }
            i++;
        }
        if(flag2==0)
            cout<<"Not Duplicates"<<endl;
    }
    return 0;
}
