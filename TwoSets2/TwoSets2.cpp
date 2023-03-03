/*----------------all header files-------*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

/*---------------Debugging Class Template------------------*/
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// os.insert(element)
// os.erase(element)
// os.find_by_order(k) {iterator to the k'th element 0 indexing}
// os.order_of_key(k) {count of elements smaller than k}

/*--------------------all defines----------------*/
#define int long long
#define endl '\n'

const int mod = 1e9 + 7;
const int inf = LLONG_MAX;
const int ninf = LLONG_MIN;
const double pi = 3.14159265359;
// priority_queue <int, vector<int>, greater<int> >

/*--------------start from here------------------*/
int ModularExponentiation(int x, int n, int M)
{
    int result = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            result = (result * x) % M;
        x = (x * x) % M;
        n = n / 2;
    }
    return result;
}
int ModuloInverse(int A, int M)
{
    // use only when M is a prime
    return ModularExponentiation(A, M - 2, M);
}

void solve()
{
    int n;
    cin >> n;
    if ((n * (n + 1)) % 4 != 0)
    {
        cout << 0 << endl;
        return;
    }
    int s = n * (n + 1) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(s / 2 + 1));
    // [n+1][s/2+1];
    // memset(dp, 0, sizeof(dp));
    int num;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        num = i;
        for (int j = 1; j <= s / 2; j++)
        {
            // from previous i
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            if (j == num)
                dp[i][j]++;
            if (j - num > 0)
                dp[i][j] += dp[i - 1][j - num];
            dp[i][j] %= mod;
        }
        // debug(dp);
    }

    cout << (dp[n][s / 2] * ModuloInverse(2, mod)) % mod << endl;
}

int32_t main()
{
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ..........................//

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tests = 1;
    // cin>>tests;
    for (int test = 1; test <= tests; test++)
    {
        // cout<<"Case "<<test<<": ";
        solve();
    }

    return 0;
}