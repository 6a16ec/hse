#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define debug 0

vector <string> radix(vector <string> array){
    int max_len = 0;
    for(int i = 0; i < array.size(); i++)
        if (array[i].length() > max_len)
            max_len = array[i].length();

    for(int digit = 0; digit < max_len; digit++){
        vector <string> buckets[16];
        for(int i = 0; i < array.size(); i++){
            string element = array[i];

            int real_digit = (element.length() - 1) - digit;
            int index = 0;

            if (real_digit >= 0){
                index = array[i][real_digit];
                if('A' <= index && index <= 'F') index = index - 'A' + 10;
                if('a' <= index && index <= 'f') index = index - 'a' + 10;
                if('0' <= index && index <= '9') index = index - '0';
            }
            else index = 0;

            buckets[index].push_back(element);
        }

        int i = 0;
        for(int d = 0; d < 16; d++)
            for(int j = 0; j < buckets[d].size(); j++){
                array[i] = buckets[d][j];
                i += 1;
            }
        cout << "Sorting by " << max_len - 1 - digit << " digit:" << endl;
        for(int i = 0; i < array.size(); i++) cout << array[i] << endl;
        cout << endl;

    }

    return array;
}

int main() {
    if (debug == 0){
        int n = 0; cin >> n;
        vector <string> array(n);
        for(int i = 0; i < n; i++){
            cin >> array[i];
            while(array[i][0] == '0' and array[i].length() > 1)
                array[i] = array[i].substr(1, array[i].length());
        }
        array = radix(array);
    }
    else{
        setlocale(LC_ALL, "");
        vector <string> array{"338", "3B1", "BC7", "101", "1BCC", "572", "1CF6", "16B4", "18A", "261A", "1281", "36F"};
        array = radix(array);
        for(int i = 0; i < array.size(); i++)
            cout << array[i] << " ";
    }


    return 0;
}
