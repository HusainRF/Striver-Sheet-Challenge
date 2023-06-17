#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &mat)
{
	// Write your code here.
	       int n = mat.size();
        int m = mat[0].size();
        int col = 1;
        for(int i = 0 ;i < n ;i++){
            for(int j = 0 ;j < m ; j++){ 
                if(!mat[i][j]){
                    if(i == 0 ){
                        col = 0;
                    }
                    else 
                        mat[i][0] = mat[0][j] = 0; 
                }
            }
        }

        for(int i = n-1 ;i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                if(i == 0 ){
                    if(!col)
                        mat[i][j] = 0;
                }
                if(j == 0){
                    if(mat[0][j] == 0)
                        mat[i][j] = 0;
                }
                if(j!=0 && i!=0 && (!mat[i][0] || !mat[0][j]))
                    mat[i][j] = 0   ;
            }
        }
}