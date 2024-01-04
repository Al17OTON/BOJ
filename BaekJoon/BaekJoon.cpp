#include <iostream>

using namespace std;

struct QUEEN
{
    int x, y;
};

QUEEN queens[15];

int nQueen(int N, int n, int x, int y)
{
    
}

int main()
{
    int N;
    cin >> N;
    
}


/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int basket[101] = { 0 };

int main()
{
    int N, M, i, j, k;

    cin >> N >> M;

    //int* basket = new int[N + 1];

    for (int n = 0; n < M; n++)
    {
        cin >> i >> j >> k;

        for (int start = i - 1; start < j; start++)
        {
            basket[start] = k;
        }
    }

    for (i = 0; i < N; i++)
    {
        cout << basket[i] << " ";
    }
}*/

/*template <class T> class HEAP
{
    T list[100002] = { 0 };
    int last, count;
public:
    HEAP()
    {
        last = 1; count = 0;
    }
    void Add(T data);

    T Remove();
};

template<typename T>
void HEAP<T>::Add(T data)
{
    T temp;
    int index = last;
    list[index] = data;
    while (index > 1 && list[index] > list[index / 2])
    {
        temp = list[index];
        list[index] = list[index / 2];
        list[index / 2] = temp;
        index /= 2;
    }
    last++; count++;
}

template<typename T>
T HEAP<T>::Remove()
{
    if (count <= 0) return 0;
    T result = list[1], temp;
    int index = 1, child = 2;

    list[1] = list[last - 1];

    while (child < last - 1)
    {
        if (child + 1 < last - 1)
        {
            if (list[child + 1] > list[child])
            {
                child += 1;
            }
        }
        if (list[child] > list[index])
        {
            temp = list[child];
            list[child] = list[index];
            list[index] = temp;
            index = child;
            child *= 2;
        }
        else
        {
            break;
        }
    }

    last--;  count--;
    return result;
}

int main()
{
    HEAP<int>* heap = new HEAP<int>();
    int N, input;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input);
        if (input == 0)
        {
            printf("%d\n", heap->Remove());
        }
        else
        {
            heap->Add(input);
        }
    }

    delete heap;
}*/