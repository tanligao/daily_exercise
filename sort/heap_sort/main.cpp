#include <iostream>

using namespace std;

//max heap
//heap sort

//read array
void read(int *a, int length)
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

//modify the heap when insert or delete the node
//find the max of the node's childs and then exchange
void modify_heap(int *a,int s,int length)
{
    int left = 2*s+1,right = 2*s+2;
    int max_index = s;
    if(left < length && a[left] > a[max_index])
    {
        max_index = left;
    }
    if(right < length && a[right] > a[max_index])
    {
        max_index = right;
    }
    if(max_index != s)
    {
        swap(a[s],a[max_index]);
        modify_heap(a,max_index,length);
    }
}

//build the heap,first to find the node who have child node
void build_heap(int *a,int length)
{
    for(int i = (length-1)/2; i >= 0; --i)
    {
        modify_heap(a,i,length);
        print(a,length);
    }
}

//heap sort
//every time to exchange the first and the 'end'
void heap_sort(int *a,int length)
{
    for(int i = length-1; i >= 1; --i)
    {
        swap(a[i],a[0]);
        modify_heap(a,0,i);
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
    build_heap(a,length);
    heap_sort(a,length);
    print(a,length);
    return 0;
}
