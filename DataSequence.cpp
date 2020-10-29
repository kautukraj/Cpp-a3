#include <iostream>
#include "DataSequence.h"
#include "Histogram.h"
#include "FiveNumberSummary.h"

// Implementation of DataSequence Class

// Public member functions //
 DataSequence::DataSequence(int n) // constructor
 {
    //this->count = n;
    numList = new float [1000]; // create the array with max size = 1000
    count = 0;
}

DataSequence::~DataSequence() // destructor
{
    delete numList; // delete the pointer
}

void DataSequence::setElement(float number)
{
    numList[count] = number;
    count++;
}

void DataSequence:: makeHistogram()
{

    Histogram histogram (numList, count); // object of class Histogram

    histogram.compute_binValue();
    histogram.compute_binFreq();

    std::cout << histogram; // call the stream object
}


void DataSequence::printArray()
{
    for (int i = 0; i < count; i++)
        std::cout << numList[i] << std::endl;

    std::cout << std::endl;
}

void DataSequence::sort()
{
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < count - 1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i+1; j < count; j++)
            if (numList[j] < numList[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        float temp = numList[min_idx];
        numList[min_idx] = numList[i];
        numList[i] = temp;
    }
}


/*DataSequence::DataSequence(DataSequence &dataSequence) // copy constructor
{
    count = dataSequence.count;
    numList = dataSequence.numList;

    delete numList; // deleting old pointer
}*/

void DataSequence::getFiveNumberSummary()
{
    FiveNumberSummary fiveNumberSummary (numList, count);

    std::cout << fiveNumberSummary; // using overloaded friend function

    return;
}
