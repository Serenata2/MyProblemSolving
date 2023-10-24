#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstdio>

#define MAX_NUM 10000

using namespace std;

pair<int, int> delivery[MAX_NUM + 1];
unordered_map<int, int> weight;
int last[MAX_NUM + 1];

int main()
{
    // N : 마을의 수, C : 트럭의 용량
    int N, C;
    cin >> N >> C;

    // M : 보내는 박스 정보의 개수
    int M;
    cin >> M;

    for (int i = 1; i <= M; i++) {
        int w;
        scanf("%d %d %d", &delivery[i].second, &delivery[i].first, &w);
        weight[MAX_NUM * delivery[i].second + delivery[i].first] = w;
    }

    // 받는 마을 번호가 낮은 순서대로 박스 정보 정렬하기
    sort(delivery + 1, delivery + M + 1);

    int ans = 0;
    int current_w = 0;
    int l = 0;

    cout << "-----------------------------------------------------------------------" << endl;
    for (int i = 1; i <= M; i++) {
        int send = delivery[i].second;
        int take = delivery[i].first;
        int w = weight[MAX_NUM * send + take];

        cout << "send : " << send << ", take : " << take << ", w : " << w << endl;

        if (send >= delivery[l].first) {
            cout << "first!!" << endl;
            int minus_w = 0;
            for (int j = delivery[l].first; j <= send; j++) {
                minus_w += last[j];
            }

            current_w -= minus_w;
            cout << "minus : " << minus_w << endl;
            l = i;
        }
        if (current_w < C) {
            cout << "second!!" << endl;
            ans += min(C - current_w, w);
            last[take] += min(C - current_w, w);
            current_w = min(C, current_w + w);
        }

        cout << "ans : " << ans << ", cur_w : " << current_w << ", last : " << last[take] << endl;
        cout << "-----------------------------------------------------------------------" << endl;
    }

    cout << ans;

    return 0;
}