//Binary indexed tree demonstration
#include <iostream>

using namespace std;


int get_sum(int BITarr[], int index)
{
    int sum = 0;

    ++index;

    while (index > 0)
    {
        sum += BITarr[index];

        index -= index & (-index);

    }
    return sum;

}


void renew_BIT(int BITarr[], int p, int index, int value)
{
    ++index;

    while (index <= p)
    {
        BITarr[index] += value;

        index += index & (-index);
    }
}

//Build and return a binary indexed tree for given array size.
int *build_BITarr(int arr[], int m)
{
    int *BITarr = new int[m+1];
    for (int i=1; i<=m; i++)
        BITarr[i] = 0;

    for (int i=0; i<m; i++)
        renew_BIT(BITarr, m, i, arr[i]);

    return BITarr;

}


int main()
{
    int nodes[] = {2, 1, 3, 2, 5, 6, 7, 8, 4, 5, 9};

    int n = sizeof(nodes)/sizeof(nodes[0]);

    int *BITarr = build_BITarr(nodes, n);

    cout << "The Sum of elements in arr[0..5] is: "
        << get_sum(BITarr, 5);


    nodes[3] += 6;
    renew_BIT(BITarr, n, 3, 6);

    cout << "\nSum of elements in arr[0..5] after the update is: "
        << get_sum(BITarr, 5) << "\n";

    return 0;

}