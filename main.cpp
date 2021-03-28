#include<iostream>

using namespace std;

int min_val_pos(int i, int n, int arr[100])
{
    int min = arr[i], pos = i;
    for(int k = i+1; k < n; k++)
    {
        if(min > arr[k])
            {
                min = arr[k];
                pos = k;
            }
    }
    return pos;
}

void reverse(int arr[100], int i, int j)
{
    if(i < j)
    {
        while(i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    else
    {
        while(j < i)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
            i--;
        }
    }
}

int cost_reversesort(int arr[100], int n)
{
    int j, sum = 0, iter = 0;
    for(; iter < n-1; iter++)
    {
        j = min_val_pos(iter, n, arr);
        sum += j-iter+1;
        reverse(arr, iter, j);
    }

    return sum;
}

int main()
{
    int t, arr[100], n;
    cin>>t;
    for(int iter = 1; iter <= t; iter++)
    {
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout<<"Case #"<<iter<<": ";
        cout<<cost_reversesort(arr, n)<<endl;
    }

    return 0;
}
