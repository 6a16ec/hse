#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k; cin >> n >> k;

    vector <int> arr(n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int min_i = 0, max_i = n - 1;
    int index = -1;
    while(max_i - min_i >= 0){
        int current_i = min_i + (max_i - min_i);
        int current = arr[current_i];

        if(current == k) {
            index = current_i;
            break;
        }
        else {
            if(current < k) min_i = current_i + 1;
            if(current > k) max_i = current_i - 1;
        }
    }

    if(index != -1) cout << "Index: " << index;
    else cout << "Not found";

    return 0;
}
