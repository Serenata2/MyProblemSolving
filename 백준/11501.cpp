#include <iostream>

#define MAX_NUM 1000000

using namespace std;

int stocks[MAX_NUM + 1];

int main() 
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        // 미래의 주가들 입력받기
        for (int i = 1; i <= N; i++) {
            scanf("%d", &stocks[i]);
        }

        long long benefit = 0;      // 최대 이득
        int max_stock = stocks[N];  // 미래에 가장 높은 주가 가격

        for (int i = N - 1; i > 0; i--) {
            // 미래에 가장 높은 주가 가격에 판다고 가정
            if (max_stock > stocks[i]) {
                benefit += (long long)(max_stock - stocks[i]);
            }
            // i일 주가가 i일 이후에 주가들보다 크므로
            // i일에 주식을 사는 경우 손해
            // 그리고 max_stock 변수 update
            else {
                max_stock = stocks[i];
            }
        }

        cout << benefit << endl;
    }

    return 0;
}