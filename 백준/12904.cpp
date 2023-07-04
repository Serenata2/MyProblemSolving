#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string S, T;

	cin >> S >> T;

	int s_len = S.length();
	int t_len = T.length();
	while (t_len > s_len) {
		if (T.back() == 'A') {
			T.pop_back(); // �ڿ� A ����
		}
		else {
			T.pop_back(); // �ڿ� B ����
			reverse(T.begin(), T.end());
		}
		t_len--;
	}

	int result = 0;
	// S�� T�� ������ S���� T�� �ٲ� �� �ִ�.
	if (S.compare(T) == 0) {
		result = 1;
	}
	
	cout << result;

	return 0;
}