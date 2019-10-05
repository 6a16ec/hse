#include <iostream>
#include <vector>

using namespace std;
#define debug 0

vector <int> merge_sort(vector <int> array){
    if (array.size() <= 1) return array;
    
    int left_size = array.size() / 2; // + (array.size() % 2)
    // {7} = {3} + {4} :((((
    int right_size = array.size() - left_size;

    vector <int> left(left_size), right(right_size);

    for(int i = 0; i < left_size; i++) left[i] = array[i];
    for(int i = left_size; i < left_size + right_size; i++) right[i - left_size] = array[i];


    left = merge_sort(left);
    right = merge_sort(right);

    int ri = 0, li = 0;
    for(int i = 0; i < array.size(); i++){
        int number = 0;
        if (ri < right.size() && li < left.size()){
            if (left[li] < right[ri]){
                number = left[li];
                li += 1;
            }
            else{
                number = right[ri];
                ri += 1;
            }
        }
        else{
            if (ri < right.size()){
                number = right[ri];
                ri += 1;
            }
            else{
                number = left[li];
                li += 1;
            }
        }
        array[i] = number;
    }

    return array;
}

int main() {
    if (debug == 0){
        int n = 0; cin >> n;
        vector <int> array(n);
        for(int i = 0; i < n; i++)
            cin >> array[i];
        array = merge_sort(array);
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
    }
    else{
        vector <int> array {338, 391, 12030, 101, 1999, 572, 1886, 1690, 189, 2619, 1281, 369};
        array = merge_sort(array);
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
    }

    // for(int i = 0; i < 30; i++) cout << i << " = > " << i / 2 - !(i % 2) << endl;

    return 0;
}
