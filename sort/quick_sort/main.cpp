#include <iostream>

using namespace std;

//read array
void read(int *a,int length)
{
    for(int i = 0; i < length; ++i)
        cin >> a[i];
}

//print array
void print(int *a,int length)
{
    for(int i = 0; i < length; ++i)
        cout << a[i] << " ";
    cout << endl;
}

//find the partition
int _partition(int *a,int low,int high)
{
    int p = a[high];
    int i = low - 1;
    for(int j = low; j < high; ++j)
    {
        if(a[j] <= p)
        {
            i = i+1;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

//quick sort
void quick_sort(int *a,int low,int high)
{
    if(low < high)
    {
        int p = _partition(a,low,high);
        quick_sort(a,low,p-1);
        quick_sort(a,p+1,high);
    }
}

int main()
{
    int length;
    cout << "please input the length of the array: ";
    cin >> length;
    cout << "please input the value of the array: ";
    int a[length];
    read(a,length);
    quick_sort(a,0,length-1);
    print(a,length);
    return 0;
}
