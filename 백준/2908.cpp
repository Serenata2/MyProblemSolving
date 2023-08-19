#include <iostream>
#include <string>

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;

    string ans;

    // 뒤에서부터 숫자를 하나씩 비교해나간다.
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] == B[i]) {
            continue;
        }
        else if (A[i] > B[i]) {
            ans = A;
            break;
        }
        else {
            ans = B;
            break;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}
