#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int m, int arr2[], int n)
{
    int i = m - 1;     // Pointer for the first array
    int j = n - 1;     // Pointer for the second array
    int k = m + n - 1; // Pointer for the merged array
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] >= arr2[j])
        {
            arr1[k] = arr1[i];
            i--;
        }
        else
        {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }
    while (j >= 0)
    {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}
int main()
{
    int m, n;
    cout << "Enter the number of elements in the first array: ";
    cin >> m;
    int arr1[m];
    cout << "Enter the elements of the first array in non-increasing order:" << endl;
    for (int i = 0; i < m; ++i)
    {
        cin >> arr1[i];
    }
    cout << "Enter the number of elements in the second array: ";
    cin >> n;
    int arr2[n];

    cout << "Enter the elements of the second array in non-increasing order:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr2[i];
    }

    mergeArrays(arr1, m, arr2, n);
    cout << "Merged array in non-increasing order:" << endl;
    for (int i = 0; i < m + n; ++i)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    return 0;
}
