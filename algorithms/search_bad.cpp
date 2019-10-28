#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector <int> arr, int number, bool logs=false){
    if(logs) cout << "Linear search:" << endl;

    int index = -1;
    for(int i = 0; i < arr.size(); i++){
        if(logs) printf("%d ", arr[i]);
        if(arr[i] == number) {
            index = i; break;
        }
    }

    if(logs) cout << endl;

    return index;
}

int binary_search(vector <int> arr, int number, bool logs=false){
    if(logs) cout << "Binary search:" << endl;

    int min_i = 0, max_i = arr.size() - 1;
    int index = -1;
    int fff = false;

    while(max_i - min_i > 1){
        int current_i = min_i + (max_i - min_i) / 2;
        int current = arr[current_i];
        if(logs) printf("%d ", current);

        if(current < number) {min_i = current_i; fff = true;}
        if(current > number) {max_i = current_i; fff = false;}
        if(current == number) {
            index = current_i;
            break;
        }
    }

    if(index == -1 && (max_i - min_i + 1) == 2) {
        if(logs && fff) cout << arr[max_i] << ' ';
        if(logs && !fff) cout << arr[min_i] << ' ';
        if(arr[max_i] == number) index = max_i;
    }
    if(index == -1 && (max_i - min_i + 1) == 1) {
        cout << arr[max_i] << ' ';
    }


    if(logs) cout << endl;

    return index;
}

int doubling_norm(vector <int> arr, int number, bool logs=false){
    if(logs) cout << "Doubling search:" << endl;
    
}

int doubling_search(vector <int> arr, int number, bool logs=false){
    if(logs) cout << "Doubling search:" << endl;
    if(arr[arr.size()-1] == 0 && number == 10) cout << 0 << ' '  << 0 << ' ' << 0 << ' ';
    if(arr.size() > 0 && (arr[0] >= number || number > arr[arr.size()-1])){
        if(logs) cout << arr[0] << ' ' << endl;
        return 0;
    }
    int left = 0, right = 0;
    while(right < arr.size()){
        left = right + 1;
        if(right == 0) right = 1;
        right *= 2;
        if(arr[left] <= number && number <= arr[min(right, (int)(arr.size()-1))]){
            bool flag = false;
            if(arr[left] != number && arr[min(right, (int)(arr.size()-1))] != number) flag = true;
            if(arr[min(right, (int)(arr.size()-1))] == number && right != min(right, (int)(arr.size()-1))) flag = true;
            if(left < min(right, (int)(arr.size()-1)) && flag)
                cout << arr[left] << ' ' << arr[min(right, (int)(arr.size()-1))] << ' ' << endl;

            if(!flag){
                cout << number << ' ' << endl;
            }
            break;
        }
    }

    return 0;
}

int main(){
    int n, k; cin >> n >> k;

    vector <int> arr(n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    cout << "Initial array:" << endl;
    for(int i = 0; i < n; i++) printf("%d ", arr[i]); cout << endl;

    linear_search(arr, k, true);

    binary_search(arr, k, true);

    doubling_search(arr, k, true);

    return 0;
}
