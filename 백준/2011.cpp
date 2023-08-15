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

        // 초기화
        D[0] = 1; // 아래 for문에서 i = 2일 때 예외 케이스를 위해서
        D[1] = 1;

        for (int i = 2; i < str.length(); i++) {
            // 0이 오는 경우 무조건 앞에 숫자와 합해져서 글자가 되어야 한다.
            if (str[i] == '0') {
                // 앞에 숫자와 0을 합쳐서 글자를 못 만드는 경우
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

                // 이전 숫자가 0이 아니거나
                // 이전 숫자를 합해서 글자를 만들 수 있는 경우
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