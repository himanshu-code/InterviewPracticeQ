#include <bits/stdc++.h>
using namespace std;
void Unique()
{
    char a[1000001];
    cin >> a;
    int lastIndex[26] = {0};
    bool presentInStack[26] = {0};
    for (int i = 0; a[i] != '\0'; i++)
    {
        lastIndex[a[i] - 'a'] = i;
    }
    stack<char> s;
    for (int i = 0; a[i] != '\0'; i++)
    {
        char ch = a[i];
        if (!presentInStack[ch - 'a'])
        {
            while (!s.empty() and ch < s.top() and lastIndex[s.top() - 'a'] > i)
            {
                presentInStack[s.top() - 'a'] = false;
                s.pop();
            }
            s.push(ch);
            presentInStack[ch - 'a'] = true;
        }
    }
    int k = s.size();
    char *ans = new char[k + 1];
    ans[k--] = '\0';
    while (!s.empty())
    {
        ans[k] = s.top();
        s.pop();
        k--;
    }
    cout << ans << endl;
}
int main()
{
    Unique();
}