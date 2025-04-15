#include <iostream>
#include <algorithm>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return true;
    return false;
}

bool binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return true;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

int main()
{
    int arr[] = {10, 5, 30, 25, 15, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    // Linear Search
    if (linearSearch(arr, size, key))
        cout << "Element found using Linear Search.\n";
    else
        cout << "Element not found using Linear Search.\n";

    // Binary Search (array must be sorted)
    sort(arr, arr + size);
    if (binarySearch(arr, size, key))
        cout << "Element found using Binary Search.\n";
    else
        cout << "Element not found using Binary Search.\n";

    return 0;
}
