#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestSuite.h>
#include "TestInversionCounter.h"


void 
TestInversionCounter::setUp ()
{
    int __list[] = {1,4,5,2,9,44,7,12,34};
    int __sorted_list[] = {1,2,4,5,7,9,12,34,44};

    list_len = sizeof(__list) / sizeof(int);

    list = new int[list_len];
    sorted_list = new int[list_len];

    memcpy( list, __list, sizeof(int)*list_len );
    memcpy( sorted_list, __sorted_list, sizeof(int)*list_len );

    inversion_counter = new InversionCounter( list, list_len );
}


void 
TestInversionCounter::tearDown () 
{
    delete inversion_counter;
    delete[] list;
    delete[] sorted_list;
}


void 
TestInversionCounter::testLength ()
{
    CPPUNIT_ASSERT( inversion_counter->length() == list_len );
}


void 
TestInversionCounter::testIndex ()
{
    for (int i = 0; i < list_len; i++) {
      CPPUNIT_ASSERT( list[i] != 0 );
      CPPUNIT_ASSERT( (*inversion_counter)[i] == list[i] );
    }
}


void
TestInversionCounter::testMerge ()
{
    int left[] = {25260, 29649, 54044};
    int right[] = {2995, 14108, 15232};
    int sorted[] = {2995, 14108, 15232, 25260, 29649, 54044}; 
    int merged[6] = {0};

    inversion_counter->merge_and_count( left, 3, right, 3, merged );

    for (int i = 0; i < 6; i++)
        CPPUNIT_ASSERT( merged[i] == sorted[i] );
}


void
TestInversionCounter::testMergesort ()
{
    int len = inversion_counter->length();

    for (int i = 0; i < len; i++)
        CPPUNIT_ASSERT( (*inversion_counter)[i] == list[i] );

    inversion_counter->inversion_counter();

    for (int i = 0; i < len; i++)
        CPPUNIT_ASSERT( (*inversion_counter)[i] == sorted_list[i] );
}


void
TestInversionCounter::testInversions ()
{
    inversion_counter->inversion_counter();
    CPPUNIT_ASSERT( inversion_counter->inversions() == 6 );
}


int
main ()
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( TestInversionCounter::suite() );
    runner.run();
    return 0;
}
