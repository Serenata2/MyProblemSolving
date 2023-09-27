#include <iostream>
#include <algorithm>

#define MAX_NUM 1000

using namespace std;

int P[MAX_NUM + 1];

int main() 
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    sort(P + 1, P + 1 + N);

    int ans = 0;

    // ������������ �����ؼ�
    // ����ð��� ª�� ������� ���� �����ϵ��� �Ѵ�.
    for (int i = 1; i <= N; i++) {
        ans += (N - i + 1) * P[i];
    }

    cout << ans;

    return 0;
}