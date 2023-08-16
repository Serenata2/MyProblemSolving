#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;

    vector<pair<int, int> > pool;

    // �Է� �ޱ�
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;

        pool.push_back(make_pair(start, end));
    }

    // ����
    sort(pool.begin(), pool.end());

    int ans = 0; // ������ ����
    int board_end = -1; // ���������� ��ġ�� �������� �� ��ġ

    for (int i = 0; i < N; i++) {
        if (board_end < pool[i].first) {
            board_end = pool[i].first;
        }
        else if (pool[i].second <= board_end) {
            continue;
        }

        // �ش� �����̸� ���� ���� �ʿ��� ������ ����
        int need_board_num = (pool[i].second - board_end - 1) / L + 1;

        board_end += need_board_num * L;
        ans += need_board_num;
    }

    cout << ans;

    return 0;
}