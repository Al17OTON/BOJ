#include<iostream>
#define MAX 15

using namespace std;

int map[MAX][MAX];
int N, M;

/// <summary>
/// 특정좌표를 파리채로 내려쳤을때, 잡힌 파리 수 계산
/// </summary>
/// <param name="a">시작 좌표xy</param>
/// <param name="b">시작 좌표xy</param>
/// <returns>해당 좌표에서 M만큼 더한 범위 내 파리 수 반환</returns>
int smash(int a, int b) {  
    int result = 0;
    for (int i = a; i < a + M; i++) {
        for (int j = b; j < b + M; j++) {
            result += map[i][j];
        }
    }
    return result;
}

/// <summary>
/// 브루트포스를 사용하여 파리채를 내리칠 수 있는 모든 경우를 계산
/// </summary>
/// <returns>가장 많은 파리수를 반환</returns>
int bruteForce() {
    int tmp, result = 0;

    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            tmp = smash(i, j);
            if (tmp > result) result = tmp;
        }
    }
    return result;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        cout << "#" << test_case << " " << bruteForce() << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}