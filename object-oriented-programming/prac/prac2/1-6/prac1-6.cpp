#include <iostream>
using namespace std;

int sum(int, int);

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cout << "끝수를 입력하세요>> ";
    cin >> n;
    cout << "1에서 " << n << "까지의 힙은 " << sum(1, n) << "입니다.";

    return 0;
}

int sum(int a, int b) {
    int tot = 0;
    for (int k = a; k <= b; k++)
        tot += k;
    return tot;
}