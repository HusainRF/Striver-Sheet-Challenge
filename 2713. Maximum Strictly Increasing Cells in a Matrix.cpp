class Solution {
public:
// leetcode problme :2713. Maximum Strictly Increasing Cells in a Matrix
//idea is simple just store sorted row and col in a seprate matrix and also now perform dp which helps to
// to travel on the index mat[i_new , j_new] which is just bigger then the value of mat[i , j]
// here we observe that moving to just bigger vlaue than the current will give the most optimal ans 
 
    #define ff first
    #define ss second

    vector<vector<pair<int,int>>>srtrw , srtcol;
    vector<vector<int>>dp;
    int n , m;

    int dfs(vector<vector<int>>&mat, int i , int j ){
       
        if(dp[i][j] != -1)
            return dp[i][j];

        int ind1 = lower_bound(srtrw[i].begin() ,srtrw[i].end() ,  make_pair(mat[i][j] +1 , numeric_limits<int>::min())) - srtrw[i].begin();
        int ind2 = lower_bound(srtcol[j].begin() ,srtcol[j].end() , make_pair(mat[i][j] +1 , numeric_limits<int>::min())) - srtcol[j].begin();

        int poss1 = 0 , poss2 = 0 ;
        for( int k = ind1; k < m ; k++ ){
            // cout<< srtrw[i][ind1].ss <<" ";
            if(srtrw[i][ind1].ff != srtrw[i][k].ff)
                break;
            poss1 = max(dfs(mat , i , srtrw[i][k].ss) , poss1);
        }
        for(int k = ind2 ; k < n ; k++){
            // cout << ind2<<" ";
            if(srtcol[j][k].ff != srtcol[j][ind2].ff)
                break;
            poss2 = max(dfs(mat , srtcol[j][k].ss , j) , poss2);
        }
        return dp[i][j] = max(poss1 ,poss2) +1;

    }

    int maxIncreasingCells(vector<vector<int>>& mat) {
         n = mat.size() , m = mat[0].size();

        srtrw.resize(n , vector<pair<int , int>>(m ));
        srtcol.resize(m , vector<pair<int , int>>(n ));

        for(int i = 0 ;i < n; i++){
            for(int j = 0 ;j < m; j++){
                srtrw[i][j] = {mat[i][j] , j};
                srtcol[j][i] = {mat[i][j] , i} ;
            }
        }
        for(int i = 0 ;i < n; i++){
           sort(srtrw[i].begin() ,srtrw[i].end());
        }
        for(int i= 0 ; i < m;i++){
            sort(srtcol[i].begin() , srtcol[i].end());
        }
        
        dp.resize(n , vector<int>(m ,-1));
        int ans = 0;

        // for(int i = 0 ; i < m ;i++){
        //     for(int j = 0 ; j < n ;j++){
        //         cout<< srtcol[i][j].ff <<" ";
        //     }
        //     cout<< endl;
        // }

        for(int i = 0 ;i < n;i++){
            for(int j = 0 ;j < m; j++){
                if(dp[i][j] == -1){
                    ans = max( ans,dfs(mat ,i , j));
                }
            }
        }
        

        return ans;
    }
};