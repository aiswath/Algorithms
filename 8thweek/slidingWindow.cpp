#include <bits/stdc++.h>
using namespace std;

typedef int Key;
struct Element{
    int id;
    Key key;
};
vector<Element> H;
int n;
vector<int> xmap;

inline int LeftChild(int i) { return 2 * i; }
inline int RightChild(int i) { return 2 * i + 1; }
inline int Parent(int i) { return i / 2 ; }

void SwapHeap(int i, int j){
    swap(H[i], H[j]);
    swap(xmap[H[i].id], xmap[H[j].id]);
}

void UpHeap(int i){
    while (i > 1 && H[Parent(i)].key > H[i].key){
        SwapHeap(i, Parent(i));
        i = Parent(i);
    }
}

void DecreaseKey(int id, Key key){
    int i = xmap[id];
    H[i].key = key;
    UpHeap(i);
}

void Insert(int id, int key){
    ++n;
    H[n].id = id;
    H[n].key = key;
    xmap[id] = n;
    UpHeap(n);
}

void Heapify(int i){
    while (true) {
        int l = LeftChild(i);
        int r = RightChild(i);
        int smallest = i;

        if (l <= n && H[l].key < H[smallest].key)
            smallest = l;
        if (r <= n && H[r].key < H[smallest].key)
            smallest = r;
        
        if (smallest == i) break;

        SwapHeap(i, smallest);
        i = smallest;
    }
}

int DeleteMin(){
    int minId = H[1].id;

    SwapHeap(1, n);
    --n;
    Heapify(1);

    return minId;
}
void CreateHeap(){
    for (int i = n/2; i >= 1; --i)
        Heapify(i);
}


int main(){
    int NumTestCases;
    cin >> NumTestCases;

    while (NumTestCases--){
        int num_elements, width;
        cin >> num_elements >> width;
        H.resize(width + 1);
        xmap.resize(num_elements + 1);
        n = width;
        for (int i = 1; i <= width; ++i){
            int val;
            cin >> val;
            H[i].id = i;
            H[i].key = val;
            xmap[i] = i;
        }
        CreateHeap();

        vector<int> ans;
        ans.reserve(max(0, num_elements - width + 1));

        for (int i = width + 1, delete_id = 1; i <= num_elements; ++i, ++delete_id){
            int val;
            cin >> val;

            ans.push_back(H[1].key);
            if (H[1].id != delete_id)
                DecreaseKey(delete_id, 0);
                
            DeleteMin();
            Insert(i, val);
        }
        ans.push_back(H[1].key);
        
        int sum = 0;
        for(int i = 0; i < (int)ans.size(); ++i){
            sum += ans[i];
            sum %= 100000007;
        }
        cout << sum << "\n";
    }
    return 0;
}