// idea is simple we just perform a normal merge sort and do small change in the merge() that will help ous to find the count thus no.

#include <bits/stdc++.h>
using namespace std;
long long ans  = 0;

void merge(long long *arr , long long l, long long mid , long long r){
    long long i = l , j = mid +1;
    vector<long long>temp;

    while(i<= mid && j <= r){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            ans += (mid - i +1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    
    while(j <= r){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k = 0 ; k < temp.size() ;k++){
       arr[l] = temp[k];
       l++; 

    }
}

void mergesort(long long *arr , int l , int r){
    if(l >= r)
        return;
    int mid = (l+ r)/2;
    mergesort(arr , l , mid );
    mergesort(arr , mid+1 , r);
    merge(arr , l ,mid , r);
}

long long getInversions(long long *arr, int n){
    // Write your code here.
   ans = 0 ;
   mergesort(arr , 0 , n -1);
   return ans;
}


