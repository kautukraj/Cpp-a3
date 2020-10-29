#ifndef Histogram_H
#define Histogram_H

class Histogram
{
public:
    explicit Histogram(float*, int) ; // constructor
    ~Histogram() ; // destructor
    Histogram(Histogram &histogram); // write a copy constructor

    void compute_binValue();
    void compute_binFreq();
    static bool is_integer(float);

    friend std::ostream& operator<< (std::ostream &, Histogram &) ;

protected: // no protected members

private:
    // Data members //
    float* nums;
    float* binValue;
    int* binFreq;
    const int bins = 10;
    int size;
} ;
#endif
