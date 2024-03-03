# include<bits/stdc++.h>
using namespace std;

void median_stream(int arr[], int n)
{
    // s is max heap
    std::priority_queue<int> s;

    // g is min heap.
    std::priority_queue <int, vector<int>, greater<int>> g;

    s.push(arr[0]);
    cout<<arr[0]<<endl;

    for( int i = 1; i < n; i++)
    {
        int x = arr[i];

        //This loop will make the sizes of both queue same.
        //it goes in condition when, s.size > g.size
        //If s.top > x then add s.top in g and pop from s and add x in s
        if(s.size() > g.size())
        {
            if(s.top() > x)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
            {
                g.push(x);
            }

            //the sizes are same, so printing the median.
            cout<<((s.top() + g.top())/2.0)<<endl;  

        }
        else
        {
            if( x <= s.top())
            {
                s.push(x);
            }
            else
            {
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            cout<<s.top()<<endl;
        }
        
    }
}

int main()
{
    int arr[] = {12,15,10,5,8,17,16};
    median_stream(arr,7);
}
