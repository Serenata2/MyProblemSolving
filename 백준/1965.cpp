#include <iostream>

#define MAX_NUM 1000

using namespace std;

int box[MAX_NUM + 1];
// D[i] : i��° ���ڸ� ���������� ���� ��, �ִ� ������ ����
int D[MAX_NUM + 1];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> box[i];
    }

    // �ʱ�ȭ
    D[1] = 1;

    for (int i = 2; i <= n; i++) {
        int max_box = 0;
        // ���� ���� �߿��� ũ�Ⱑ ���� �� �߿���
        // ���� ū D�迭 ���� ������ �� ����
        for (int j = i - 1; j > 0; j--) {
            if (box[j] < box[i] && max_box < D[j]) {
                max_box = D[j];
            }
        }
        D[i] = max_box + 1;
    }

    // D�迭���� �ִ밪�� ����
    int ans = D[1];
    for (int i = 2; i <= n; i++) {
        ans = max(ans, D[i]);
    }

    cout << ans;

    return 0;
}