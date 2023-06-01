#include <cstddef>
#include <iostream>
#include "include/FlexArray.h"

int main()
{
    //basic setup: generate a[10] with a[i] = i
    FlexArray<int, 2, 10> myArray(0);
    for(int i = 0; i < myArray.getSize(); i++)
        myArray.set(i, i+1);
    myArray.print();

    //testing a)
    std::cout << std::endl << "iterator test:\n";
    FlexArray<int, 2, 10>::FlexArrayIterator begin = myArray.begin();
    FlexArray<int, 2, 10>::FlexArrayIterator end = myArray.end();
    std::cout << "begin is: " << *begin << std::endl << std::endl;

    //testing b)
    auto increment = begin;
    while (++increment != end)
    {
        std::cout << "increment++ is: " << *increment << std::endl;
    }
    FlexArray<int, 2, 10>::FlexArrayIterator* beginpointer = &begin;
    std::cout << "accessing location of begin pointer copy: " << beginpointer->getLocation() << std::endl;
    std::cout << "end is: " << *end << " (should be some random invalid value)" << std::endl << std::endl;

    //testing c)
    std::cout << "begin[2] is: " << begin[2] << std::endl;
    std::cout << "begin + 2 is: " << *(begin + 2) << std::endl;
    std::cout << "end - 2 is: " << *(end - 2) << std::endl;
    begin += 2;
    std::cout << "begin += 2 is: " << *begin << std::endl;
    begin -= 2;
    std::cout << "begin -= 2 is: " << *begin << std::endl << std::endl;
    
    //testing d)
    std::cout << "begin < end = " << (begin < end) << std::endl;
    std::cout << "begin <= end = " << (begin < end) << std::endl;
    std::cout << "begin > end = " << (begin > end) << std::endl;
    std::cout << "begin >= end = " << (begin > end) << std::endl;
    std::cout << "end < begin = " << (end < begin) << std::endl;
    std::cout << "end <= begin = " << (end < begin) << std::endl;
    std::cout << "end > begin = " << (end > begin) << std::endl;
    std::cout << "end >= begin = " << (end > begin) << std::endl;

    return 0;
}