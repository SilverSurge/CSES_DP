#include <bits/stdc++.h>
#define modnum 1e9 + 7
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v.at(i);
    vector<int> dp(s + 1, 0);
    dp.at(0) = 1;
    for (int i = 1; i <= s; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (i - v.at(j) >= 0)
            {
                temp += dp.at(i - v.at(j));
                temp %= (1000000000 + 7);
            }
        }
        // cout<<temp<<endl;
        dp.at(i) = temp;
    }
    cout << dp.at(s) << endl;

    return 0;
}