#include <iostream>

#define MAX_NUM 10

using namespace std;

int coin[MAX_NUM + 1];

int main() 
{
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> coin[i];
    }

    int ans = 0;
    for (int i = N; i > 0; i--) {
        // ���� �ݾ��� ���� ������ �켱������ K���� ������� ����
        if (K >= coin[i]) {
            ans += K / coin[i];
            K %= coin[i];
        }
    }

    cout << ans;

    return 0;
}