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

    // A, B �迭 ����
    sort(A, A + N);
    sort(B, B + N);

    // A�迭���� ���� ���� ���� B�迭���� ���� ū �Ϳ� ������� ���ϱ�
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[N - i - 1] * B[i];
    }

    cout << ans;

    return 0;
}