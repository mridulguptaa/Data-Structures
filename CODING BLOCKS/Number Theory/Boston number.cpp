#include "bits/stdc++.h"
using namespace std;

#define MAXN   100001

// stores smallest prime factor for every number
long long int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (long long int i=2; i<MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (long long int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (long long int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (long long int j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<long long int> getFactorization(long long int x)
{
    vector<long long int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

// driver program for above function
 int main(long long int argc, char const *argv[])
{
    // precalculating Smallest Prime Factor
    sieve();
    long long int x;
    cin>>x;
    long long int ans1=0,ans2=0;
    //cout << "prime factorization for " << x << " : ";

    // calling getFactorization function
    vector <long long int> p = getFactorization(x);

    for (long long int i=0; i<p.size(); i++)
        ans1+=p[i];
    //find sum of digits
    while(x!=0)
    {
        ans2+=x%10;
        x/=10;
    }
    if(ans1==ans2)
        cout<<"1";
    else cout<<"0";
    return 0;
}
