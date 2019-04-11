#include<bits/stdc++.h>
using namespace std;

void print(int**ar,int k,int n)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
            cout<<ar[i][j]<<" ";
        cout<<endl;
    }

}
bool cmp(int a,int b)
{
    return a>b;
}

void heapify(vector<int>&v,int index,int&temp)
{

				int left = 2*index;
				int right = left+1;

				int minIndex = index;
				if(left<v.size() and cmp(v[index],v[left])){
					minIndex = left;
				}
				if(right<v.size() and cmp(v[minIndex],v[right])){
					minIndex = right;
				}

    if(v[temp]>v[minIndex])
        temp=minIndex;

				if(minIndex!=index){
						swap(v[index],v[minIndex]);
						heapify(v,minIndex,temp);
				}
				return;
}

findsmallestwalekaindex(vector<int>&v,int n,int k,int&temp)
{
    for(int i=n/2;i>0;i--)
        heapify(v,i,temp);

}

void mergearrays(int n,int k,int*variables,int**ar,vector<int>&v,int ans[])
{
    int z=0;
    for(int i=0;i<k;i++)
    {
        v.push_back(ar[i][0]);
    }
    while(z<k*n)
    {
        int temp=n/2;
        findsmallestwalekaindex(v,n,k,temp);  //temp will contain the array jisme sabse chhota tha
        ans[z++]=v[1];
        //now remove smallest from heap
        swap(v[1],v[k]);
        v.pop_back();
        v.push_back(ar[temp][variables[temp]]);
        variables[temp]+=1;
    }
}
int main()
{
    int n,k,j;
    cin>>k>>n;
    int ans[k*n];
    int**ar=new int*[k];
    int variables[k];       //itne vairiables chahiye
    for(int i=0;i<k;i++)
    {
        ar[i]=new int[n+1];
        for(j=0;j<n;j++)
            cin>>ar[i][j];
        ar[i][j]=INT_MAX;
        variables[i]=1;
    }
    //print(ar,k,n);
    vector<int>v;       //k size ke liye heap banayenge
    v.reserve(k+1);
    v.push_back(-1);
    mergearrays(n,k,variables,ar,v,ans);

    for(int p=0;p<k*n;p++)  //print sorted merged arrays.
        cout<<ans[p]<<" ";

    //delete the arrays.
    for(int i = 0; i <k; ++i)
    {
    delete []ar[i];
    }
    delete [] ar;
    return 0;
}
