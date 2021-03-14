# include<bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
    //Your code here
    if(N==1){
      return 1;
    }
    int m = 0, count = 1;
    sort(arr, arr+N);
    for(int i=1; i<N; i++){
        if(1 + arr[i-1] == arr[i]){
            count++;
        }else if(arr[i-1] == arr[i]){
            continue;
        }else{
            count = 1;
        }
        m = max(count, m);
    }
    return m;
}


int main()
{
    int arr[] = {8,20,7,30};
    int n = 4;
    findLongestConseqSubseq(arr,n);
}
