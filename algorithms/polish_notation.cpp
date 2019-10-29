#include <iostream>
#include <string>
using namespace std;

/*
#define O_COUNT 4
const char operations[O_COUNT] = {'+', '-', '*', '/'}
*/

bool isDigit(char c){
    return ('0' <= c && c <= '9');
}

int priority(char c){
    int priority = 0;
    if(c == '+' || c == '-') priority = 1;
    if(c == '*' || c == '/') priority = 2;
    return priority;
}

bool isOp(char c){
    return (priority(c) > 0);
}

bool good(char c){
    return (1 <= priority(c) && priority(c) <=2);
}


class o_stack{
    private:
        char arr[1000];
        int len = 0;
    public:
        void push(char ch){
            arr[len] = ch;
            len += 1;
        }
        char pop(){
            char ch = top();
            len -= 1;
            return ch;
        }
        char top(){
            return arr[len - 1];
        }
        bool isEmpty(){
            return (len == 0);
        }
};

/*
class notation{
    private:
        bool is_number[1000];
        int numbers[1000];
        char ops[1000];
        int len = 0;
    public:
        void addNumber(int number){
            is_number[len] = true;
            numbers[len] = number;
            len += 1;
        }
};
*/

class Numbers{
    private:
        int arr[1000];
        int len = 0;
    public:
        void push(int number){
            arr[len] = number;
            len += 1;
        }
        void calculate(char op){
            int n1 = arr[len - 2], n2 = arr[len - 1];
            int result = 0;
            if (op == '+') result = n1 + n2;
            if (op == '-') result = n1 - n2;
            if (op == '*') result = n1 * n2;
            if (op == '/') result = n1 / n2;
            arr[len - 2] = result;
            len -= 1;
        }
        int result(){
            return arr[0];
        }
};

int main(){
    string str; getline(cin, str);
    cout << "Expression:" << endl << str << endl;
    str.push_back('\0');

    cout << "Reverse Polish Notation:" << endl;

    o_stack ops; Numbers numbers;
    int number = 0; bool number_flag = false;

    for(int i = 0; i < str.size(); i++){
        char now = str[i];
        if (isDigit(now)) {
            number = number * 10 + (now - '0');
            number_flag = true;
        }
        else{
            if (number_flag) {
                cout << number << ' ';
                numbers.push(number);
            }

            if (now == '(') ops.push(now);

            if (now == ')') {
                while(ops.top() != '('){
                    numbers.calculate(ops.top());
                    cout << ops.pop() << ' ';
                }
                ops.pop();
            }

            if (isOp(now)) {
                while(ops.top() != '(' && !ops.isEmpty() && priority(now) <= priority(ops.top())){
                    numbers.calculate(ops.top());
                    cout << ops.pop() << ' ';
                }
                ops.push(now);
            }

            if (now == '\0') {
                while(!ops.isEmpty()) {
                    numbers.calculate(ops.top());
                    cout << ops.pop() << ' ';
                }
            }

            number_flag = false;
            number = 0;
        }
    }

    cout << endl << "Result:" << endl << numbers.result() << endl;

    return 0;
}
