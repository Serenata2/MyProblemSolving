#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    vector<char> operators; // operators[i] = i번째 숫자 앞에 있는 연산자 종류
    vector<int> numbers; // 숫자 배열

    string str;

    cin >> str;

    int i = 0;
    if (str[0] == '-' || str[0] == '+') {
        operators.push_back(str[0]);
        i++;
    }
    else {
        // 첫 번째 숫자 앞에 연산자가 없으면
        // + 연산자가 있다고 가정
        operators.push_back('+');
    }

    // 문자열을 숫자와 연산자로 나누기
    while (i < str.length()) {
        // 연산자인 경우
        if (str[i] == '-' || str[i] == '+') {
            operators.push_back(str[i]);
            i++;
        }
        // 숫자인 경우
        else {
            int val = 0;
            while (i < str.length() && str[i] != '-' && str[i] != '+') {
                val = 10 * val + (str[i] - '0');
                i++;
            }
            numbers.push_back(val);
        }
    }

    int plus = 0;
    int minus = 0;
    
    // 첫 번째 - 연산자가 나오기 전까지는 더하고
    // 이후에는 다 뺀다.
    for (int i = 0; i < operators.size(); i++) {
        if (minus == 0 && operators[i] == '+') {
            plus += numbers[i];
        }
        else {
            minus += numbers[i];
        }
    }

    cout << plus - minus;

    return 0;
}