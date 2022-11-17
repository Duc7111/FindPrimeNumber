
#include<random>
#include<ctime>

int* dataGenerator(int s, int e, int n)
{
    srand(time(NULL));
    int *arr = new int[n], r = e - s + 1;
    for(int i = 0; i < n; ++i)
        arr[i] = s + rand()%r;
    return arr;
}