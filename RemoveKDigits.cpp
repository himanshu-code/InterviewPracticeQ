#include <bits/stdc++.h>
using namespace std;
string removeKDigits(string &num, int k)
{
  if (num.length() <= k)
    return "0";
  int n = num.length();
  stack<char> s;
  for (auto c : num)
  {
    while (k > 0 and !s.empty() && c < s.top())
    {
      s.pop();
      k--;
    }
    if (!s.empty() or c != '0')
    {
      s.push(c);
    }
  }
  while (!s.empty() and k--)
  {
    s.pop();
  }
  if (s.empty())
  {
    return "0";
  }
  string str = "";
  while (!s.empty())
  {
    str.push_back(s.top());
    s.pop();
  }
  reverse(str.begin(), str.end());
  return str;
}
int main()
{
  string num;
  int k;
  cin >> num;
  cin >> k;
  cout << removeKDigits(num, k);
}