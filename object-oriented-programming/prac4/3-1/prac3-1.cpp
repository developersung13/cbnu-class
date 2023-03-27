#include <iostream>
using namespace std;

// 원형 선언
void f(char c=' ', int line=1);

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    f();
    f('%');
    f('@', 5);

    return 0;
}

void f(char c, int line) {
    for (int k=0; k < line; k++) {
        for (int k=0; k < 10; k++)
            cout << c;
        cout << '\n';
    }
}