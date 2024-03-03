class Solution {
public:
    int maxEvents(vector<vector<int>>& arr) {
        int n = arr.size();
        int lastDay = 0;
        sort(arr.begin(),arr.end());

        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
            lastDay = max(lastDay, arr[i][1]);
        int i = 0; 
        int ans = 0;
        
        
        for(int d = 1; i <= lastDay + 1; d++) {
            while(pq.size() && pq.top()<d)
                pq.pop();
            while(i < n && arr[i][0] == d) {
             pq.push(arr[i][1]);
             i++;
            }
            if(pq.size() && pq.top() >= d) {
             pq.pop();
             ans++;
            }
            if(pq.size() == 0 && i == n) {
             break;
            }
        }
        return ans;
    }
};





// You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

// You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

// Return the maximum number of events you can attend.

 

// Example 1:


// Input: events = [[1,2],[2,3],[3,4]]
// Output: 3
// Explanation: You can attend all the three events.
// One way to attend them all is as shown.
// Attend the first event on day 1.
// Attend the second event on day 2.
// Attend the third event on day 3.
// Example 2:

// Input: events= [[1,2],[2,3],[3,4],[1,2]]
// Output: 4
