#include <iostream>

#define MAX_NUM 90

using namespace std;

long long D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	D[1] = 1;

	for (int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + D[i - 2];
	}

	cout << D[N];

	return 0;
}