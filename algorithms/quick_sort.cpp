#include <iostream>
#include <vector>

using namespace std;
#define debug 0
/*
    int middle_index = array.size() / 2 - !(array.size() % 2);
    int a1 = array[0], a2 = array[middle_index], a3 = array[array.size() - 1];

    if (max(a2, a3) >= a1 && a1 >= min(a2, a3)) pivot = a1;
    else {
        if (max(a1, a3) >= a2 && a2 >= min(a1, a3)) pivot = a2;
        else pivot = a3;
    }
*/

void print(vector <int> array){
    for(int i = 0; i < array.size(); i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void q_sort(vector <int> &array, int li, int ri){
    int pivot_index = 0, pivot = 0;
    int array_size = (ri - li + 1);

    pivot_index = li + array_size / 2 - !(array_size % 2);
    pivot = array[pivot_index];

    vector <int> left, right;

    int pivot_count = 0;
    for(int i = li; i <= ri; i++){
        if (array[i] < pivot) left.push_back(array[i]);
        else {
            if (array[i] > pivot) right.push_back(array[i]);
            else {
                if (pivot_count == 0) pivot_count += 1;
                else {
                    left.push_back(array[i]);
                    pivot_count += 1;
                }
            }
        }
    }

    int index = li;
    for(int i = 0; i < left.size(); i++, index++) array[index] = left[i];
    array[index] = pivot; index += 1;
    for(int i = 0; i < right.size(); i++, index++) array[index] = right[i];

    if (left.size() > 1) {
        q_sort(array, li, li+left.size()-1);
    }
    if (right.size() > 1) {
        q_sort(array, ri-right.size()+1, ri);
    }
}

int main() {

    if (debug == 0){
        int n = 0; cin >> n;
        vector <int> array(n);
        for(int i = 0; i < n; i++) cin >> array[i];

        q_sort(array, 0, array.size() - 1);

        cout << "Result array:" << endl; print(array);
    }
    else{
        setlocale(LC_ALL, "");
        vector <int> array{338, 391, 12030, 101, 1999, 572, 1886, 1690, 189, 2619, 1281, 369};

        cout << "Initial array:" << endl; print(array); cout << endl;

        q_sort(array, 0, array.size() - 1);
    }


    return 0;
}
