#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <unordered_map>

#define MAX_NUM 300000

using namespace std;

pair<int, int> jewels[MAX_NUM];
unordered_map<int, int> bag_num; // <가방의 무게, 개수>
set<int> bags; // 현재 가지고 있는 가방의 무게들을 담은 집합

int main() 
{
    int N, K;
    cin >> N >> K;

    // 보석 정보 입력 받기
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jewels[i].second, &jewels[i].first);
    }

    // 보석의 가치순으로 오름차순으로 정렬하기
    sort(jewels, jewels + N);

    // 배낭의 정보를 입력받기
    int c;
    for (int i = 0; i < K; i++) {
        scanf("%d", &c);
        bags.insert(c);
        if (bag_num.find(c) == bag_num.end()) {
            bag_num[c] = 1;
        }
        else {
            bag_num[c]++;
        }
    }

    int i = N - 1;
    long long ans = 0;
    while (i >= 0 && !bags.empty()) {
        // M : 보석의 무게, V : 보석의 가치
        int M = jewels[i].second, V = jewels[i].first;

        // 가치가 높은 보석 순서대로
        // 최대한 절약해서 배낭에 담기
        if (bags.lower_bound(M) != bags.end()) {
            // 보석을 집어넣을 가방의 무게
            int bag_M = *bags.lower_bound(M);

            ans += (long long)V;
            if (bag_num[bag_M] > 1) {
                bag_num[bag_M]--;
            }
            else {
                bags.erase(bag_M);
            }
        }
        i--;
    }

    cout << ans;

    return 0;
}