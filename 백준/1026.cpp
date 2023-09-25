#include <iostream>
#include <algorithm>

using namespace std;

int A[50];
int B[50];

int main() 
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // A, B 배열 정렬
    sort(A, A + N);
    sort(B, B + N);

    // A배열에서 값이 작은 것을 B배열에서 값이 큰 것에 순서대로 곱하기
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[N - i - 1] * B[i];
    }

    cout << ans;

    return 0;
}