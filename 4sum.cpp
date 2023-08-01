class Solution {
public:


    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
     
        sort(nums.begin() , nums.end());
        
        set<vector<int>> ans;

        for(int i = 0 ;i < n - 3 ;i++){
            for(int j = i+1 ;j < n-2 ;j++){
                    int l = j+1 , r = n-1;
                    long long f =  (long long)nums[i] + (long long)nums[j];
                    while(l < r){
                        long long sum = (long long)nums[l] + (long long)nums[r] + f;
                        if(sum == target){
                            ans.insert({nums[i] , nums[j] , nums[l] , nums[r]});
                            l++, r--;
                        }
                        else if(target > sum)
                            l++;
                        else 
                            r--;
                    }
            }
        }

        return {ans.begin(),ans.end()};
    }
};