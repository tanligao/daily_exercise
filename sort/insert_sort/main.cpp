#include <iostream>

using namespace std;

//insert sort

void print(int *a,int length,int i)
{
    cout << "sort" << i << ": " ;
    for(int i = 0; i < length; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insert_sort(int *a,int length)
{
    for(int i = 1; i < length; ++i)
    {
        if(a[i] < a[i-1])
        {
            int j = i-1;
            int value = a[i];
            a[i] = a[i-1];
            while(value < a[j])
            {
                a[j+1] = a[j];
                --j;
            }
            a[j+1] = value;
        }
        print(a,length,i);
    }
}

int main()
{
    int length;
    cout << "please input the length of the array: ";
    cin >> length;
    int a[length];
    cout << "please input the value of the array: ";
    for(int i = 0; i < length; ++i)
    {
        cin >> a[i];
    }
    insert_sort(a,length);
    print(a,length,length);
    return 0;
}
