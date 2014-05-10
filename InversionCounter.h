#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <iostream>
using namespace std;


class InversionCounter;
class InversionCounter
{
    public:

    InversionCounter();
    InversionCounter(const int*, int);
    ~InversionCounter();

    friend ostream& operator<< (ostream&, const InversionCounter&);
    int& operator[] (const int index);

    int& length (void);
    long int& inversions (void);

    void merge_and_count (int *, int, int *, int, int *);
    void inversion_counter (void);
    int *_inversion_counter (int *, int);


    private:

    int* list;
    int len;
    long int _inversions;
};


ostream& operator<< (ostream&, const InversionCounter&);
void print_arr(int *, int);
#endif
