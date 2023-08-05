// https://hagisilecoding.tistory.com/133 코드 참조

#include <iostream>
#include <vector>

#define MAX_NUM 50

using namespace std;

vector<int> v[MAX_NUM + 1];

// 자신의 그룹이 어디에 속해있는지 리턴
int find_p(int parent[], int x) {
    if (x != parent[x])
        return parent[x] = find_p(parent, parent[x]);
    else
        return parent[x];
}

// x와 y를 같은 그룹으로 만들어줌
void mer(int parent[], int x, int y) {
    int px = find_p(parent, parent[x]);
    int py = find_p(parent, parent[y]);
    if (px != py) {
        if (px < py)
            parent[py] = parent[px];
        else
            parent[px] = parent[py];
    }
}

int main() {
    int n, m; // 사람 수, 파티 수
    cin >> n >> m;

    int know_tru; // 진실을 아는 사람 수
    cin >> know_tru;

    int parent[53]; // 어느 그룹에 속해 있는지 

    for (int i = 0; i <= n; i++)
        parent[i] = i; // 각자 자신의 그룹으로 먼저 분류

    for (int i = 0; i < know_tru; i++) {
        int num;
        cin >> num;
        parent[num] = 0; // 진실을 아는 사람은 0 집합으로 분류
    }

    for (int i = 1; i <= m; i++) {
        // 파티에 오는 사람 수와 첫 번째 사람 입력 받기
        int n, persion_num;
        cin >> n >> persion_num;

        v[i].push_back(persion_num);

        // 첫번째 사람만 올 경우 혼자 오는 것이기 때문에
        // 다른 사람과 그룹을 합치지 않아도 돼서 분류
        for (int j = 2; j <= n; j++) {
            int num;
            cin >> num; // 파티에 오는 사람 번호
            v[i].push_back(num); // 파티에 오는 사람 번호 저장
            mer(parent, v[i][0], num); // 파티에 오는 사람 그룹 합침
        }
    }

    int answer = m; // 전부 거짓말을 할 경우 수 부터 시작

    // 각 파티마다 진실을 아는 사람이 한명이라도 있으면 거짓말을 할 수 없음
    // -> 하나 빼줌
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (find_p(parent, parent[v[i][j]]) == 0) {
                answer--;
                break;
            }
        }
    }

    cout << answer;
    return 0;
}
