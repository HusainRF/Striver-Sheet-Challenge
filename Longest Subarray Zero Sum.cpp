#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    int ans = 0 , n = arr.size();
    unordered_map<int,  int> mp;
    int sum = 0;
    for(int i = 0 ;i < n;i++){
      sum += arr[i];
      if(sum == 0)
        ans = i+1;
      else if(mp.count(sum)){
        ans =  max(ans ,i - mp[sum]);
      }
      else {
        mp[sum] = i;
      }
    }
    return ans;
}