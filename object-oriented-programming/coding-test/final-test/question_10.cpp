#include <iostream>
using namespace std;

// max() 함수 구현
template <typename T> T max(T x[], int size) {
  T max = x[0];
  for (int k = 1; k < size; k++)
    max = max < x[k] ? x[k] : max;
  return max;
}

int main() {
  int x[] = {3, 4, 1, 5, 2};
  char c[] = {'e', 'a', 'c', 'd', 'b', 'f'};

  cout << max(x, 5) << " " << max(c, 6);
}