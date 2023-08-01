class Solution {
public:
    int ans = 0;
    void merge(vector<int>& nums, int l , int mid , int r){
        for(int i = mid +1; i <= r ; i++){
            long long k = (long long)nums[i] *(2LL) +1;
            int ind = lower_bound(nums.begin()+l ,nums.begin()+mid+1 , k) - nums.begin() ;
            ans += (mid +1 - ind) ;
            // cout<< ans<<" ";
        }
        vector<int>temp;
        int i = l , j = mid+1;
        while(i <= mid && j <=r)
        {
            if(nums[i] <nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while( j <= r)
         {
             temp.push_back(nums[j]);
             j++;
         }
         i = 0;
         while(l <= r)
         {
             nums[l] =temp[i];
             i++, l++;
         }
    }
    void mergeSort( vector<int> &nums ,int i , int j){
        if(i == j)
            return ;
        int mid = (i +j)/2;
        mergeSort(nums,i , mid);
        mergeSort(nums ,mid+1 , j);
        merge(nums ,i , mid , j);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums ,0 , nums.size() -1);
        return ans;
    }
};