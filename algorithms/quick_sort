#include <iostream>
#include <vector>

using namespace std;
#define debug 0

vector <int> q_sort(vector <int> array){
    int middle_index = array.size() / 2 - !(array.size() % 2);
    int a1 = array[0], a2 = array[middle_index], a3 = array[array.size() - 1];

    int pivot = 0, pivot_count = 0;

    if (max(a2, a3) >= a1 && a1 >= min(a2, a3)) pivot = a1;
    else {
        if (max(a1, a3) >= a2 && a2 >= min(a1, a3)) pivot = a2;
        else pivot = a3;
    }

    vector <int> left, right;

    for(int i = 0; i < array.size(); i++){
        if (array[i] < pivot) left.push_back(array[i]);
        else {
            if (array[i] > pivot) right.push_back(array[i]);
            else pivot_count += 1;
        }
    }

    if (left.size() > 1) left = q_sort(left);
    if (right.size() > 1) right = q_sort(right);

    int index = 0;
    for(int i = 0; i < left.size(); i++, index++) array[index] = left[i];
    for(int i = 0; i < pivot_count; i++, index++) array[index] = pivot;
    for(int i = 0; i < right.size(); i++, index++) array[index] = right[i];

    return array;
}

int main() {
    if (debug == 0){
        int n = 0; cin >> n;
        vector <int> array(n);
        for(int i = 0; i < n; i++)
            cin >> array[i];
        array = q_sort(array);
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
    }
    else{
        setlocale(LC_ALL, "");
        vector <int> array{338, 391, 12030, 101, 1999, 572, 1886, 1690, 189, 2619, 1281, 369};
        array = q_sort(array);
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
    }

    return 0;
}
