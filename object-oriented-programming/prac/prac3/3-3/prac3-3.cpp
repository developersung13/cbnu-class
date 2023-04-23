#include <iostream>
using namespace std;

//제네릭 함수 add()
template <class T>
T add(T *arr, int size) {
    T tot = 0;
    for (int k=0; k < size; k++)
        tot += arr[k];
    return tot;
} 

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int x[] = { 1, 2, 3, 4, 5 };
    double d[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };
    cout << "sum of x[] = " << add(x, sizeof(x) / sizeof(x[0])) << '\n'; // 배열 x와 원소 5개의 합을 계산
    cout << "sum of d[] = " << add(d, sizeof(d) / sizeof(d[0])) << '\n'; // 배열 d와 원소 6개의 합을 계산
    
    return 0;
}

// #include <iostream>
// using namespace std;

// // 제네릭 함수 add
// template <class T, size_t N> T add(T (&ary)[N]) {
//   T total = 0;
//   for (int k = 0; k < N; k++)
//     total += ary[k];
//   return total;
// }

// int main() {
//   int x[] = {1, 2, 3, 4, 5};
//   double d[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};

//   cout << "sum_of x[] = " << add(x) << '\n';
//   cout << "sum_if d[] = " << add(d) << '\n';

//   return 0;
// }