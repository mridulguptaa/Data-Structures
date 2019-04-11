#include<bits/stdc++.h>
using namespace std;
char tempar[100];
int temp=0,flag=0;


void print()
{
    cout<<tempar<<endl;
    flag++;
}

int sumfindkaro(char ar[],int sum,int n,int p)
{
    if(temp==sum)
    {
        print();
        return 0;

    }
    for(int i=p;i<n;i++)
    {
        if((temp+int(ar[i])-48)<=sum)
        {   temp=temp+int(ar[i])-48;
            tempar[p]=ar[i];
            sumfindkaro(ar,sum,n,p+1);
        }
        else tempar[p-1]='0';
    }


}

int main()
{
    int n,sum;
    cin>>n;
    char ar[n];     //n is number pf elements
    for(int i=0;i<n;i++)
        cin>>ar[i];
    cout<<"enter Sum \n";
    cin>>sum;
    sumfindkaro(ar,sum,n,0);
    if(flag==0)
        cout<<"No possible combination";
    return 0;



}
