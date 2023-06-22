// here, the concept used is merged sort and a little chnage in merge function will give ous the ans 

int ans = 0;
void merge(vector<int>& a, int low , int mid , int high){
    int i = low , j = mid + 1;
    vector<int> temp;
    while(i <= mid && j <= high){
        if(a[i] <= a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            ans += mid +1 - i;
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(a[i]);
        i++;
    }
    
    while(j <= high){
        temp.push_back(a[j]);
        j++;
    }
     i = 0;
    while(low <= high)
        a[low++] = temp[i++];
}

void mergesort(vector<int>&a , int low , int high){
    if(low >= high)
        return;
    int mid = (low + high)/2;
    mergesort(a ,low , mid);
    mergesort(a ,mid +1 , high);
    merge(a , low , mid , high);

}

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    ans = 0;
    mergesort(a ,0, n-1);
    return ans;

}