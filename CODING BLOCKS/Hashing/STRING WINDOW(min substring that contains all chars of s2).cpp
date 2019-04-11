#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    unordered_map<char,int>m;
    unordered_map<char,int>temp;
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<s2.length();i++)
        m[s2[i]]++;     //saved jo bi string 2 mei hai
    vector<char>v;
    char zzz[10000],start;
    int minsize=s1.length(),milgye=0;

    for(int i=0;i<s1.length();i++)
    {
        v.push_back(s1[i]);
        if(m[s1[i]]>temp[s1[i]])    //chahiye
        {
            milgye++;
        }
        temp[s1[i]]++;


        if(milgye==s2.length())
        {
            start=v.front();
            while(m[start]==0 or m[start]<temp[start])
            {
                temp[start]--;
                //cout<<temp[start]<<" ";

                v.erase(v.begin());
                start=v.front();
            }

            if(v.size()<minsize)
              {
                 minsize=v.size();
                 for(int p=0;p<minsize;p++)
                    zzz[p]=v[p];
              }
        }
    }

    for(int j=0;j<minsize;j++)
        cout<<zzz[j];
    return 0;
}


