// I've used chatGPT to convert output print onto string in line 68

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <limits.h>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <string>
using namespace std;

namespace ariel
{
    TEST_CASE("create containers")
    {
        MagicalContainer container;
        double a = 5.5;
        float b = 6.6;
        int c = 7;
        string d = "8";
        CHECK(container.size() == 0);
        container.addElement(a);
        container.addElement(b);
        container.addElement(c);
        // CHECK_THROWS(container.addElement(d));
        CHECK_EQ(container.size(), 3);
        CHECK_THROWS(container.removeElement(8));
        CHECK_EQ(container.size(), 3);
        CHECK_NOTHROW(container.removeElement(7));
        CHECK_EQ(container.size(), 2);

        
        // Initial boolean variables

    }

    TEST_CASE("Check AscendingIterator Iterator")
    {
        MagicalContainer container;
        CHECK_EQ(container.size(),0);
        container.addElement(17);
        CHECK_EQ(container.size(),1);
        container.addElement(3);
        CHECK_EQ(container.size(),2);
        container.addElement(INT_MAX);
        CHECK_EQ(container.size(),3);
        container.addElement(INT_MIN);
        CHECK_EQ(container.size(),4);
        CHECK_NOTHROW(container.removeElement(17));
        CHECK_EQ(container.size(),3);

        MagicalContainer::AscendingIterator ascIter(container);
        CHECK_EQ(ascIter.begin().get_index(), INT_MIN);
        CHECK_EQ(ascIter.end().get_index(), INT_MAX);
        CHECK_EQ(container.size(), 3);
    };

    TEST_CASE("Check AscendingIterator")
    {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(3);
        container.addElement(INT_MAX);
        container.addElement(INT_MIN);

        MagicalContainer::AscendingIterator ascIter(container);
        CHECK_EQ(ascIter.begin().get_index(), INT_MIN);
        CHECK_EQ(ascIter.end().get_index(), INT_MAX);
        CHECK_EQ(container.size(), 4);
    };

    TEST_CASE("Check PrimeIterator")
    {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(3);
        container.addElement(INT_MAX);
        container.addElement(INT_MIN);
        MagicalContainer::PrimeIterator prIt(container);
        CHECK_EQ(prIt.begin().get_index(), 3);
        CHECK_EQ(prIt.end().get_index(), 3);
        CHECK_EQ(container.size(), 1);
        container.removeElement(3);
    };

    TEST_CASE("Comparesion")
    {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(3);
        container.addElement(INT_MAX);
        container.addElement(INT_MIN);
        MagicalContainer container2;
        container2.addElement(17);
        container2.addElement(3);
        container2.addElement(INT_MAX);
        container2.addElement(INT_MIN);
        CHECK_EQ(container.size(), container2.size());
        MagicalContainer::PrimeIterator prIt(container);
        MagicalContainer::PrimeIterator prIt2(container2);
        CHECK_EQ(prIt.begin().get_index(), prIt2.begin().get_index());
        CHECK_EQ(prIt.end().get_index(), prIt2.end().get_index());
        CHECK_NE(prIt.begin().get_index(), prIt2.end().get_index());
    };

}