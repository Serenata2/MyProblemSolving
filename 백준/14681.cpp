#include <iostream>

using namespace std;

int main() 
{
    int x, y;
    cin >> x >> y;

    int ans = 0;
    if (x > 0) {
        ans = 4;
        if (y > 0) {
            ans = 1;
        }
    }
    else {
        ans = 3;
        if (y > 0) {
            ans = 2;
        }
    }

    cout << ans;

    return 0;
}