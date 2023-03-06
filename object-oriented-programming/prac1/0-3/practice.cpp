#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tot = 0;
	for (int k = 1; k <= 10; k++)
		tot += k;
	cout << "1에서 10까지 더한 결과는 " << tot << "입니다.";
	return 0;
}