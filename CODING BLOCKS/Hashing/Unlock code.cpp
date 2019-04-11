#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b)
{
    return a>b;
}
int main()
{
    int k,i,len;
    cin>>len>>k;
    char s[len],v[len];
    for(int i=0;i<len;i++)
        {cin>>s[i];
         v[i]=s[i];
        }
    sort(v,v+len,compare);
    unordered_map<char,int>m;

    for(i=0;i<len;i++)
    {
        m[s[i]]=i;

    }


    for(i=0;i<len&&k>0;i++)
    {
        if(s[i]==v[i])
            continue;

        else
        {
            //cout<<"Swapping "<<s[i]<<" with "<<s[m[v[i]]]<<endl;
            char c=s[i];
            s[i]=s[m[v[i]]];   //swapping
            s[m[v[i]]]=c;

            for(int j=0;j<len;j++)
                m[s[j]]=j;
            k--;
        }
    }
    for(i=0;i<len;i++)
        cout<<s[i]<<" ";
    return 0;
}


