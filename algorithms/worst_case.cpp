#include <iostream>
#include <vector>
using namespace std;

void print(vector <int> array){
    for(int i = 0; i < array.size(); i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n; cin >> n;
    vector <int> array(n);

/*
    int pivot_index = n / 2 - !(n % 2);
    for(int i = 0; i < n; i++){
        int index = pivot_index;
        int delta =  (i / 2 + i % 2);
        if (i % 2) delta = (-1) * abs(delta);
        index += delta;
        array[index] = i;
    }
*/
    int index = 0;
    for(int m = n - 2; m >= (n % 2); m -= 2){
        array[index] = m;
        index += 1;
    }
    for(int m = !(n % 2); m <= n-1; m += 2){
        array[index] = m;
        index += 1;
    }

    print(array);

    return 0;
}
