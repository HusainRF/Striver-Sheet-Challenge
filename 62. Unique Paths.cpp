class Solution {
public:
    int uniquePaths(int n, int m) {
        int dp[n][m];
        dp[0][0] =1;
        for(int i = 0 ;i < n;i++)
            dp[i][0] = 1;
        for(int i = 0; i <m ; i++)
            dp[0][i] =1;
        
        for(int i = 1 ;i < n; i++){
            for(int j = 1 ;j < m ;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};