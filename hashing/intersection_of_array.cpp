# include<bits/stdc++.h>
using namespace std;
void count_inters(int*,int*,int,int);
void count_inters(int arr1[], int arr2[],int n,int m)
{
    std::set<int> set_a;
    std::set<int> set_b;
    std::unordered_map<int,int> freq;
    int count = 0;
    std::set<int> :: iterator itr1;
    std::set<int> :: iterator itr2;



    for(int i =0;i<n;i++)
    {
        set_a.insert(arr1[i]);
    }

    for(int j =0;j<m;j++)
    {
        set_b.insert(arr2[j]);
    }


    for(itr2 = set_a.begin();itr2!=set_a.end();++itr2)
    {
        freq[*itr2]++;
    }


    for(itr1 = set_b.begin();itr1!=set_b.end();++itr1)
    {
        freq[*itr1]++;
    }



    for(auto x:freq)
    {
        if(x.second == 2)
        count++;
    }

   cout<<count;

}


int main()
{
    int arr1[] = {10,15,20,15,30,30,5};
    int arr2[] = {30,5,30,80};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);


    count_inters(arr1,arr2,n,m);
}
