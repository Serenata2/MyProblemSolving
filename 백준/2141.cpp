#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 참고한 수학적 자료
// https://math.stackexchange.com/questions/4410205/minimum-value-of-sum-of-absolute-diferences

int main()
{
	int N;
	long long sum = 0;
	vector<pair<int, int>> town;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int pos, person;
		scanf("%d %d", &pos, &person);
		town.push_back(make_pair(pos, person));
		sum += (long long)person;
	}

	sort(town.begin(), town.end());

	long long cur = 0;
	for (int i = 0; i < N; i++) {
		cur += town[i].second;
		if (cur >= (sum + 1) / 2) {
			printf("%d", town[i].first);
			break;
		}
	}

	return 0;
}