//Tavas and Saddas Bitmasking
#include<iostream>
#include<math.h>
using namespace std;

int length(int num)
{
    int len=0;
    while(num!=0)
    {
        num/=10;
        len++;
    }

    return len;
}
/*
bool compare(int num,int tempnum)
{
    if(tempnum<num)
        return true;
    else return false;
}

int permutate(int i,int num,int *ar,int len,int &ans)
{
    int tempnum=0,j=0;
    while(len--)
    {
        if((i&1)!=0)
            tempnum=tempnum*10+ar[j];
        j++;
        i>>1;
    }

    if(compare(num,tempnum))
        ans++;
    return ans;

}
*/

int main()
{
    int num,numcpy,len,i=0,ans=0;
    cin>>num;
    numcpy=num;
    len=length(num);
    int *ar=new int[len];
    do                      //array mei number dalwayenge
    {
        ar[i]=numcpy%10;
        numcpy/=10;
        i++;
    }while(numcpy!=0);


    /*for(i=1;i<pow(2,len);i++)
        ans=permutate(i,num,ar,len,ans);
    cout<<endl<<"ans is"<<ans+1;*/

    for(i=0;i<len;i++)
        {
         if(ar[i]==4)
            ans+=pow(2,i);
         else if(ar[i]==7)
            ans+=pow(2,i+1);
        }
    cout<<ans;
    delete []ar;
    return 0;

}
