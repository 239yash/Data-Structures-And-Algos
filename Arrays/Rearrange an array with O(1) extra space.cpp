void arrange(long long arr[], int n) {
    // Your code here
    for (int i = 0; i < n; i++)
        arr[i] += (arr[arr[i]] % n) * n;
    
    // for(int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";

    for (int i = 0; i < n; i++)
        arr[i] /= n;
    
}
