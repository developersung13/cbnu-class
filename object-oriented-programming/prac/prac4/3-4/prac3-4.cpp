#include <iostream>
using namespace std;

template <class T>
void reverseArray(T *arr, int size) {
    for (int k=0; k < size / 2; k++) {
        T tempValue = arr[k];
        arr[k] = arr[size-k-1];
        arr[size-k-1] = tempValue;
    }
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int x[] = {1, 10, 100, 5, 4};
    reverseArray(x, sizeof(x)/sizeof(x[0]));
    for(int i=0; i<5; i++)
    cout << x[i] << ' '; // 4 5 100 10 1 이 출력된다.
    cout << '\n';
    
    return 0;
}