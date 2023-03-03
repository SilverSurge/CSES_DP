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

void solve()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int dp[n][n][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[i][i][0] = v[i];
    for (int l = n; l >= 0; l--)
    {
        for (int r = l + 1; r < n; r++)
        {
            // for player 0
            dp[l][r][0] = max(dp[l + 1][r][1] + v[l], dp[l][r - 1][1] + v[r]);
            // for player 1
            dp[l][r][1] = min(dp[l + 1][r][0], dp[l][r - 1][0]);
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout << dp[i][j][0] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout << dp[i][j][1] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[0][n - 1][0] << endl;
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