#include <bits/stdc++.h> 
int maximumProfit(vector<int> &p){
    // Write your code here.
 int ans = 0;
        int mn = p[0] , n = p.size();

        for(int i = 1 ;i < n ;i++){
            if(mn < p[i]){
                ans = max(ans , p[i] - mn);
            }
            else {
                mn = p[i];
            }
        }
        return ans;
}