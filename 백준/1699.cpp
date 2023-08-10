#include <iostream>
#include <climits>
#include <cmath>

#define MAX_NUM 100000

using namespace std;

// D[i] : i�� ���������� ������ ǥ���� �� �� ���� �ּҰ���
int D[MAX_NUM + 1];

int main() 
{
    int N;
    cin >> N;

    D[1] = 1;
    D[2] = 2;

    for (int i = 3; i <= N; i++) {
        D[i] = INT_MAX;
        // root������ i���� ���� ������ �� ���� ū ��
        int root = (int)sqrt((double)(i));

        // ���� i�� ǥ���� �� ���� ���� ���� ������ ã��
        for (int j = root; j > root / 2; j--) {
            int pow_n = (int)pow((double)j, 2);
            D[i] = min(D[i], D[i - pow_n] + 1);
        }
    }

    cout << D[N];

    return 0;
}
