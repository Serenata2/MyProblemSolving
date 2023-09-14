#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    vector<char> operators; // operators[i] = i��° ���� �տ� �ִ� ������ ����
    vector<int> numbers; // ���� �迭

    string str;

    cin >> str;

    int i = 0;
    if (str[0] == '-' || str[0] == '+') {
        operators.push_back(str[0]);
        i++;
    }
    else {
        // ù ��° ���� �տ� �����ڰ� ������
        // + �����ڰ� �ִٰ� ����
        operators.push_back('+');
    }

    // ���ڿ��� ���ڿ� �����ڷ� ������
    while (i < str.length()) {
        // �������� ���
        if (str[i] == '-' || str[i] == '+') {
            operators.push_back(str[i]);
            i++;
        }
        // ������ ���
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
    
    // ù ��° - �����ڰ� ������ �������� ���ϰ�
    // ���Ŀ��� �� ����.
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