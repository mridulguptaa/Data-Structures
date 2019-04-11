#include<bits/stdc++.h>
using namespace std;

void  pushinheap(vector<int>&v,int index,int a)
{
    v.push_back(a);
    index=v.size()-1;
    int parent=index/2;
    while(index>1 and v[parent]>v[index])
    {
        swap(v[parent],v[index]);
        index=parent;
        parent=parent/2;
    }
}
bool cmp(int a,int b)
{
    return a>b;
}
void heapify(vector<int>&v,int index)
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

				if(minIndex!=index){
						swap(v[index],v[minIndex]);
						heapify(v,minIndex);
				}
				return;
		}
int main()
{
    vector<int>v;
    v.reserve(100);
    v.push_back(-1);    //block first box
    int a,index=0;
    cin>>a;
    while(a!=-1)
    {
        pushinheap(v,index,a);
        cin>>a;
    }

    for(int i=1;i<v.size();i++)
        cout<<v[i]<<" ";
    index=v.size()-1;
    swap(v[1],v[index]);
    v.pop_back();

    heapify(v,1);
    cout<<endl;

    for(int i=1;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}
