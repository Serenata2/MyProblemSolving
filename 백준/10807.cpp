#include <iostream>

using namespace std;

int num[201];

int main() 
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;

        num[n + 100]++;
    }

    int v;
    cin >> v;

    cout << num[v + 100];

    return 0;
}