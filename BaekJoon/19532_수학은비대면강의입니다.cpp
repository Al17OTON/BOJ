#include <iostream>

using namespace std;

int a, b, c, d, e, f;

void buruteForce() {

	int x = -999, y = -999;

	int ax = x * a, by = b * y, dx = d * x, ey = e * y;

	while (ax + by != c || dx + ey != f) {

		x++;
		if (x == 1000) {
			x = -999;
			y++;
			if (y == 1000) break;
		}

		ax = x * a, by = b * y, dx = d * x, ey = e * y;
	}

	cout << x << " " << y << endl;

}

int main() {

	cin >> a >> b >> c >> d >> e >> f;

	buruteForce();
}