#include <iostream>
#include <iomanip>
#include <cmath>
#include "Histogram.h"

// Implementation of Histogram Class

// Public member functions
Histogram:: Histogram(float* arr, int size)
{
    this->nums = arr;
    this->size = size;
    binValue = new float [bins+1];
    binFreq = new int [bins];

    for (int i = 0; i < bins; i++)
        binFreq[i] = 0;

}

Histogram::~Histogram() // destructor
{
    delete Histogram::binValue; // delete pointers
    delete Histogram::binFreq;
}

void Histogram:: compute_binValue()
{
    float min = nums[0];
    float max = nums[size - 1];
    float width = (max - min) / float(bins);

    binValue[0] = min;
    for (int i = 1; i  < bins + 1; i++)
    {
        binValue[i] = binValue[i-1] + width;
    }

    /*std::cout << "hello\n";
    for (int i = 0; i < bins; i++)
        std::cout << binValue[i] << ",";

    std::cout << binValue[bins] << " -1 \n";*/

}

void Histogram:: compute_binFreq()
{
    for (int i = 0; i < bins; i++)
    {
        //std::cout << binValue[i] << " " << binValue[i+1] << std::endl;
        for (int j = 0; j < size; j++)
        {
            //std::cout << "Value = " << nums[j] << std::endl;
            if (nums[j] >= binValue[i] && nums[j] < binValue[i+1])
            {
                //std::cout << "Allowed = " << nums[j] << std::endl;
                binFreq[i] += 1;
            }
        }
    }
}

 Histogram::Histogram(Histogram &oldCopy) // copy constructor
{
    nums = oldCopy.nums;
    //bins = oldCopy.bins;
    size = oldCopy.size;
    binValue = oldCopy.binValue;
    binFreq = oldCopy.binFreq;

    // deleting old pointers
    delete binValue;
    delete binFreq;
}



std::ostream &operator<< (std::ostream& os, Histogram& histogram)
{
    for (int i = 0; i < histogram.bins; i++)
    {
        if (Histogram::is_integer(histogram.binValue[i]))
        {
            os << std::fixed << std::setprecision(1) << histogram.binValue[i] << ",";
            os.unsetf(std::ios::fixed | std::ios::scientific);
        }
        else
            os << std::setprecision(5) << histogram.binValue[i] << ",";
    }

    if (Histogram::is_integer(histogram.binValue[histogram.bins]))
    {
        os << std::fixed << std::setprecision(1) << (float) histogram.binValue[histogram.bins] << " ";
        os.unsetf(std::ios::fixed | std::ios::scientific);
    }
    else
    {
        os << std::setprecision(5) << (float) histogram.binValue[histogram.bins] << " ";
    }



    for (int i = 0; i < histogram.bins - 1; i++)
    {
        if (Histogram::is_integer(histogram.binFreq[i] / (float) histogram.size))
        {
            os << std::fixed << std::setprecision(1) << histogram.binFreq[i] / (float) histogram.size << ",";
            os.unsetf(std::ios::fixed | std::ios::scientific);
        }
        else
        {
            os << std::setprecision(5) << histogram.binFreq[i] / (float) histogram.size << ",";
        }
    }

    if (Histogram::is_integer(histogram.binFreq[histogram.bins - 1] / (float) histogram.size))
    {
        os << std::fixed << std::setprecision(1) << histogram.binFreq[histogram.bins - 1]/(float)histogram.size << " -1 ";
        os.unsetf(std::ios::fixed | std::ios::scientific);
    }
    else
        os << std::setprecision(5) << histogram.binFreq[histogram.bins - 1]/(float)histogram.size << " -1 ";


    return os;
}

bool Histogram::is_integer(float k)
{
    //std::cout << std::floor(k) << std::endl;
    //std::cout << k << std::endl;
    return std::floor(k) == k;
}

