#ifndef __CONCAT_H__
#define __CONCAT_H__

#include "pri.h"

class concat {
private:
    int num;
    pri** pa;
    pri** pa_sort;
    pri** p;
    // You can declare more member variables and member functions here..


public:
    concat(void);
    concat(int* priority, char** words, int n);
    ~concat(void);

    char* concatenate(void);
    char* strcat_(char* result, const char* w);
    void countingSort(pri** A, pri** B, int num, int k);
   
};

#endif
