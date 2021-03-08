#include <bits/stdc++.h>
using namespace std;
string reverseEqn(string s)
{
  stack<string> st;
  int l = s.length();
  string s1;
  for (int i = 0; i < l; i++)
  {
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
    {
      st.push(s1);
      s1 = "";
      s1 = s1 + s[i];
      st.push(s1);
      s1 = "";
    }
    else
    {
      s1 = s1 + s[i];
    }
  }
  st.push(s1);
  s1 = "";
  while (st.size() != 0)
  {
    s1 = s1 + st.top();
    st.pop();
  }
  return s1;
}
int main()
{
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {
    string s;
    cin >> s;
    string output = reverseEqn(s);
    cout << output << endl;
  }
}