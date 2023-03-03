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

class SegmentTree
{
private:
    int n;
    vector<int> stree;

public:
    vector<int> base;
    SegmentTree(int n)
    {
        // take the base array from outside
        base = vector<int>(n);
        stree = vector<int>(4 * n);
        this->n = n;
        // build(0, n-1, 1);
    }

    void init()
    {
        // build();
    }

    // combine function
    int combine(const int &a, const int &b)
    {
        return max(a, b);
    }

    // overloaded build
    void build()
    {
        build(0, n - 1, 1);
    }
    void build(int tl, int tr, int idx)
    {
        if (tl == tr)
        {
            stree.at(idx) = base.at(tl);
        }
        else
        {
            int tm = tl + (tr - tl) / 2;
            build(tl, tm, 2 * idx);
            build(tm + 1, tr, 2 * idx + 1);
            stree.at(idx) = combine(stree.at(2 * idx), stree.at(2 * idx + 1));
        }
    }

    // overloaded update
    void update(int pos, int val)
    {
        update(0, n - 1, 1, pos, val);
    }
    void update(int tl, int tr, int idx, int pos, int val)
    {
        if (tl == tr)
            stree.at(idx) = max(val, stree.at(idx));
        else
        {
            int tm = tl + (tr - tl) / 2;
            if (pos <= tm)
                update(tl, tm, 2 * idx, pos, val);
            else
                update(tm + 1, tr, 2 * idx + 1, pos, val);
            stree.at(idx) = combine(stree.at(2 * idx), stree.at(2 * idx + 1));
        }
    }

    // overloaded query
    int query(int l, int r)
    {
        return query(0, n - 1, 1, l, r);
    }
    int query(int tl, int tr, int idx, int l, int r)
    {
        if (l > r)
            return 0;
        else if (tl == l && tr == r)
            return stree.at(idx);
        int tm = tl + (tr - tl) / 2;
        return combine(query(tl, tm, 2 * idx, l, min(r, tm)), query(tm + 1, tr, 2 * idx + 1, max(l, tm + 1), r));
    }
};
struct project
{
    int a, b, p;
};
bool cmp(const project &p1, const project &p2)
{
    return p1.b < p2.b;
}
void solve()
{
    int n;
    cin >> n;
    vector<project> v(n);
    vector<int> cc;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].a >> v[i].b >> v[i].p;
        cc.push_back(v[i].a);
        cc.push_back(v[i].b);
        // cc.push_back(v[i].p);
    }
    sort(v.begin(), v.end(), cmp);
    // debug(v);
    sort(cc.begin(), cc.end());
    for (int i = 0; i < n; i++)
    {
        v[i].a = lower_bound(cc.begin(), cc.end(), v[i].a) - cc.begin();
        v[i].b = lower_bound(cc.begin(), cc.end(), v[i].b) - cc.begin();
    }

    SegmentTree stree(2 * n);
    stree.init();
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        int val = stree.query(0, v[i].a - 1);
        dp[i] = val + v[i].p;
        stree.update(v[i].b, dp[i]);
    }
    int ans = 0;
    for (const int &num : dp)
        ans = max(ans, num);
    cout << ans << endl;
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