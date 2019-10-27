#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k; cin >> n >> k;

    vector <int> arr(n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    arr.push_back(k);
    int index = 0;
    if(n > 0){
        while(arr[index] != k) index += 1;
    }

    if(index < n) cout << "Index: " << index;
    else cout << "Not found";

    return 0;
}
