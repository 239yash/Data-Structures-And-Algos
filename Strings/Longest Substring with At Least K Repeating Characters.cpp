int longestSubstring(string s, int k)
{
  int n = s.size();
  if(n == 0 || n < k)
  {
      return 0;
  }

  if(k <= 1)
  {
      return n;
  }

  unordered_map<char, int> m;
  for(auto x : s) m[x]++;

  int i = 0;
  while(i < n && m[s[i]] >= k)
  {
      i++;
  }

  if(i >= n-1)
  {
      return i;
  }

  int ls1 = longestSubstring(s.substr(0,i), k);
  while(i < n && m[s[i]] < k) i++;
  int ls2 = longestSubstring(s.substr(i), k);

  return max(ls1, ls2);
}
