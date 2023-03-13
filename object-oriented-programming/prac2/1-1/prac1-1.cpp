#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int dan = 1; dan <= 9; dan++) {
        for (int k = 1; k <= 9; k++)
            cout << dan << 'X' << k << '=' << dan * k << '\t';
        cout << '\n';
    }

    return 0;
}