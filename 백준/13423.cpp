#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void)
{
	int T, N;
	cin >> T;

	while (T-- > 0) {
		cin >> N;
		int result = 0;
		vector<int> X;
		unordered_map<int, bool> M;

		for (int i = 0; i < N; i++) {
			int pos;
			scanf("%d", &pos);
			X.push_back(pos);
			M[pos] = true;
		}
			
		sort(X.begin(), X.end());

		// b = X[i]�̸鼭 ������ ���� a, b, c�� �ִ��� Ȯ��
		for (int i = 0; i < N; i++) {
			for (int j = i - 1; j >= 0; j--) {
				// X[j] = a, X[i] = b�� ��, ������ �����ϴ� c�� �ִ��� Ȯ��
				// HashMap�� Ȱ���ؼ� O(1)���� c�� �ִ��� Ȯ��
				if (M.find(X[i] + (X[i] - X[j])) != M.end())
					result++;
			}
		}

		cout << result << endl;
	}

	return 0;
}