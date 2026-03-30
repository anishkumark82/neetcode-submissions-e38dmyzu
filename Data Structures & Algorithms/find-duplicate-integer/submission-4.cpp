class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // floyd's algorithm
        int slow = 0;
        int fast = 0;

        // Always expecting a cycle.
        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast == slow)
                break;
        }
        int slow2 = 0;
        while(slow2 != slow)
        {
            slow2 = nums[slow2];
            slow = nums[slow];
        }
        return slow;
    }
};
