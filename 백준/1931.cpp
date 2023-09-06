#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX_NUM 100000

using namespace std;

pair<int, int> meeting[MAX_NUM + 1];

int main() 
{
    int N;
    cin >> N;

    // ȸ�� �ð� �Է¹ޱ�
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &meeting[i].second, &meeting[i].first);
    }

    // ȸ�ǰ� ������ �ð� �������� ����
    sort(meeting + 1, meeting + N + 1);

    int ans = 0; // ����� �� �ִ� ȸ�� ����
    int meeting_end = -1; // ���������� ����� ȸ���� ������ �ð�

    for (int i = 1; i <= N; i++) {
        if (meeting_end <= meeting[i].second) {
            meeting_end = meeting[i].first;
            ans++;
        }
    }

    cout << ans;

    return 0;
}