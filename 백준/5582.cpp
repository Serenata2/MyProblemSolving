#include <iostream>
#include <string>

#define MAX_NUM 4000

using namespace std;

// D[i][j] : s, t 문자열의 각각 i, j번째에서 끝나는 문자열에서
// 가장 긴 공통 문자열의 길이
int D[MAX_NUM + 1][MAX_NUM + 1];

int main() {
    string s, t;

    // index 검사를 편하게 하기 위해 맨 앞에 공백 넣기
    cin >> s >> t;
    s.insert(0, " ");
    t.insert(0, " ");

    // 최댓값을 가지고 있다가 s[i], t[j]가 같은 경우 D[i][j]와 비교하기
    int ans = 0;
    for (int i = 1; i < s.length(); i++) {
        for (int j = 1; j < t.length(); j++) {
            if (s[i] == t[j]) {
                D[i][j] = D[i - 1][j - 1] + 1;
                ans = max(ans, D[i][j]);
            }
            else {
                D[i][j] = 0;
            }
        }
    }

    if (ans > 1) {
        cout << ans;
    }
    else {
        cout << 0;
    }

    return 0;
}