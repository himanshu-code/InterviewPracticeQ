#include <bits/stdc++.h>
using namespace std;
int SubArraySum(int *arr, int n, int k)
{
    int *sum = new int[n + 1];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x += arr[i];
        sum[i] = x;
    }
    deque<pair<int, int>> q;
    q.push_back({0, -1});
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() and sum[i] - q.front().first >= k)
        {
            ans = min(ans, i - q.front().second);
            q.pop_front();
        }
        while (!q.empty() && sum[i] < q.back().first)
        {
            q.pop_back();
        }
        q.push_back({sum[i], i});
    }
    if (ans == INT_MAX)
        return -1;

    return ans;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << SubArraySum(arr, n, k);
    cout << endl;
    return 0;
}