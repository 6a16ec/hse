#include <iostream>
#include <vector>

using namespace std;
#define debug 1

int GetMinrun(int n)
{
    int r = 0;
    /* станет 1 если среди сдвинутых битов будет хотя бы 1 ненулевой */
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

vector <int> merge_sort(vector <int> array){
    int left_size = array.size() / 2 + (array.size() % 2);
    int right_size = array.size() - left_size;

    vector <int> left(left_size), right(right_size);

    for(int i = 0; i < left_size; i++) left[i] = array[i];
    for(int i = left_size; i < left_size + right_size; i++) right[i - left_size] = array[i];


    if (max(left_size, right_size) > 1){
        left = insertion(left);
        right = insertion(right);
    }

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


vector <int> tim_sort(vector <int> array){
    cout << array.size() << " " << GetMinrun(array.size()) << endl;
    int min_run = 4;
    for(int index = 0; index < array.size(); index += minrun){
        vector <int> help(min(minrun, array.size() - 1 - index));
        for(int i = 0; i < min(minrun, array.size() - 1 - index); i++){
            help[i] = array[index+i];
        }
        if
    }
    return array;
}

int main() {
    if (debug == 0){
        int n = 0; cin >> n;
        vector <int> array(n);
        for(int i = 0; i < n; i++)
            cin >> array[i];
        array = tim_sort(array);
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
    }
    else{
        setlocale(LC_ALL, "");
        vector <int> array{338, 391, 12030, 101, 1999, 572, 1886, 1690, 189, 2619, 1281, 369};
        array = tim_sort(array);
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
    }

    return 0;
}
