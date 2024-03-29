  int missingNumber(int arr[], int n) 
  {
      for(int i = 0; i < n; i++)
      {
          while(arr[i] >= 1 && arr[i] <= n-1 && arr[i] != arr[arr[i] - 1])
          {
              swap(arr[i], arr[arr[i] - 1]);
          }
      }

      for(int i = 0; i < n; i++)
      {
          if(i + 1 != arr[i])
          {
              return i + 1;
          }
      }

      return n + 1;
  } 
