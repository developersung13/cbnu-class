#include <iostream>
using namespace std;

int sum(int, int);

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cout << "������ �Է��ϼ���>> ";
    cin >> n;
    cout << "1���� " << n << "������ ���� " << sum(1, n) << "�Դϴ�.";

    return 0;
}

int sum(int a, int b) {
    int tot = 0;
    for (int k = a; k <= b; k++)
        tot += k;
    return tot;
}