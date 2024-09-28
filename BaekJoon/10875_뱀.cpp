#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> snake;
int L, N, snake_dir = 0;
int dr[] = { 0, 1, 0, -1 }; //¿À ¾Æ·¡ ¿Þ À§
int dc[] = { 1, 0, -1, 0 };

bool checkOutside(const int& r, const int& c);
bool checkColide(const int& r, const int& c);
int left(const int& dir);
int right(const int& dir);

int main() {
    int t, time = 0, nr = 0, nc = 0;
    char dir;
    bool flag = false;
    snake.push_back(pair<int, int>(nr, nc));
    scanf("%d", &L);
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        scanf("%d %c", &t, &dir);
        t += time;
        for (; time < t; time++) {
            nr += dr[snake_dir];
            nc += dc[snake_dir];
            if (checkOutside(nr, nc) || checkColide(nr, nc)) {
                flag = true;
                break;
            }
            snake.push_back(pair<int, int>(nr, nc));
        }
        if (flag) break;
        snake_dir = dir == 'L' ? left(snake_dir) : right(snake_dir);
    }
    if (!flag) {
        while (!checkOutside(nr, nc) && !checkColide(nr, nc)) {
            nr += dr[snake_dir];
            nc += dc[snake_dir];
            time++;
        }
    }
    printf("%d", time + 1);
}

bool checkOutside(const int& r, const int& c) {
    return r < L * -1 || r > L || c < L * -1 || c > L;
}

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if (op > 0) return 1;
    else if (op == 0) return 0;
    else return -1;
}

bool checkCross(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y) {
    pair<int, int> a = x.first;
    pair<int, int> b = x.second;
    pair<int, int> c = y.first;
    pair<int, int> d = y.second;
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b)swap(a, b);
        if (c > d)swap(c, b);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}


//ÁÖ¾îÁø ÁÂÇ¥°¡ ¹ì ¸öÅë¿¡ Æ÷ÇÔµÇ¾ú´ÂÁö Å½»ö
bool checkColide(const int& r, const int& c) {
    pair<int, int> s;
    for (int i = 0; i < snake.size(); i++) {
        s = snake.at(i);
        if (s.first == r && s.second == c) return true;
    }
    return false;
}

int left(const int& dir) {
    return dir - 1 < 0 ? 3 : dir - 1;
}
int right(const int& dir) {
    return dir + 1 > 3 ? 0 : dir + 1;
}