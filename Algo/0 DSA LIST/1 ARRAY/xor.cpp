// C++ program to get total
// xor of all subarray xors
#include <bits/stdc++.h>
using namespace std;

// Returns XOR of all subarray xors
int xordsflkj(int arr[], int N)
{
    int res = 0;

    for (int i = 0; i < N; i++)
    {
        int freq = (i + 1) * (N - i);

        cout << arr[i] << " " << freq << endl;

        if (freq % 2 == 1)
            res = res ^ arr[i];
    }

    return res;
};

// Driver Code
int main()
{
    int arr[] = {3, 5, 2, 4, 6};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << xordsflkj(arr, N);
    return 0;
}
