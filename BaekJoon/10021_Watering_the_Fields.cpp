#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 2000
#define MAX_MAP 1001

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

class Pipe {
public:
	int from, to, cost;
	Pipe(int f, int t, int c) : from(f), to(t), cost(c) {}

	bool operator<(const Pipe p) const {
		return this->cost > p.cost;
	}

};

int N, C;
pair<int, int>* fields[MAX_N];
priority_queue<Pipe> pq;
bool v[MAX_N];

int calcEuclidean(pair<int, int>* a, pair<int, int>* b);

int main() {
	int x, y, cost, total = 0, count = 0;
	Pipe p = Pipe(0,0,0);

	scanf("%d %d", &N, &C);

	for (int n = 0; n < N; n++) {
		scanf("%d %d", &x, &y);
		fields[n] = new pair<int, int>(x, y);
		for (int i = n - 1; i >= 0; i--) {
			cost = calcEuclidean(fields[i], fields[n]);
			if (cost < C) continue;
			pq.push(Pipe(i, n, cost));
			pq.push(Pipe(n, i, cost));
		}
	}

	/*printf("----------------\n");

	while (!pq.empty()) {
		printf("%d %d %d\n", pq.top().from, pq.top().to, pq.top().cost);
		pq.pop();
	}
	printf("----------------\n");*/

	while (!pq.empty() && count < N) {
		p = pq.top();
		pq.pop();

		if (v[p.from]) continue;
		v[p.from] = true;
		//v[p.to] = true;
		total += p.cost;
		//printf("%d %d %d\n", p.from, p.to, p.cost);
		count++;
	}

	printf("%d", count == N ? total : -1);
}

int calcEuclidean(pair<int, int>* a, pair<int, int>* b) {
	return pow(a->first - b->first, 2) + pow(a->second - b->second, 2);
}