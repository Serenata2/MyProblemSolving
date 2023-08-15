#include <iostream>
#include <cstdio>

#define MAX_NUM 2000

using namespace std;

int arr[MAX_NUM + 1];
// D[s][e] : s��° ������ e��° ���� ���� �Ҹ������ �̷�� 1, �ƴϸ� 0
int D[MAX_NUM + 1][MAX_NUM + 1];

int main()
{
    int N, M;
    cin >> N;
    
    // ���� �Է� �ޱ� �� D�迭 �ʱ�ȭ
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        D[i][i] = 1;
    }

    for (int i = N - 1; i > 0; i--) {
        // i, i+1��° ���� ���� ��쿡�� i ~ i+1 ���� �Ӹ����
        if (arr[i] == arr[i + 1]) {
            D[i][i + 1] = 1;
        }

        for (int j = i + 2; j <= N; j++) {
            // i, j��° ���� ������ i+1 ~ j-1 ���� �Ӹ������ �̷���� Ȯ���Ѵ�.
            if (arr[i] == arr[j]) {
                D[i][j] = D[i + 1][j - 1];
            }
            // i, j��° ���� ���� ������ i ~ j ���� �Ӹ������ �̷��� �ʴ´�.
            else {
                D[i][j] = 0;
            }
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", D[s][e]);
    }

    return 0;
}