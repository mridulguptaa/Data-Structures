#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2,string s3,int len1,int len2,int len3)
{
   int DP[len1+1][len2+1][len3+1];
   int i, j,k;

   for (i=0; i<=len1; i++)
   {
     for (j=0; j<=len2; j++)
     {
         for(k=0;k<=len3;k++)
       {
           if (i == 0 || j == 0||k==0)
            DP[i][j][k] = 0;

          else if (s1[i-1] == s2[j-1]&&s2[j-1]==s3[k-1])
                DP[i][j][k] = DP[i-1][j-1][k-1] + 1;

          else DP[i][j][k] = max(max(DP[i-1][j][k],DP[i][j-1][k]),DP[i][j][k-1]);
        }
     }


   }

   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return DP[len1][len2][len3];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    string s1,s2,s3;
    int len1,len2,len3;
    cin>>s1>>s2>>s3;
    len1=s1.length();
    len2=s2.length();
    len3=s3.length();
    cout<<LCS(s1,s2,s3,len1,len2,len3)<<endl;
    }
    return 0;

}

