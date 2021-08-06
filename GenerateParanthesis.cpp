#include <bits/stdc++.h>
using namespace std;
void generate(vector<string> &ans, string brackets, int open, int close, int max)
{
    if (brackets.length() == 2 * max)
    {
        ans.push_back(brackets);
    }
    if (close < open)
    {
        generate(ans, brackets + ")", open, close + 1, max);
    }
    if (open < max)
    {
        generate(ans, brackets + "(", open + 1, close, max);
    }
}
vector<string> generateParanthesis(int n)
{
    vector<string> ans;
    generate(ans, "", 0, 0, n);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> ans = generateParanthesis(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
}