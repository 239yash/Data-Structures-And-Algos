class Solution {
public:
    struct myComp {
        constexpr bool operator()(
            pair<int, int> const& a,
            pair<int, int> const& b)
            const noexcept
        {
            return a.second > b.second;
        }
    };
  
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::unordered_map<int, int> m;
        for(auto x : arr) m[x]++;
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
        for(auto x : m) 
            pq.push(make_pair(x.first, x.second));
        while(k) {
            pair<int, int> p = pq.top();
            if(p.second <= k) {
                k = k - p.second;
                pq.pop();
            } else {
                return pq.size();
            }
        }
        
        return pq.size();
    }
    
};
