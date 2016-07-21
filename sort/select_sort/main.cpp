#include <iostream>

using namespace std;

//select sort

//print the array element
void print(int *a,int length,int i)
{
    cout << "sort" << i << ": ";
    for(int i = 0; i < length; ++i)
        cout << a[i] << " ";
    cout << endl;
}

//select sort function
void select_sort(int *a,int length)
{
    for(int i = 0; i < length; ++i)
    {
        int index = i,max_value = a[i];
        for(int j = i; j < length; ++j)
        {
            if(max_value > a[j])
            {
                index = j;
                max_value = a[j];
            }
        }
        swap(a[i],a[index]);
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
        cin >> a[i];
    select_sort(a,length);
    print(a,length,length);
    return 0;
}
