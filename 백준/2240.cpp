#include <iostream>

#define MAX_NUM 1000

using namespace std;

// D[i][j] : i�ʱ��� j�� �������� �� ���� �� �ִ� �ִ� �ڵ��� ��
int D[MAX_NUM + 1][31];
int drop[MAX_NUM + 1];

int main() {
    int T, W;
    cin >> T >> W;
    
    for (int i = 1; i <= T; i++) {
        cin >> drop[i];

        // �ڸ��� �������� �ʾ��� ���� ��(D[i][0]) �ʱ�ȭ
        D[i][0] = D[i - 1][0] + drop[i] % 2;
    }

    for (int i = 1; i <= T; i++) {

        for (int j = 1; j <= W && j <= i; j++) {
            // i�ʿ� ���� 1���� �ڵΰ� �������� ���
            if (drop[i] == 1) {
                // j�� �̵����� �� ���� 1�� ��ġ�� ���
                if (j % 2 == 0) {            
                    // �� �� �� �� ū ���� ����
                    // 1. i-1�ʿ��� j�� �̵����� �� �ִ� �ڵ� �� + 1
                    // 2. i-1�ʿ��� j-1�� �̵��߰�, i�ʿ��� �̵����� �� + 1
                    D[i][j] = max(D[i - 1][j], D[i-1][j-1]) + 1;
                }
                // j�� �̵����� �� ���� 2�� ��ġ�� ���
                else {           
                    // i�ʿ����� �ᱹ �ڵθ� �� �ޱ⿡ D[i-1][j]�� �Ҵ�
                    D[i][j] = D[i - 1][j];
                }
            }
            // i�ʿ� ���� 2���� �ڵΰ� �������� ���
            else {
                if (j % 2 == 0) {
                    D[i][j] = D[i - 1][j];
                }
                else {
                    D[i][j] = max(D[i - 1][j], D[i - 1][j - 1]) + 1;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= W; i++) {
        ans = max(ans, D[T][i]);
    }

    cout << ans;

    return 0;
}