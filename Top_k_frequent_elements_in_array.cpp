#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
  if (a.second == b.second)
  {
    return a.first > b.first;
  }
  return a.second > b.second;
}
vector<int> topk(vector<int> &nums, int k)
{
  unordered_map<int, int> m;
  for (int i = 0; i < nums.size(); i++)
  {
    m[nums[i]]++;
  }
  vector<pair<int, int>> v;
  vector<int> output;
  for (auto it = m.begin(); it != m.end(); it++)
  {
    v.push_back({it->first, it->second});
  }
  sort(v.begin(), v.end(), compare);
  for (int i = 0; i < k; i++)
  {
    output.push_back(v[i].first);
  }
  return output;
}
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      v.push_back(a);
    }
    int k;
    cin >> k;
    vector<int> output = topk(v, k);
    for (int i = 0; i < output.size(); i++)
    {
      cout << output[i] << " ";
    }
    cout << endl;
  }
}