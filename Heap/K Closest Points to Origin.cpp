
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        // using lamba comparision for comaore func.
        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) 
        {
            return ((a.first * a.first) + (a.second * a.second)) < ((b.first * b.first) + (b.second * b.second));
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        for(auto x : points)
        {
            pq.push(make_pair(x[0], x[1]));
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
        vector<vector<int>> v;
        while(pq.size() > 0)
        {
            pair<int, int> top = pq.top();
            v.push_back(vector<int> {top.first, top.second});
            pq.pop();
        }
        
        return v;
    }
};
