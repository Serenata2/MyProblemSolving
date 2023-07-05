#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//a�� b�� ���Ͽ�, a>b�� ����� ��ȯ�Ѵ�.
bool desc(int a, int b) {
	return a > b;
}

int main(void)
{
	int N;
	vector<int> list;

	cin >> N;

	while (N > 0) {
		list.push_back(N % 10);
		N /= 10;
	}

	sort(list.begin(), list.end(), desc);

	for(int i = 0; i < list.size(); i++) {
		cout << list[i];
	}

	return 0;
}