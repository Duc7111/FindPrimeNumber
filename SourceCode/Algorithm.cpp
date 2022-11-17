
#include<fstream>
#include<math.h>
#include<chrono>

using namespace std;

bool* Eratosthenes(int n)
{
    bool *arr = new bool[n];
    arr[0] = arr[1] = false;
    for(int i = 2; i < n; ++i) arr[i] = true;
    int m = sqrt(n);

    for(int i = 2; i <= m; ++i)
        if(arr[i])
            for(int j = i*i; j < n; j += i) arr[j] = false;
    
    return arr;
}

bool* Sundaram(int n)
{
    int k = (n - 1)/2, m = sqrt(k);
    bool *tarr{new bool[k + 1]{}}, *arr{new bool[n]{}};

    for(int i = 1; i <= m; ++i)
        for(int j = i; i + j + 2*i*j <= k; ++j)
            tarr[i + j + 2*i*j] = true;

    arr[2] = true;
    for(int i = 1; i <= k; ++i)
        if(!tarr[i]) arr[2*i + 1] = true;

    delete[] tarr;
    return arr;
}

bool* Atkin(int n)
{
    int m = sqrt(n);
    bool *arr{new bool[n]{}}, hash[60] = {};

    hash[1] = hash[13] = hash[17] = hash[29] = hash[37] = hash[41] = hash[49] = hash[53] = true;
    for(int x = 1; x <= m; ++x)
        for(int y = 1; y <= m; y += 2)
        {
            int k = 4*x*x + y*y;
            if(k < n && hash[k%60]) 
                arr[k] = !arr[k];
        }
    hash[1] = hash[13] = hash[17] = hash[29] = hash[37] = hash[41] = hash[49] = hash[53] = false;

    hash[7] = hash[19] = hash[31] = hash[43] = true;
    for(int x = 1; x <= m; x += 2)
        for(int y = 2; y <= m; y += 2)
        {
            int k = 3*x*x + y*y;
            if(k < n && hash[k%60]) 
                arr[k] = !arr[k];
        }
    hash[7] = hash[19] = hash[31] = hash[43] = false;

    hash[11] = hash[23] = hash[47] = hash[59] = true;
    for(int x = 2; x <= m; ++x)
        for(int y = x - 1; y > 0; y -= 2)
        {
            int k = 3*x*x - y*y;
            if(k < n && hash[k%60]) 
                arr[k] = !arr[k];
        }

    int size = (n/60 + 1)*16, *S{new int[size]{1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59}};
    for(int i = 16; i < size; ++i)
        S[i] = S[i - 16] + 60;

    for(int i = 1; i < size; ++i)
    {
        int k = S[i]*S[i];
        if(k > n) break;
        if(arr[S[i]])
            for(int j = 0; j < size; ++j)
            {
                long long o = k*S[j];
                if(o >= n) break;
                arr[o] = false;
            }
    }

    arr[2] = arr[3] = arr[5] = true;

    return arr;
}