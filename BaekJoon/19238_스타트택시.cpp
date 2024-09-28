#include <iostream>
#include <queue>
#define MAX 20
#define MAX_PASSENGER MAX * MAX
using namespace std;

int N, M, init_fuel;
int map[MAX][MAX] = {};
pair<int,int> passenger[MAX_PASSENGER + 1] = {};
int dr[] = {}
class TEXI {
public:
	int fuel;
	pair<int, int> pos;

	int sim() {
		for (int m = 0; m < M; m++) {

		}

		return fuel;
	}

private:
	bool check_passenger(pair<int, int> p) {
		return map[p.first][p.second] < 0;
	}
	bool find_passenger() {
		queue<pair<int, int>> q;
		pair<int, int> p;
		bool v[MAX][MAX] = {};
		v[pos.first][pos.second] = true;
		q.push(pos);
		int fuel_use = 0, size;

		while (!q.empty() && fuel_use <= fuel) {
			size = q.size();

			for (int s = 0; s < size; s++) {
				p = q.front(); q.pop();
				if (check_passenger(p)) {
					pos = p;
					fuel -= fuel_use;
					return true;
				}

				for (int i = 0; i < 4; i++) {

				}

			}
			fuel_use++;
		}
	}

};

TEXI texi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	pair<int,int> in;
	cin >> N >> M >> init_fuel;
	texi.fuel = init_fuel;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
		}
	}

	cin >> texi.pos.first >> texi.pos.second;

	for (int m = -1; m >= -M; m--) {
		cin >> in.first >> in.second >> passenger[-m].first >> passenger[-m].second;
		map[in.first][in.second] = m;
	}

	/*for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << map[r][c] << " ";
		}
		cout << endl;
	}*/

	cout << texi.sim();
}

