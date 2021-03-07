#include <bits/stdc++.h>
using namespace std;
bool hasArrayTwoCandidates(vector<int> &nums, int n, int x)
{
  unordered_map<int, int> m;
  for (int i = 0; i < nums.size(); i++)
  {
    m[nums[i]]++;
  }
  for (int i = 0; i < nums.size(); i++)
  {
    m[nums[i]]--;
    if (m.find(x - nums[i]) != m.end() && m[x - nums[i]] > 0)
    {
      return true;
    }
    m[nums[i]]++;
  }
  return false;
}
int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int n, x;
    cin >> n >> x;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
      int k;
      cin >> k;
      nums.push_back(k);
    }
    if (hasArrayTwoCandidates(nums, n, x) == true)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
}