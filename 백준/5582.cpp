#include <iostream>
#include <string>

#define MAX_NUM 4000

using namespace std;

// D[i][j] : s, t ���ڿ��� ���� i, j��°���� ������ ���ڿ�����
// ���� �� ���� ���ڿ��� ����
int D[MAX_NUM + 1][MAX_NUM + 1];

int main() {
    string s, t;

    // index �˻縦 ���ϰ� �ϱ� ���� �� �տ� ���� �ֱ�
    cin >> s >> t;
    s.insert(0, " ");
    t.insert(0, " ");

    // �ִ��� ������ �ִٰ� s[i], t[j]�� ���� ��� D[i][j]�� ���ϱ�
    int ans = 0;
    for (int i = 1; i < s.length(); i++) {
        for (int j = 1; j < t.length(); j++) {
            if (s[i] == t[j]) {
                D[i][j] = D[i - 1][j - 1] + 1;
                ans = max(ans, D[i][j]);
            }
            else {
                D[i][j] = 0;
            }
        }
    }

    if (ans > 1) {
        cout << ans;
    }
    else {
        cout << 0;
    }

    return 0;
}