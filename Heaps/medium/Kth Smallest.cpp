class Solution
{
public:
    int findKthSmallest(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int> maxheap;
        for (int i = 0; i < n; i++)
        {
            maxheap.push(nums[i]);

            if (maxheap.size() > k)
                maxheap.pop();
        }
        return maxheap.top();
    }
};