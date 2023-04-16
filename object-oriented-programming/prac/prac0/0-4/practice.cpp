#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int k = 0; k < 4; k++) {
		for (int z = 0; z <= k; z++)
			cout << '*';
		cout << '\n';
	}
	return 0;
}