#ifndef __MAX_SUM_H__
#define __MAX_SUM_H__

class maxSum {
private:
    int num;
    int* money;
    int q = 0;


    // Declare member variables or functions here if you need...

public:
    maxSum(int n, int* m);
    ~maxSum();
    int max(void);
    int moneyDp(int* money, int n, int* dp);
    int chooseMax(int a, int b);
};

#endif
