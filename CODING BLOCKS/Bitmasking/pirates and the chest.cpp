#include<bits/stdc++.h>
using namespace std;

int hcf(int a,int b)
{
    if(b==0)
        return a;

    return hcf(b,a%b);
}

bool checkcoprime(int a,int b)
{
    if(hcf(a,b)==1)
        return true;
    else return false;
}

int findmax(int i,int keys,int maxkeys,int chests,int keyno[],int chestno[],int chestvalue[])
{
    int maxsum=0,cursum=0,k=0,j=0;
    while(i!=0 && k<maxkeys)
    {
        if(i&(1<<j)!=0)
        {
            for(int z=0;z<chests;z++)
            {
                if(!checkcoprime(keyno[j],chestno[z]))
                {
                    cursum+=chestvalue[z];
                    maxsum=max(maxsum,cursum);
                    k++;
                }
            }

        }

        i=i>>1;
        j++;
    }

    return maxsum;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int keys,chests,maxkeys,maxx;
        cin>>keys>>chests>>maxkeys;
        int *keyno=new int[keys],*chestno=new int[chests],*chestvalue=new int[chests];

        for(int i=0;i<keys;i++)
            cin>>keyno[i];
        for(int i=0;i<chests;i++)
            cin>>chestno[i];
        for(int i=0;i<chests;i++)
            cin>>chestvalue[i];

        for(int i=1;i<pow(2,keys);i++)
            maxx=max(findmax(i,keys,maxkeys,chests,keyno,chestno,chestvalue),maxx);

        cout<<maxx<<endl;

    }

    return 0;
}
