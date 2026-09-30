class Solution {
public:
    int maxArea(vector<int>& nums) {
        int maxArea = INT_MIN;
        int n = nums.size();
        int st = 0; int end = n - 1;
        while(st < end){
            int ht = min(nums[st], nums[end]);
            int wd = end - st;
            maxArea = max(maxArea, ht * wd);
            if(nums[st] < nums[end]) st++;
            else end --;
        }
        return maxArea;
    }
};
