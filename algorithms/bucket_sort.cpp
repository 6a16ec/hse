#include <stdio.h>
#include <iostream>
#include <vector>
#define debug 0

using namespace std;
const double eps = 1e-12;

void print(vector <double> array){
    for(int i = 0; i < array.size(); i++){
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

vector <double> insertion(vector <double> array){
    for(int i = 1; i < array.size(); i++){
        double number = array[i], index = i;
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

vector <double> bucket_sort(vector <double> array){
    int n = array.size();
    int buckets_count = 2 * n;

    double min_value = array[0], max_value = array[0];
    for(int i = 0; i < n; i++){
        if (array[i] > max_value) max_value = array[i];
        if (array[i] < min_value) min_value = array[i];
    }

    double b_len = double(max_value - min_value) / (2 * n);
    vector <vector <double> > buckets(2 * n);

    for(int i = 0; i < n; i++){
        int index = (int)((array[i] - min_value) / b_len + eps);
        if (index >= buckets_count) index -= 1;
        buckets[index].push_back(array[i]);
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
        vector <double> array(n);
        for(int i = 0; i < n; i++)
            cin >> array[i];
        array = bucket_sort(array);
        print(array);
    }
    else {
        vector <double> array {33.8, 39.1, 1203.0, 10.1, 199.9, 57.2, 188.6, 169.0, 18.9, 261.9, 128.1, 36.9};
        print(array);
        array = bucket_sort(array);
        print(array);
    }

    return 0;
}
