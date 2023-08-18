#include <iostream>

#define MAX_NUM 100

using namespace std;

// D[i][j] : (0,0)���� (i, j)���� �� �� �ִ� ����� ��
long long D[MAX_NUM + 1][MAX_NUM + 1];

// roadwork[i][j][0] : (i, j) ~ (i+1, j) ���ο��� ���簡 �������̸� true
// roadwork[i][j][1] : (i, j) ~ (i, j+1) ���ο��� ���簡 �������̸� true
bool roadwork[MAX_NUM + 1][MAX_NUM + 1][2];

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a == c) {
            roadwork[a][min(b, d)][1] = true;
        }
        else {
            roadwork[min(a, c)][b][0] = true;
        }
    }

    // y = 0���� x�����θ� �̵��� �� ����� �� �ʱ�ȭ
    D[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        if (roadwork[i - 1][0][0] == true) {
            break;
        }
        D[i][0] = 1;
    }

    // ������ D�迭 ä���
    for (int j = 1; j <= M; j++) {
        // x = 0���� y�����θ� �̵��� �� ����� �� ���� �ʱ�ȭ
        if (D[0][j - 1] == 0 || roadwork[0][j - 1][1] == true) {
            D[0][j] = 0;
        }
        else {
            D[0][j] = 1;
        }

        for (int i = 1; i <= N; i++) {
            if (roadwork[i-1][j][0] == false) {
                D[i][j] += D[i - 1][j];
            }

            if (roadwork[i][j-1][1] == false) {
                D[i][j] += D[i][j - 1];
            }
        }
    }

    cout << D[N][M];
    
    return 0;
}