#include <iostream>
#define N 5
using namespace std;

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double inputNum, maxNum;

    cout << N << "���� �Ǽ��� �Է��϶� >> ";

    for (int k = 0; k < N; k++) {
        cin >> inputNum;
        if (!k) maxNum = inputNum;
        else
            if (inputNum > maxNum)
                maxNum = inputNum;
    }

    cout << "���� ū �� = " << maxNum;
    return 0;
}