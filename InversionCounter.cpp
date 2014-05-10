#include <iostream>
#include <cmath>
#include "InversionCounter.h"

using namespace std;


InversionCounter::InversionCounter()
{
    list = new int[0];
    len = _inversions = 0;
}


InversionCounter::InversionCounter (const int* t, int length)
{
    if (t) {
        len = length;
        _inversions = 0;

        list = new int[len];
        for (int i = 0; i < length; i++)
            list[i] = t[i];
    }
    else {
        list = new int[0];
        len = _inversions = 0;
    }
}


InversionCounter::~InversionCounter()
{
    delete[] list;
}


ostream& 
operator<< (ostream& os, const InversionCounter& ms)
{
    if (ms.len >= 1)
        os << ms.list[0];

    for (int i = 1; i < ms.len; i++)
        os << ", " << ms.list[i];

    os << endl;
    return os;
}


int& 
InversionCounter::operator[] (const int index)
{
    return list[index];
}


int& 
InversionCounter::length (void)
{
    return len;
}


long int&
InversionCounter::inversions (void)
{
    return _inversions;
}


void
print_arr(int *l, int len)
{
    for (int i = 0; i < len; i++)
        cout << l[i] << " ";
    cout << endl;
}


void
InversionCounter::merge_and_count (int *subarr1, int subarr1_len, 
                  int *subarr2, int subarr2_len, 
                  int *arr)
{
    for (int i = 0, i1 = 0, i2 = 0; i1 < subarr1_len || i2 < subarr2_len; i++) {
        if (i1 < subarr1_len && i2 < subarr2_len) {
            if (subarr1[i1] <= subarr2[i2])
                arr[i] = subarr1[i1++];
            else {
                arr[i] = subarr2[i2++];
                inversions() = inversions() + (subarr1_len - i1);
            }
        }
        else if (i1 < subarr1_len)
            arr[i] = subarr1[i1++];
        else if (i2 < subarr2_len)
            arr[i] = subarr2[i2++];
    }
}


int *
InversionCounter::_inversion_counter (int *arr, int arrlen)
{
    if (arrlen <= 1)
        return arr;

    int middle = arrlen / 2;
    int *left = arr;
    int *right = arr + middle;

    left = _inversion_counter( left, middle );
    right = _inversion_counter( right, arrlen - middle );

    /* copy subarrays into local arrays for merge */
    int l[middle];
    int r[arrlen - middle];
    for (int i = 0; i < middle; i++, left++)
        l[i] = *left;
    for (int i = 0; i < arrlen - middle; i++, right++)
        r[i] = *right;

    merge_and_count( l, middle, r, arrlen - middle, arr );
    return arr;
}


void
InversionCounter::inversion_counter ()
{
    _inversion_counter( list, len );
}
