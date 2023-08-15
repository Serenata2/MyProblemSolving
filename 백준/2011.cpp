#include <iostream>
#include <string>

#define MAX_NUM 5000
#define DIVISION_NUM 1000000

using namespace std;

int D[MAX_NUM + 1];

int main()
{
    string str;
    cin >> str;
    str.insert(0, " ");

    int ans = 0;

    if (str[1] != '0') {
        ans = 1;

        // �ʱ�ȭ
        D[0] = 1; // �Ʒ� for������ i = 2�� �� ���� ���̽��� ���ؼ�
        D[1] = 1;

        for (int i = 2; i < str.length(); i++) {
            // 0�� ���� ��� ������ �տ� ���ڿ� �������� ���ڰ� �Ǿ�� �Ѵ�.
            if (str[i] == '0') {
                // �տ� ���ڿ� 0�� ���ļ� ���ڸ� �� ����� ���
                if (str[i - 1] == '0' || str[i - 1] >= '3') {
                    ans = 0;
                    break;
                }
                else {
                    D[i] = D[i - 2];
                }
            }
            else {
                D[i] = D[i - 1];

                int sum = 10 * (str[i - 1] - '0') + (str[i] - '0');

                // ���� ���ڰ� 0�� �ƴϰų�
                // ���� ���ڸ� ���ؼ� ���ڸ� ���� �� �ִ� ���
                if (str[i-1] != '0' && sum <= 26) {
                    D[i] = (D[i] + D[i - 2]) % DIVISION_NUM;
                }
            }
        }

        if (ans) {
            ans = D[str.length() - 1];
        }
    }

    cout << ans;

    return 0;
}