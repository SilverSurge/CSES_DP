#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long int, long long int>
#define inf 1e15

int main()
{
    int n;
    cin >> n;
    if (n == 0)
        cout << 0 << endl;
    else if (n < 10)
        cout << 1 << endl;
    else
    {
        vector<int> dp(n + 1);
        for (int i = 1; i < 10; i++)
            dp.at(i) = 1;
        for (int i = 10; i <= n; i++)
        {
            int temp = INT_MAX;
            int a = i;
            while (a)
            {
                if (a % 10)
                {
                    temp = min(temp, dp.at(i - a % 10) + 1);
                }
                a /= 10;
            }
            dp.at(i) = temp;
        }
        cout << dp.at(n) << endl;
    }
    return 0;
}