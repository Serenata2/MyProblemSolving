#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;

    vector<pair<int, int> > pool;

    // 입력 받기
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;

        pool.push_back(make_pair(start, end));
    }

    // 정렬
    sort(pool.begin(), pool.end());

    int ans = 0; // 널판지 개수
    int board_end = -1; // 마지막으로 설치한 널판지의 끝 위치

    for (int i = 0; i < N; i++) {
        if (board_end < pool[i].first) {
            board_end = pool[i].first;
        }
        else if (pool[i].second <= board_end) {
            continue;
        }

        // 해당 웅덩이를 덮기 위해 필요한 널판지 개수
        int need_board_num = (pool[i].second - board_end - 1) / L + 1;

        board_end += need_board_num * L;
        ans += need_board_num;
    }

    cout << ans;

    return 0;
}