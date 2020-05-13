
# include<bits/stdc++.h>
using namespace std;


int knapsack(int w, int wt[], int val[], int n)
{
    if(n == 0 || w == 0)
    {
        return 0;
    }

    if(wt[n-1] > w)
    {
        return knapsack(w,wt,val,n-1);
    }
    else
    {
        return max(knapsack(w,wt,val,n-1) , val[n-1] + knapsack(w-wt[n-1],wt,val,n-1));
    }



}
int main()
{
    int w = 10;
    int wt[] = {5,4,6,3};
    int val[] = {10,40,30,50};
    int n = 4;

    cout<<knapsack(w,wt,val,n);
}
