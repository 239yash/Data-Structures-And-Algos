# include<bits/stdc++.h>
using namespace std;
void count_freq(int*,int);
void count_freq(int arr[], int n)
{
    std::unordered_map<int,int> freq;
    for(int i = 0;i<n;i++)
    {
        freq[arr[i]]++;
    }

    for(auto x:freq)
    {
        std::cout<<x.first<<" "<<x.second<<endl;
    }

}

int main()
{
    int arr[] = {10,10,10,20,20,40,50};
    int n = 7;
    count_freq(arr,n);
}
