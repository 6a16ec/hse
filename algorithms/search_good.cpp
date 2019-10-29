#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int linear_search(vector <int> arr, int target, bool logs = false){
    if(logs) printf("Linear search:\n");
    int n = arr.size();
    arr.push_back(target);

    int index = 0;
    while(arr[index] != target){
        if(logs) if(index < n) printf("%d ", arr[index]);
        index += 1;
    }
    if(logs && index < n) printf("%d ", arr[index]);
    if(logs) printf("\n");

    return (index != n) ? index : (-1);
}

int binary_search(vector <int> arr, int target, bool logs = false, bool about = true){
    if(logs && about) printf("Binary search:\n");
    int left_i = 0, right_i = (arr.size() - 1);
    int index = -1;

    while(right_i - left_i + 1 > 0){
        int middle_i = left_i + ((right_i - left_i) / 2);
        int middle = arr[middle_i];
        if(logs) printf("%d ", middle);

        if(target == middle){
            index = middle_i;
            break;
        }
        else {
            if(target < middle) right_i = (middle_i - 1);
            if(target > middle) left_i = (middle_i + 1);
        }
    }
    if(logs) printf("\n");

    return index;
}

int exponential_search(vector <int> arr, int target, bool logs = false){
    if(logs) printf("Doubling search:\n");
    /*
    if(arr.size() == 1){
        cout << arr[0] << ' ' << endl;
        return 0;
    }
    */
    int last_i = (arr.size() - 1);
    int index = -1; int pow = 1;
    while(pow / 2 < last_i || arr.size() == 1){
        int min_i = pow / 2;
        int max_i = min(pow, last_i);

        int min = arr[min_i];
        int max = arr[max_i];

        if((min <= target && target <= max) || !(pow < last_i)){
            bool side = false;
            if(target == min){
                index = min_i;
                side = true;
            }
            if(max_i == pow && target == max){
                index = max_i;
                side = true;
            }
            if(!side){
                if(arr.size() == 1){
                    cout << arr[min_i] << " " << endl;
                }
                if(arr.size() == 2){
                    cout << arr[min_i] << " " << endl;
                }
            }

            if(!side){
                min_i += 1;
                if(max_i == pow) max_i -= 1;
                vector <int> help(max_i - min_i + 1);
                for(int i = min_i; i <= max_i; i++) help[i - min_i] = arr[i];
                int result = binary_search(help, target, true, false);
                index = (result != -1) ? (min_i + result) : (-1);
            }

            if(logs){
                if(side){
                    cout << arr[index] << ' ' << endl;
                }
            }

            break;
        }

        pow *= 2;
    }

    return index;
}

int main(){
    int size, target; cin >> size >> target;

    vector <int> arr(size);
    for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
    printf("Initial array:\n"); for(int i = 0; i < size; i++) printf("%d ", arr[i]); printf("\n");

    linear_search(arr, target, true);
    binary_search(arr, target, true);
    exponential_search(arr, target, true);

    return 0;
}
