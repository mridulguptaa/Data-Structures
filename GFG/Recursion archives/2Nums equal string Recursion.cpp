#include<bits/stdc++.h>
using namespace std;

int check(int num1,int num2)
{

    if(num1==num2 && num1!=0)
        cout<<endl<<num2;
}

int dhundo(char ar[],int n,int num1,int num2,int p)
{


    num1=0;
    for(int i=p;i<n-1;i++)
        {
            num1=num1*10+ar[i]-48;
            for(int j=i+1;j<n;j++)
            {
                num2=num2*10+ar[j]-48;
                check(num1,num2);

            }
            num2=0;

        }
    if(p<n-2)
    dhundo(ar,n,num1,num2,p+1);
    return 0;
}


int main()
{
    char ar[100];
    int i,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>ar[i];
    dhundo(ar,n,0,0,0);
}
