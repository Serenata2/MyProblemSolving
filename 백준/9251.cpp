#include <iostream>
#include <string>

#define MAX_NUM 1000

using namespace std;

int D[MAX_NUM + 1][MAX_NUM + 1];

int main()
{
	string S1, S2;

	cin >> S1 >> S2;

	// S1, S2를 비교할 때 마지막 글자가 같으면 마지막 글자를 뺀 글자에서 LCS를 찾아서 1을 더하면 된다.
	// 아니라면 S1, S2에서 하나의 마지막 글자를 뺀 경우 중 더 큰 LCS가 답이다.
	for (int i = 1; i <= S1.size(); i++) {
		for (int j = 1; j <= S2.size(); j++) {
			if (S1[i - 1] == S2[j - 1]) {
				D[i][j] = D[i - 1][j - 1] + 1;
			}
			else {
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);
			}
		}
	}

	cout << D[S1.size()][S2.size()];

	return 0;
}