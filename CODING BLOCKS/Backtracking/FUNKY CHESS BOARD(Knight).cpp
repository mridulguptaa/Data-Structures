#include<bits/stdc++.h>
using namespace std;
int mat[10][10];

void chess(int mat[][10],int i,int j)       //(r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1)
{
    if(mat[i][j]==0 or mat[i][j]==-1 or i<0 or j<0 or i>=10 or j>=10) //out of scope or already visited;
        return ;
    if(mat[i][j]==1)
    {
    mat[i][j]=-1;   //visited
    chess(mat,i-2,j-1);
    chess(mat,i-2,j+1);
    chess(mat,i-1,j-2);
    chess(mat,i-1,j+2);
    chess(mat,i+1,j-2);
    chess(mat,i+1,j+2);
    chess(mat,i+2,j-1);
    chess(mat,i+2,j+1);
    }
}

int main()

{
    int size,cnt=0;
    cin>>size;
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            cin>>mat[i][j];

    chess(mat,0,0);

    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if(mat[i][j]==1)
                cnt++;

    cout<<cnt;
    return 0;
}
