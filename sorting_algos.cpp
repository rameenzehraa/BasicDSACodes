#include <iostream>
using namespace std;

void printArray(int arr[], int size, string name)
{
    cout << name << ": ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// 1. Bubble Sort
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// 2. Insertion Sort
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// 3. Merge Sort
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int L[50], R[50];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// 4. Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 5. Selection Sort
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

// 6. Heap Sort
void heapify(int arr[], int size, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}
void heapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int A1[] = {64, 34, 25, 12, 22, 11};
    int A2[] = {64, 34, 25, 12, 22, 11};
    int A3[] = {64, 34, 25, 12, 22, 11};
    int A4[] = {64, 34, 25, 12, 22, 11};
    int A5[] = {64, 34, 25, 12, 22, 11};
    int A6[] = {64, 34, 25, 12, 22, 11};
    int size = 6;

    bubbleSort(A1, size);
    insertionSort(A2, size);
    mergeSort(A3, 0, size - 1);
    quickSort(A4, 0, size - 1);
    selectionSort(A5, size);
    heapSort(A6, size);

    printArray(A1, size, "Bubble Sort");
    printArray(A2, size, "Insertion Sort");
    printArray(A3, size, "Merge Sort");
    printArray(A4, size, "Quick Sort");
    printArray(A5, size, "Selection Sort");
    printArray(A6, size, "Heap Sort");

    return 0;
}
