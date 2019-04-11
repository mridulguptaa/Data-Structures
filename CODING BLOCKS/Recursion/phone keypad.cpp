#include<bits/stdc++.h>
using namespace std;

string number[10]={{'\0'},{'\0'},{"ABC"},{"DEF"},{"GHI"},{"JKL"},{"MNO"},{"PQRS"},{"TUV"},{"WXYZ"}};

void phonekeypad(string s,char temp[],int len,int in,int out)
{
    if(in>=len)
    {
        temp[out]='\0';
        cout<<temp<<endl;
        return;
    }
    int x;
    x=int(s[in])-48;
    if(x==0 || x==1)
        phonekeypad(s,temp,len,in+1,out);

    for(int j=0;number[x][j]!='\0';j++)
    {
        temp[out]=number[x][j];
        phonekeypad(s,temp,len,in+1,out+1);
    }

}

int main()
{
    string s;
    cin>>s;
    int len;
    len=s.length();
    char temp[len];
    phonekeypad(s,temp,len,0,0);

}
