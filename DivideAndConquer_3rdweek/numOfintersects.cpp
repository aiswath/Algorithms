#include<bits/stdc++.h>
using namespace std;

long long merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right){
    int i = left, j = mid + 1, k = left;
    long long inv = 0;

    while (i <= mid && j <= right){
        if (arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv += (mid - i + 1);
        }
    }
    while (i <= mid){
        temp[k++] = arr[i++];
    }
    while (j <= right){
        temp[k++] = arr[j++];
    }
    for(int i=left; i<=right; i++){
        arr[i] = temp[i];
    }
    return inv;
}

long long mergeSort(vector<int> &arr, vector<int> &temp, int left, int right){
    if (left>=right)return 0;
    int mid = (left + right) / 2;
    long long inv = 0;

    inv += mergeSort(arr, temp, left, mid);
    inv += mergeSort(arr, temp, mid+1, right);
    inv += merge(arr, temp, left, mid, right);

    return inv;
}
long long countInversion(vector<int>&arr){
    int n = arr.size();
    vector<int>temp(n);
    return mergeSort(arr, temp,0, arr.size()-1);

}
long long intersections(vector<int>&arr, vector<int>&arr1){
    unordered_map<int, int>pos;
    for(int i=0; i< (int)arr.size(); i++) pos[arr[i]] = i;
    vector<int> temp(arr.size());
    for(int x: arr1) temp.push_back(pos[x]);
    return countInversion(temp);
}
int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n), arr1(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int j=0; j<n; j++) cin >> arr1[j];
        cout << intersections(arr,arr1) << endl;
    }
    return 0;

}