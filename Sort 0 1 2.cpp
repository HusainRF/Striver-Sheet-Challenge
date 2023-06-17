#include <bits/stdc++.h> 
void sort012(int *nums, int n)
{
   int l = 0 , mid = 0 , h = n -1;
        while(mid <= h){
            if(nums[mid] == 0){
                swap(nums[l],nums[mid]);
                mid++ , l++;
            }
            else if(nums[mid] == 2){
                 swap(nums[h],nums[mid]);
                h--;
            }
            else 
                mid++;
        }
}