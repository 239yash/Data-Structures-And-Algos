class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int maj = nums[0];
        int count = 1;
        int i = 1;
        
        while(i < nums.size())
        {
            if(nums[i] == maj)
                count++;
            else
                count--;
            
            if(count == 0)
            {
                maj = nums[i];
                count = 1;
            }
            
            i++;
        }
        
        return maj;
    }
};

// Loop through each element and maintains a count of majority element, and a majority index, maj_index
// If the next element is same then increment the count if the next element is not same then decrement the count.
// if the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
// Now again traverse through the array and find the count of majority element found.
// If the count is greater than half the size of the array, print the element
// Else print that there is no majority element
