#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        long long x, y;
        cin >> x >> y;

        long long length = y - x;

        // 이분탐색으로 원하는 값 찾기
        long long left = 0;
        long long right = (long long)pow(2, 16);
        long long ans;

        while (left <= right) {
            long long mid = (left + right) / 2;
            long long remain = length - mid * (mid + 1);


            if (remain < 0) {
                right = mid - 1;
            }
            else {
                ans = 2 * mid;
                left = mid + 1;
                if (remain > 0) {
                    ans++;
                    if (remain > mid + 1)
                        ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}