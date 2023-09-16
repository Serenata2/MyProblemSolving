#include <iostream>

#define MAX_NUM 100

using namespace std;

int main() 
{
    int N;
    cin >> N;

    int remain = 1000 - N;

    int coin[6] = { 500, 100, 50, 10, 5, 1 };
    int num = 0;

    for (int i = 0; i < 6; i++) {
        num += remain / coin[i];
        remain = remain % coin[i];
    }

    cout << num;

    return 0;
}