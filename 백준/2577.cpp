#include <iostream>

using namespace std;

int num_appearances[10];

int main() 
{
    int A, B, C;

    cin >> A >> B >> C;

    int mul = A * B * C;

    do {
        num_appearances[mul % 10]++;
        mul /= 10;
    } while (mul > 0);

    for (int i = 0; i < 10; i++) {
        cout << num_appearances[i] << endl;
    }

    return 0;
}