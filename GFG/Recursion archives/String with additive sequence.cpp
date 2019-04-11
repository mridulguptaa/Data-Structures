#include<bits/stdc++.h>
using namespace std;
int i,j,k;
int dhoondo(char ar[],int n,int num1,int num2,int strleft,int p)
{

    if(num1+num2==strleft)
        {
            cout<<endl<<num1<<"+"<<num2<<"="<<strleft<<endl;
            return 0;

        }
    if(p==n)            //21113
        return 0;


    for(i=0;i<n/2;i++)

       for(j=i+1;j<=(n-i)/2;j++)
           {
                strleft=strleft*10+ar[p]-48;
                dhoondo(ar,n,num1,num2,strleft,p+1);
            }

       num2=num2*10+ar[j]-48;


}

int main()
{
    char ar[100]={0};
    int ii,n;
    cin>>n;
    for(ii=0;ii<n;ii++)
        cin>>ar[ii];
    dhoondo(ar,n,ar[0]-48,ar[1]-48,0,2);

}
