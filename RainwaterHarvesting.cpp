#include <bits/stdc++.h>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    if (n == 0)
        return 0;
    int *max_start, *max_end;
    max_start = new int[10000000];
    max_end = new int[10000000];
    max_start[0] = 0;
    for (int i = 1; i < n; i++)
    {
        max_start[i] = max(max_start[i - 1], height[i - 1]);
    }
    max_end[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        max_end[i] = max(max_end[i + 1], height[i + 1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int level = min(max_start[i], max_end[i]);
        if (level - height[i] > 0)
        {
            ans += level - height[i];
        }
    }
    return ans;
}
int trap2(vector<int> &height)
{
    int ans = 0, current = 0;
    stack<int> s;
    while (current < height.size())
    {
        while (!s.empty() && height[current] > height[s.top()])
        {
            int top = s.top();
            s.pop();
            if (s.empty())
                break;
            int distance = current - s.top() - 1;
            int boundedHeight = min(height[current], height[s.top()]) - height[top];
            ans += distance * boundedHeight;
        }
        s.push(current++);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;

    vector<int> height;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        height.push_back(num);
    }
    cout << trap(height) << endl;
    cout << trap2(height);
}