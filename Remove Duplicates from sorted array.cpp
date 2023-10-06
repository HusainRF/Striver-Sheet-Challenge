class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0 , n= nums.size();
        for(int i = 0 ;i < nums.size() -1;i++){
            if(nums[i] != nums[i+1]){
                nums[j] = nums[i];
                j++;
            }
        }
        // if(nums[n-1] != nums[n-2])
            nums[j++]= nums[n-1];
        // cout<< j;
        return j;
    }
};