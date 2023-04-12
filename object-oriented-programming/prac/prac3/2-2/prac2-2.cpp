#include <iostream>
using namespace std;

bool average(int a[], int size, int& avg) {
    if (size < 0 || size > 6) return false;
    int tot = 0;
    for (int idx=0; idx < size; idx++)
        tot += a[idx];
    avg = tot / size;
    return true;
}

int main() {
    int x[] = { 0, 1, 2, 3, 4, 5 };
    int avg;
    
    if(average(x, 5, avg)) cout << "평균은 " << avg << endl;
    else cout << "매개 변수 오류" << endl;
    
    if(average(x, 7, avg)) cout << "평균은 " << avg << endl;
    else cout << "매개변수 오류 " << endl;

    return 0;
}