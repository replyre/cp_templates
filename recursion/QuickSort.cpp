#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forn(i, n) for (int i = 0; i < int(n); i++)

// freopen('input.txt', 'r', stdin);
// freopen('output.txt', 'w', stdout);

int findPivotPos(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotPos = findPivotPos(arr, low, high);
        QuickSort(arr, low, pivotPos - 1);
        QuickSort(arr, pivotPos + 1, high);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t; while(_t--)
    vector<int> arr = {2, 3, 1, 4, 1, 3, 6};
    QuickSort(arr, 0, arr.size() - 1);
    for (auto a : arr)
        cout << a << " ";
    return 0;
}