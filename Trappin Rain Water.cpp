class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int>pri(n+1 , 0) ,suff(n+1 ,0);
        for(int  i= 0 ;i < n;i++)
            pri[i+1]  = max(pri[i] , h[i]);
        for(int i = n -1; i >= 0 ;i--)
            suff[i] = max(suff[i+1] , h[i]);
        int ans = 0;

        for(int i = 1 ;i < n - 1;i++){
            ans += max(min(pri[i], suff[i+1]) - h[i], 0);
        }
        return ans;


    }
};