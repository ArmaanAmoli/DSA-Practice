#include <bits/stdc++.h>
using namespace std;

vector<int> decrypt(vector<int> &code, int k)
{
    // circular array
    int n = code.size();

    vector<int> result(n, 0);
    if (k == 0)
        return result;

    int i = 0;
    int nextIdx = ((i + k) % n + n) % n;
    int stIdx = (k > 0) ? (i + 1) % n : (i - 1 + n) % n;
    int sum = 0;
    if (k > 0)
    {
        while (stIdx != nextIdx)
        {
            sum += code[stIdx];
            stIdx = ((stIdx + 1) % n + n) % n;
        }
        sum += code[stIdx];
    }
    else if (k < 0)
    {
        while (stIdx != nextIdx)
        {
            sum += code[stIdx];
            stIdx = ((stIdx - 1) % n + n) % n;
        }
        sum += code[stIdx];
    }

    result[0] = sum;

    // i-th element = i%n th index
    for (int i = 1; i < n; i++)
    {
        sum -= code[stIdx];
        if (k > 0)
        {
            nextIdx= ((nextIdx+1)%n + n )%n;
            stIdx=((stIdx+1)%n + n )%n;
        }
        else if (k < 0)
        {
            nextIdx= ((nextIdx-1)%n + n )%n;
            stIdx=((stIdx-1)%n + n )%n;
        }
        sum += code[nextIdx];
        result[i] = sum;
    }
    return result;
}

int main()
{
}