#include <iostream>

#define MAX_NUM 100000
#define DIVISION_NUM 9901

using namespace std;

// D[i][0] : i��° �����ٿ��� ���ڸ� ��ġ���� ����� ��
// D[i][1] : i��° �����ٿ� �ϳ��� ���ڸ� ��ġ�ϴ� ����� ��
int D[MAX_NUM + 1][2];

int main() {
    int N;
    cin >> N;

    // �ʱ�ȭ
    D[1][0] = 1;
    D[1][1] = 2;

    for (int i = 2; i <= N; i++) {
        D[i][0] = (D[i - 1][0] + D[i - 1][1]) % DIVISION_NUM;
        D[i][1] = (2 * D[i - 1][0] + D[i - 1][1]) % DIVISION_NUM;
    }

    cout << (D[N][0] + D[N][1]) % DIVISION_NUM;

    return 0;
}