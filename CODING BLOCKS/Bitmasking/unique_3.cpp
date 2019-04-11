#include<iostream>
using namespace std;

int getithbit(int num,int pos)
{
     if((num&(1<<pos))==0)
        return 0;
     else return 1;
}


int main()
{
    int n,i,temp=0,t=32;        //t is number of bits ie 32 for int
    cin>>n;
    int ar[n],arcpy[n];
    for(i=0;i<n;i++)
        {
         cin>>ar[i];
         arcpy[i]=ar[i];
        }

    while(t--)
    {
        temp=0;
        for(i=0;i<n;i++)
            {
                if((ar[i]&(1<<(32-t)))!=0)
                temp++;
            }

        temp%=3;
        for(int j=0;j<n;j++)
            if(arcpy[j]!=NULL)
                if(getithbit(ar[j],32-t)!=temp)
                    {
                     arcpy[j]=NULL;     //array ki copy mei NULL karenge
                    }

    }

    for(i=0;i<n;i++)
        if(arcpy[i]!=NULL)      //required number will not be NULL
            cout<<ar[i];

    return 0;
}
