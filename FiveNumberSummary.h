#ifndef FiveNumberSummary_H
#define FiveNumberSummary_H
#include <iostream>
// declare the class here and the function prototypes

class FiveNumberSummary
{

public:
    explicit FiveNumberSummary(float*, int); // constructor
    ~FiveNumberSummary() ; // destructor
    FiveNumberSummary(FiveNumberSummary&) ; // copy constructor


    // get functions //
    float getMin();
    float getMax();
    float getMedian();
    static float getMedian(float*, int);
    float getLowerQuartile();
    float getUpperQuartile();
    static bool is_integer(float);
    friend std::ostream& operator<< (std::ostream &, FiveNumberSummary &);


private:
    float* nums;
    int n;

    // ostream overload function
};



#endif
