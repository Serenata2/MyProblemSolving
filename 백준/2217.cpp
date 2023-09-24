#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_NUM 100000

using namespace std;

int rope[MAX_NUM + 1];

int main() 
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        scanf("%d", &rope[i]);
    }

    // �� ������ ��ƿ �� �ִ� �߷��� ������������ ����
    sort(rope, rope + N);

    int ans = 0;

    // ��� ���̽��� ���ؼ� ����
    for (int i = 0; i < N; i++) {
        ans = max(ans, (N - i) * rope[i]);
    }

    cout << ans;

    return 0;
}