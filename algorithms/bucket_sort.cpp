#include <iostream>
#include <vector>

using namespace std;
#define debug 0

vector <int> insertion(vector <int> array){
    for(int i = 1; i < array.size(); i++){
        int number = array[i], index = i;
        for(int j = i - 1; j >= 0; j--){
            if (array[j] >  number){
                array[j + 1] = array[j];
                index -= 1;
            }
            else break;
        }
        array[index] = number;
    }
    return array;
}

vector <int> bucket_sort(vector <int> array){
    int n = array.size();

    int min_value = array[0], max_value = array[0];
    for(int i = 0; i < n; i++){
        if (array[i] > max_value) max_value = array[i];
        if (array[i] < min_value) min_value = array[i];
    }

    double k = double(max_value - min_value) / (2 * n);
    // cout << min_value << " " << k << " " << max_value << " at all:" << 2*n << endl;
    vector <vector <int> > buckets(2 * n);

    for(int i = 0; i < n; i++){
        int index = (array[i] - min_value) / k;
        buckets[index].push_back(array[i]);
        // cout << array[i] << " = > " << index << endl;
    }

    int index = 0;
    for(int i = 0; i < 2*n; i++){
        buckets[i] = insertion(buckets[i]);
        for(int j = 0; j < buckets[i].size(); j++){
            array[index] = buckets[i][j];
            index += 1;
        }
    }


    return array;
}

int main() {
    if (debug == 0){
        int n = 0; cin >> n;
        vector <int> array(n);
        for(int i = 0; i < n; i++)
            cin >> array[i];
        array = bucket_sort(array);
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
    }
    else{
        setlocale(LC_ALL, "");
        vector <int> array{338, 391, 12030, 101, 1999, 572, 1886, 1690, 189, 2619, 1281, 369};
        array = bucket_sort(array);
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
    }

    return 0;
}
