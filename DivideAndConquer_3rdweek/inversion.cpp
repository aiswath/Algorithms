#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& arr, vector<int>& temp_arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long inv_count = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp_arr[k++] = arr[i++];
        } else {
            temp_arr[k++] = arr[j++];
            inv_count += (mid - i + 1);  
        }
    }
    
    while (i <= mid) {
        temp_arr[k++] = arr[i++];
    }
    
    while (j <= right) {
        temp_arr[k++] = arr[j++];
    }
    
    for (int i = left; i <= right; ++i) {
        arr[i] = temp_arr[i];
    }
    
    return inv_count;
}
long long merge_and_count(vector<int>& arr, vector<int>& temp_arr, int left, int right) {
    if (left >= right) return 0;
    
    int mid = (left + right) / 2;
    long long inv_count = 0;
    
    inv_count += merge_and_count(arr, temp_arr, left, mid);      
    inv_count += merge_and_count(arr, temp_arr, mid + 1, right);  
    inv_count += merge(arr, temp_arr, left, mid, right);         
    
    return inv_count;
}


long long count_inversions(vector<int>& arr) {
    vector<int> temp_arr(arr.size());
    return merge_and_count(arr, temp_arr, 0, arr.size() - 1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> arr2(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        // for (int i = 0; i < n; ++i) {
        //     cin >> arr2[i];
        // }
        
        cout << count_inversions(arr) << "\n";

    }

    return 0;
}
