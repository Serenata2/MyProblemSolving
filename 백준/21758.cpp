#include <iostream>

#define MAX_NUM 100000

using namespace std;

int beehive[MAX_NUM + 1];
int sum[MAX_NUM + 1];

int main() 
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> beehive[i];
        sum[i] = sum[i - 1] + beehive[i];
    }
       
    int ans = -1;
    // 벌통이 벌 중앙에 있는 경우
    // 벌은 양쪽 끝에 위치하는게 최선
    for (int i = 2; i <= N - 1; i++) {
        int honey_sum = (sum[i] - sum[1]) + (sum[N-1] - sum[i-1]);
        ans = max(ans, honey_sum);
    }

    // 벌통이 오른쪽 끝에 있는 경우
    for (int i = 2; i <= N - 1; i++) {
        int honey_sum = (sum[N] - sum[1]) + (sum[N] - sum[i]) - beehive[i];
        ans = max(ans, honey_sum);
    }

    // 벌통이 왼쪽 끝에 있는 경우
    for (int i = N - 1; i >= 2; i--) {
        int honey_sum = sum[N - 1] + sum[i - 1] - beehive[i];
        ans = max(ans, honey_sum);
    }

    cout << ans;

    return 0;
}
