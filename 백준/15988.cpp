#include <iostream>

#define MAX_NUM 1000000
#define DIVISION_NUM 1000000009

using namespace std;


int main()
{
	long long D[MAX_NUM + 1];
	
	// 초기화
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;

	// D[i] : i를 1, 2, 3의 합으로 나타내는 방법
	for (int i = 4; i <= MAX_NUM; i++) {
		D[i] = (D[i - 1]  + D[i - 2] + D[i - 3]) % DIVISION_NUM;
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << D[n] << endl;
	}

	return 0;
}