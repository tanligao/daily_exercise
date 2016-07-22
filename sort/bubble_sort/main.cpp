#include <iostream>

using namespace std;

//read array
void read(int *a,int length)
{
    for(int i = 0; i < length; ++i)
        cin >> a[i];
}

//print array
void print(int *a,int length,int i)
{
    cout << "sort" << i << ": ";
    for(int i = 0; i < length; ++i)
        cout << a[i] << " ";
    cout << endl;
}

//bubble sort
void bubble_sort1(int *a,int length)
{
    for(int i = 0; i < length; ++i)
    {
        for(int j = 0; j < length - i - 1; ++j)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
        print(a,length,i+1);
    }
}

//improve the bubble sort
void bubble_sort2(int *a,int length)
{
    int low = 0;
    int high = length - 1;
    int k;
    while(low < high)
    {
        for(k = low; k < high; ++k)
        {
            if(a[k] > a[k+1])
            {
                swap(a[k],a[k+1]);
            }
        }
        ++low;
        for(k = high; k > low; --k)
        {
            if(a[k] < a[k-1])
            {
                swap(a[k],a[k-1]);
            }
        }
        --high;
        print(a,length,low);
    }
}

int main()
{
    int length;
    cout << "please input the length of the array: ";
    cin >> length;
    int a[length];
    cout << "please input the value of the array: ";
    read(a,length);
    //bubble_sort1(a,length);
    bubble_sort2(a,length);
    print(a,length,length);
    return 0;
}
