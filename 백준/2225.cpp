#include <iostream>

#define MAX_NUM 200
#define DIVISION_NUM 1000000000

using namespace std;

// D[N][K] : ���� N�� �ǵ��� K�� ���ϴ� ����� ��
int D[MAX_NUM + 1][MAX_NUM + 1];

int main() 
{
    int N, K;
    cin >> N >> K;

    // 1�� ���ؼ� N�� �Ǵ� ��� �ʱ�ȭ
    for (int i = 0; i <= N; i++) {
        D[i][1] = 1;
    }

    for (int j = 2; j <= K; j++) {
        // D[0][j] = 1�̹Ƿ� ���� ó��
        D[1][j] = (1 + D[1][j - 1]) % DIVISION_NUM;

        for (int i = 2; i <= N; i++) {
            D[i][j] = (D[i - 1][j] + D[i][j - 1]) % DIVISION_NUM;
        }
    }

    cout << D[N][K];

    return 0;
}