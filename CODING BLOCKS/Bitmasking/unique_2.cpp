#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,temp=0,num1=0,num2,cpy,pos;
    cin>>n;
    int ar[n+1];
    ar[0]=0;
    for(i=0;i<n;i++)
       {
            cin>>ar[i];
            temp=temp^ar[i];   //temp has xor of thsoe 2 numbers
        }
     cpy=temp;
     i=0;

     while(1)
     {
        if((cpy&1)!=0)
            {pos=i;
            break;
            }

         i++;
        cpy=cpy>>1;


     }


     for(i=0;i<n;i++)
        if((ar[i]&(1<<pos))!=0)
            num1^=ar[i];

     num2=temp^num1;
     if(num1<num2)
     cout<<num1<<" "<<num2;
     else cout<<num2<<" "<<num1;

    return 0;
}
