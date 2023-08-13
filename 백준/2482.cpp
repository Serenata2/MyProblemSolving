#include <iostream>

#define MAX_NUM 1000
#define DIVSION_NUM 1000000003

using namespace std;

// D[i][j] : i���� ���򿡼� ��Ģ�� ��Ű�鼭 j�� ĥ�� ���
// i�� N���� ���� ���, �� ����� �ƴ� ������ ���·� ��������
long long D[MAX_NUM + 1][MAX_NUM + 1];

int main()
{
    int N, K;
    cin >> N >> K;

    // �ʱ�ȭ
    for (int i = 1; i <= N; i++) {
        D[i][1] = (long long)i;
    }

    for (int j = 2; j <= K; j++) {
        if (2 * j - 1 <= N) {
            D[2 * j - 1][j] = 1;
        }

        for (int i = 2 * j; i <= N - 1; i++) {
            D[i][j] = (D[i - 1][j] + D[i - 2][j - 1]) % DIVSION_NUM;
        }

        // D[N - 3][j - 1] : N��° ĭ�� ĥ�ϴ� ��� 
        //                   -> 2 ~ N - 2ĭ����  j -1 �� ĥ�ϴ� ��� == 1 ~ N - 3ĭ���� j - 1�� ĥ�ϴ� ���
        // D[N - 1][j] : N��° ĭ�� ĥ���� ���礤 ���
        D[N][j] = (D[N - 3][j - 1] + D[N - 1][j]) % DIVSION_NUM;
    }


    cout << D[N][K];

    return 0;
}