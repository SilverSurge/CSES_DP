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
// #define int long long
#define endl '\n'

const int mod = 1e9 + 7;
// const int inf = LLONG_MAX;
// const int ninf = LLONG_MIN;
const double pi = 3.14159265359;
// priority_queue <int, vector<int>, greater<int> >

/*--------------start from here------------------*/

void solve()
{
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int dp[2][x + 1];
    memset(dp, 0, sizeof(dp));
    /*
    dp[i][j] -> getting sum j from  first i types of coins
    nottake = dp[i-1][j]
    int take = dp[i][j-c[i]];
    */
    for (int i = c[0]; i <= x; i += c[0])
        dp[0][i] = 1;
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i % 2][j] = dp[(i - 1) % 2][j];
            if (j - c[i] >= 0)
                dp[i % 2][j] += dp[i % 2][j - c[i]];
            dp[i % 2][j] %= mod;
        }
    }
    cout << dp[(n + 1) % 2][x] << endl;
}
/*
Everyone Contributed to the Assignment/Group Activity. No one was arrogant and condescending

Everyone was cooperative and we helped each other in their parts and also discussed the good things and flaws in their work

Everyone was focused and commited and tried their very best to do their roles.

Everyone did their role efficiently and if anyone lagged behind others were always the to back then up.

We know each other very well and there was no miscommunication and we all had meeting together


*/

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