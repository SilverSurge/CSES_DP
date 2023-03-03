#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v.at(i);
    vector<int> dp(s + 1, 0);
    dp.at(0) = 0;
    // cout<<INT_MAX<<endl;
    for (int i = 1; i <= s; i++)
    {
        int temp = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i - v.at(j) >= 0 && dp.at(i - v.at(j)) != INT_MAX)
            {
                temp = min(temp, dp.at(i - v.at(j)) + 1);
            }
        }
        // cout<<temp<<endl;
        dp.at(i) = temp;
    }
    if (dp.at(s) != INT_MAX)
        cout << dp.at(s) << endl;
    else
        cout << -1 << endl;

    return 0;
}