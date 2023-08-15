#include <iostream>

#define MAX_NUM 1000
#define DIVSION_NUM 1000000003

using namespace std;

// D[i][j] : i�� ������ ����ؼ� ��Ģ�� ��Ű�鼭 j�� ĥ�� ���
long long D[MAX_NUM + 1][MAX_NUM + 1];

int main()
{
    int N, K;
    cin >> N >> K;

    // 1�� ��ĥ�� �� D �迭 �ʱ�ȭ
    for (int i = 1; i <= N; i++) {
        D[i][1] = (long long)i;
    }

    for (int j = 2; j <= K; j++) {
        // j�� ĥ�ϱ� ���ؼ��� �ּ��� 2 * j - 1���� ���� �ʿ��ϴ�
        if (2 * j - 1 <= N) {
            D[2 * j - 1][j] = 1;
        }

        // i(2*j <= i <= N - 1)�� ������ ����ؼ� j�� ĥ�ϴ� ���
        for (int i = 2 * j; i <= N - 1; i++) {
            D[i][j] = (D[i - 1][j] + D[i - 2][j - 1]) % DIVSION_NUM;
        }

        // N�� ������ ����ؼ� j�� ĥ�ϴ� ���
        D[N][j] = (D[N - 1][j] + D[N - 3][j - 1]) % DIVSION_NUM;
    }

    cout << D[N][K];

    return 0;
}