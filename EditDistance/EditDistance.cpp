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
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size(), m = t.size();
    /*
    dp[i][j]
    edit distance for substrings with prefixes
    of length i and j from s and t respectively

    */
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int i = 1; i <= m; i++)
        dp[0][i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                int tmp = inf;
                // add on s OR replace on t
                tmp = min(tmp, dp[i][j - 1] + 1);
                // remove on s OR add on t
                tmp = min(tmp, dp[i - 1][j] + 1);
                // replace on s OR replace on t
                tmp = min(tmp, dp[i - 1][j - 1] + 1);
                dp[i][j] = tmp;
            }
        }
    }
    cout << dp[n][m] << endl;
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

