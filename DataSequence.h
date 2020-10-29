#ifndef DataSequence_H
#define DataSequence_H

class DataSequence
        {
 public:
  explicit DataSequence(int n) ; // constructor
  ~DataSequence() ; // destructor
  //DataSequence(DataSequence&) ; // copy constructor

  void setElement(float n);
  void sort();
  void makeHistogram();
  void printArray();
  void getFiveNumberSummary();
  
 protected: // no protected members
  
 private:
  // Data members //
  float* numList;
  int count;
  //int size;
} ;
#endif
