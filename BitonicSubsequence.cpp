#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001];
int solve()
{
    int left[1001], right[1001];
    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int x = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                x = max(x, left[j] + 1);
            }
        }
        left[i] = x;
    }

    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int x = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                x = max(x, right[j] + 1);
            }
        }
        right[i] = x;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, left[i] + right[i] - 1);
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solve() << endl;
    }
}