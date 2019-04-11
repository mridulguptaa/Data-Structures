#include<bits/stdc++.h>
using namespace std;
char ar[1000][1000];
int countt=0;

void print(char ar[][1000],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            cout<<ar[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl<<endl;
}

int RatInMaze(char ar[][1000],int row,int col,int m,int n)     //m for rows....n for cols
{
    //base case
    if(m==row-1 && n==col-1)
    {
        print(ar,row,col);
        countt++;
        return 1;
    }
    //recursive call
    if(ar[m][n+1]!='X' && m<row && n<col)     //move right
    {
        ar[m][n+1]='1';
        RatInMaze(ar,row,col,m,n+1);
        ar[m][n+1]='O';     //backtrack
    }
    if(ar[m+1][n]!='X' && m<row && n<col)     //move down
    {
        ar[m+1][n]='1';
        RatInMaze(ar,row,col,m+1,n);
        ar[m+1][n]='O';     //backtrack
    }

    return 0;
}


int main()
{
    int row,col;
    cin>>row>>col;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>ar[i][j];  //maze entered
    ar[0][0]='1';
    RatInMaze(ar,row,col,0,0);
    cout<<countt<<" ways in total";


    cout<<ar[5][3];


    return 0;
}
