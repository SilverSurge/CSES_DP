#include <bits/stdc++.h>
using namespace std;
typedef int int32_t;
#define int long long int
#define endl '\n'
int mod = 1e9+7;
vector<vector<int>> MatrixMultiplication(const vector<vector<int>> &a, const vector<vector<int>> &b)
{
    int m1 = a.size(), n1 = a[0].size(), m2 = b.size(), n2 = b[0].size();
    vector<vector<int>> tmp;
    if(n1 != m2) return tmp;
    vector<vector<int>> c(m1,vector<int>(n2));
    for (auto j = 0; j < n2; ++j)
    {
        for (auto k = 0; k < n1; ++k)
        {
            for (auto i = 0; i < m1; ++i)
            {
                // c[i][j] += a[i][k] * b[k][j];
                c[i][j] = (c[i][j]%mod +  (a[i][k]%mod * b[k][j]%mod)%mod)%mod;
            }
        }
    }
    return c;
}
 
vector<vector<int>> BinaryMatrixExponentiation(vector<vector<int>> &m,int n)
{
    vector<vector<int>> result(m.size(),vector<int>(m.size(),0));
    for(int i=0;i<m.size();i++)
    {
        result[0][0] = 1;
    }
 
    while(n>0)
    {
        if(n % 2 ==1)
            result=MatrixMultiplication(result,m);
        m=MatrixMultiplication(m,m);
        n=n/2;
    }
    return result;
}
int32_t main()
{
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // ..........................//
    
    int tests = 1;
    // cin>>tests;
    int mod = 1e9+7;
    
    for(int test = 1;test<=tests;test++)
    {
        int n;
        cin>>n;
        vector<vector<int>> m(6,vector<int>(6,0));
 
        for(int i=0;i<6-1;i++)
        {
            m[i][i+1] = 1;
        }
        for(int i=0;i<6;i++)
        {
            m[5][i] = 1;
        }
 
        vector<vector<int>> tmp = BinaryMatrixExponentiation(m,n-1);
        int ans = 0;
        vector<int> base(6);
        base[0] = 1;
        base[1] = 2;
        base[2] = 4;
        base[3] = 8;
        base[4] = 16;
        base[5] = 32;
 
        for(int i=0;i<6;i++)
        {
            ans = (ans + (tmp[0][i]%mod * base[i]%mod)%mod)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;


int main()
{


    ll int x = 1e6+2,dp[x] ;
    int p = 1;
    for(int i = 1;i<=6;i++)
    {
        dp[i] = p;
        p*=2;
    }
    int n;
    cin>>n;
    ll int m = 1e9 + 7;
    for(int i = 7;i<=n;i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6])%m;
    }
    cout<<dp[n]<<endl;

    return 0;
}

*/