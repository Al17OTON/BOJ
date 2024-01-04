#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define MAX 101

using namespace std;

typedef struct INPUT
{
	int x;
	char c;
};

INPUT com[MAX];	//뱀의 이동 명령

int map[MAX][MAX] = { 0 };
int N, K, L;
int dirX[4] = { -1, 0, 1, 0 };	//상우하좌 , 90도씩 오른쪽으로 회전했을때
int dirY[4] = { 0, 1, 0, -1 };
int dir = 1;	//오른쪽을 향한상태가 기본

void debug(int time)
{
	cout << time << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

int sim()
{
	int time = 1; //시간경과
	int c = 0;	//명령어 인덱스
	int x = 1, y = 1; //뱀 머리위치
	int tx = 1, ty = 1; //뱀 꼬리 위치
	int xx, yy;	//한칸 이동했을때 위치
	bool apple;
	//debug(time);
	while (1)
	{
		apple = false;
		xx = x + dirX[dir]; yy = y + dirY[dir];
		if (xx > N || xx <= 0 || yy > N || yy <= 0 || map[xx][yy] > 0 )	//앞으로 진행했을때 충돌여부 조사, 1 이상이라면 뱀을 만난것
		{
			return time; //게임 끝난 시점의 시간
		}
		if (map[xx][yy] == -1) apple = true;	//사과 먹기
		map[xx][yy] = time + 1;	//시간을 넣어서 뱀표시
		x = xx; y = yy;	//머리 변경
		if (!apple)	//사과를 먹은게 아니라면 꼬리 삭제
		{
			for (int i = 0; i < 4; i++)	//4방향에서 자기 자신보다 1큰 숫자가 꼬리가 됨.
			{
				if (map[tx + dirX[i]][ty + dirY[i]] == map[tx][ty] + 1)
				{
					map[tx][ty] = 0;	//꼬리 비우기
					tx = tx + dirX[i]; ty = ty + dirY[i];
					break;
				}
			}
		}

		if (c < L && com[c].x == time)	//명령입력이 있다면 방향전환
		{
			if (com[c].c == 'D')	//오른쪽
			{
				dir += 1;
				if (dir == 4) dir = 0;
			}
			else //왼쪽
			{
				dir -= 1;
				if (dir == -1) dir = 3;
			}
			c++;
		}
		//debug(time);
		time++;
	}
}

int main()
{
	int i, x, y;
	char d;
	scanf("%d", &N);
	scanf("%d", &K);

	for (i = 0; i < K; i++)	//사과 위치
	{
		scanf("%d %d", &x, &y);
		map[x][y] = -1;
	}
	map[1][1] = 1;	//주의, 문제에서는 맨 위 맨 왼쪽이라고 적혀있는데 0,0가 아니라 1,1이다.

	scanf("%d", &L);
	for (i = 0; i < L; i++)	//명령어 입력받기
	{
		scanf("%d %c", &x, &d);
		com[i].x = x;
		com[i].c = d;
	}

	i = sim();
	cout << i << endl;
}