int sb(int arr[], int n, int x)
{
  // Your code goes here
  // Variable Sized Sliding Window Problem

  int i = 0;
  int j = 0;
  int sum = 0;
  std::vector<int> v;
  while(j < n && i < n)
  {
      sum = sum + arr[j];
      if(sum > x)
      {
          v.push_back(j - i + 1);
          while(sum > x && i < n)
          {
              sum = sum - arr[i];
              i++;
              if(sum > x)
              {
                  v.push_back(j - i + 1);
              }
          }
      }

      j++;
  }

  return *min_element(v.begin(), v.end());
}
