class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fix = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[fix] != nums[i]){
                nums[fix+1] = nums[i];
                fix++;
            }
        }
        return fix+1;
    }
};
