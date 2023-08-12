#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_NUM 20

using namespace std;

int arr[MAX_NUM + 1];

int main() 
{
    int N, S;
    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        vector<bool> temp(N, false);

        for (int j = 0; j < i; j++) {
            temp[j] = true;
        }

        do {
            int sum = 0;
            for (int j = 0; j < N; j++) {
                if (temp[j]) {
                    sum += arr[j+1];
                }
            }
            if (sum == S) {
                ans++;
            }
        } while (prev_permutation(temp.begin(), temp.end()));
    }

    cout << ans;

    return 0;
}
