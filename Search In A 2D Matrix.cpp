bool searchMatrix(vector<vector<int>>& mat, int target) {
  
  int n = mat.size() , m = mat[0].size();
  int i = 0 , j = m-1 ;
  
  for(int k = 0 ; k < n ; k++){
      j = m-1 , i = 0;
      if(target <= mat[k][j])
      {
          while(i <= j){
              int mid = (i + j )/2;
              if(mat[k][mid] == target)
                return 1;
              else if(mat[k][mid] < target)
                 i = mid+1;
              else
                 j = mid-1;
          }
      }
  }       
  return 0;
}