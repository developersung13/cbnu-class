#include <iostream>
using namespace std;

class Integer {
  private:
    int n;
  public:
    Integer(int n);
    int get();
    void set(int n);
    int isEven();
};

inline Integer::Integer(int n) {
    this->n = n;
}

inline int Integer::get() {
    return this->n;
}

inline void Integer::set(int n) {
    this->n = n;
}

inline int Integer::isEven() {
    return !(this->n & 1);
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    Integer n(30);
    cout << n.get() << ' '; // 30 출력
    
    n.set(50);
    cout << n.get() << ' '; // 50 출력
    
    Integer m(300);
    cout << m.get() << ' '; // 300 출력
    cout << m.isEven(); // true(정수로 1) 출력
    
    return 0;
}