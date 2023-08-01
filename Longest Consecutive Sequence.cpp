class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size() , ans = 0;
        // if(n == 0)
        for(int i = 0 ;i < n;i++)
            st.insert(nums[i]);

        for(auto itr : st){
            if(st.count(itr -1))
                continue;
            int l = 1;
            int x = itr +1;
            while(st.count(x))
            {
                l++;
                x++;
            }
            ans = max(ans , l);
        }
        return ans;
    }
};