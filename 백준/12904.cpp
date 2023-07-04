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
			T.pop_back(); // 뒤에 A 제거
		}
		else {
			T.pop_back(); // 뒤에 B 제거
			reverse(T.begin(), T.end());
		}
		t_len--;
	}

	int result = 0;
	// S와 T가 같으면 S에서 T로 바꿀 수 있다.
	if (S.compare(T) == 0) {
		result = 1;
	}
	
	cout << result;

	return 0;
}