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
        cout << "Insertion - Element #" << i << endl;
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
        cout << endl;

    }


    return array;
}

int main() {
    if (debug == 0){
        int n = 0; cin >> n;
        vector <int> array(n);
        for(int i = 0; i < n; i++)
            cin >> array[i];

        cout << "Initial array:" << endl;
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
        cout << endl;

        array = insertion(array);
        /*
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
        */
    }
    else{
        setlocale(LC_ALL, "");
        vector <int> array{338, 391, 12030, 101, 1999, 572, 1886, 1690, 189, 2619, 1281, 369};
        array = insertion(array);
        /*
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
        */
    }


    return 0;
}
