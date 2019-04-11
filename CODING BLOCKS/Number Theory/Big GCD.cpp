#include<bits/stdc++.h>
using namespace std;;

long long int stringtoint(string m,long long int n)
{
    long long int temp=0;
    for(int i=0;i<m.length();i++)
    {
        temp*=10;
        temp%=n;
        temp+=m[i]-'0';
        temp%=n;
    }
    return temp;

}
int main()
{
    long long int n;
    string m;
    cin>>n;
    cin>>m;
    if(stringtoint(m,n)==0)
    {
        cout<<n;
        return 0;
    }
    for(long long int i=n/2;i>=1;i--)
        if(stringtoint(m,i)==0)
        {
            cout<<i;
            return 0;
        }


    return 0;
}
