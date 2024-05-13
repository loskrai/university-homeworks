#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<queue>

#define _READ_
using namespace std;



int main() {
#ifdef _READ_
	freopen("in.txt", "r", stdin);
#endif // _READ_
	time_t beg = clock();

	long long y;
	long long p;
	cin >> y >> p;
	int con = 0;
	p = (pow(2, y) - p);
	while (p != 1) {
		if (p & 1) {
			p = (p + 1) / 2;
		}
		else {
			p /= 2;
			con++;
		}
	}
	if (con & 1) {
		cout << "blue\n";
	}
	else {
		cout << "red\n";
	}


	time_t end = clock();
	cout << "\nrun time: " << (double)(end - beg) / CLOCKS_PER_SEC << " s\n";
	return 0;
}