#include <iostream>
#define N 5
using namespace std;

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double inputNum, maxNum;

    cout << N << "개의 실수를 입력하라 >> ";

    for (int k = 0; k < N; k++) {
        cin >> inputNum;
        if (!k) maxNum = inputNum;
        else
            if (inputNum > maxNum)
                maxNum = inputNum;
    }

    cout << "제일 큰 수 = " << maxNum;
    return 0;
}