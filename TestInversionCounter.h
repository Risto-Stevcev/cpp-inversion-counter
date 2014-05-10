#ifndef __TESTMERGESORT_H__
#define __TESTMERGESORT_H__
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "InversionCounter.h"

using namespace std;


class TestInversionCounter : public CppUnit::TestFixture
{
    public:

    void setUp();
    void tearDown();
    void testLength();
    void testIndex();
    void testMerge();
    void testMergesort();
    void testInversions();

    static 
    CppUnit::Test *suite ()
    {
        CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "TestInversionCounter" );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestInversionCounter>( 
                                       "testLength", 
                                       &TestInversionCounter::testLength ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestInversionCounter>( 
                                       "testIndex", 
                                       &TestInversionCounter::testIndex ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestInversionCounter>( 
                                       "testMerge", 
                                       &TestInversionCounter::testMerge ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestInversionCounter>( 
                                       "testMergesort", 
                                       &TestInversionCounter::testMergesort ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestInversionCounter>( 
                                       "testInversions", 
                                       &TestInversionCounter::testInversions ) );

        return suiteOfTests;
    }


    private:

    InversionCounter *inversion_counter;
    int *list;
    int *sorted_list;
    int list_len;
};
#endif
