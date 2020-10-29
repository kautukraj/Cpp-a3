// implement FiveNumberSummary here
#include "FiveNumberSummary.h"
#include <cmath>
#include <iostream>
#include <iomanip>


bool FiveNumberSummary::is_integer(float k)
{
    return std::floor(k) == k;
}


FiveNumberSummary::FiveNumberSummary(float* nums, int n)
{
    this->nums = nums;
    this->n = n;
}

FiveNumberSummary::~FiveNumberSummary()
{
    delete nums;
}

FiveNumberSummary::FiveNumberSummary(FiveNumberSummary &fiveNumberSummary)
{
    nums = fiveNumberSummary.nums;
    n = fiveNumberSummary.n;

    delete nums;
}


float FiveNumberSummary::getMin()
{
    return nums[0];
}

float FiveNumberSummary::getMax()
{
    return nums[n - 1];
}

float FiveNumberSummary::getMedian()
{
    if (n % 2 != 0)
        return nums[n / 2];
    else
        return (nums[(n - 1) / 2] + nums[n / 2]) / 2;
}


float FiveNumberSummary::getMedian(float arr[], int size)
{
    if (size % 2 != 0)
        return arr[size / 2];
    else
        return (arr[(size - 1) / 2] + arr[size / 2]) / 2;
}

float FiveNumberSummary::getLowerQuartile()
{
    if (n % 2 != 0) // n is odd
    {
        int partition = n / 2 + 1;
        float lower [partition];
        for (int i = 0; i < partition; i++)
        {
            lower[i] = nums[i];
        }

        return getMedian(lower, partition);

    }
    else // n is even
    {
        int partition = n / 2;
        float lower [partition];
        for (int i = 0; i < partition; i++)
        {
            lower[i] = nums[i];
        }

        return getMedian(lower, partition);
    }

}

float FiveNumberSummary::getUpperQuartile()
{
    if (n % 2 != 0) // n is odd
    {
        int partition = n / 2 + 1;
        int count = 0;
        float upper [partition];
        for (int i = partition - 1; i < n; i++)
        {
            upper[count++] = nums[i];
        }

        return getMedian(upper, partition);

    }
    else
    {
        int partition = n / 2;
        int count = 0;
        float upper [partition];
        for (int i = partition; i < n; i++)
        {
            upper[count++] = nums[i];
        }

        return getMedian(upper, partition);
    }
}


std::ostream& operator<< (std::ostream& os, FiveNumberSummary& fns) // overloaded friend function
{
    /*os << fns.getMin() << "," << fns.getLowerQuartile() << "," << fns.getMedian() << "," << fns.getUpperQuartile()
    << "," << fns.getMax() << " ";*/

    if (FiveNumberSummary::is_integer(fns.getMin()))
    {
        os << std::fixed << std::setprecision(1) << fns.getMin() << ",";
        os.unsetf(std::ios::fixed | std::ios::scientific);
    }
    else
        os << std::setprecision(5) << fns.getMin() << ",";

    if (FiveNumberSummary::is_integer(fns.getLowerQuartile()))
    {
        os << std::fixed << std::setprecision(1) << fns.getLowerQuartile() << ",";
        os.unsetf(std::ios::fixed | std::ios::scientific);
    }
    else
        os << std::setprecision(5) << fns.getLowerQuartile() << ",";

    if (FiveNumberSummary::is_integer(fns.getMedian()))
    {
        os << std::fixed << std::setprecision(1) << fns.getMedian() << ",";
        os.unsetf(std::ios::fixed | std::ios::scientific);
    }
    else
        os << std::setprecision(5) << fns.getMedian() << ",";

    if (FiveNumberSummary::is_integer(fns.getUpperQuartile()))
    {
        os << std::fixed << std::setprecision(1) << fns.getUpperQuartile() << ",";
        os.unsetf(std::ios::fixed | std::ios::scientific);
    }
    else
        os << std::setprecision(5) << fns.getUpperQuartile() << ",";

    if (FiveNumberSummary::is_integer(fns.getMax()))
    {
        os << std::fixed << std::setprecision(1) << fns.getMax() << " ";
        os.unsetf(std::ios::fixed | std::ios::scientific);
    }
    else
        os << std::setprecision(5) << fns.getMax() << " ";


    return os;
}