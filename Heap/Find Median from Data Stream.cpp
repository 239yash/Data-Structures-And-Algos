class MedianFinder {
public:
    std::priority_queue<int, vector<int>, decltype([](const int& a, const int& b) {
        return a < b;
    })> firstHalf;
    std::priority_queue<int, vector<int>, decltype([](const int& a, const int& b) {
        return a > b;
    })> secondHalf;
    
    
    MedianFinder() {  
    }
    
    void addNum(int num) {
        if(firstHalf.empty() || (firstHalf.top() > num)) 
            firstHalf.push(num);
        else secondHalf.push(num); 
        
        if(firstHalf.size() > secondHalf.size() + 1) {
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }
        else if(firstHalf.size() + 1 < secondHalf.size()) {
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
    }
    
    double findMedian() {
        if (firstHalf.size() == secondHalf.size())
            return (firstHalf.top() + secondHalf.top()) / 2.00;
        else if (firstHalf.size() > secondHalf.size()) 
            return firstHalf.top();
        else return secondHalf.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0
