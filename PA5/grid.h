#ifndef __GRID_H__
#define __GIRD_H__

class grid {
private:
    int n;
    unsigned long long result;
    int gridArray[100][100];

    // Declare additional variables or functions here if you need...

public:
 
    grid(int n) {
        this->n = n;
        this->result = 0;
    }
    unsigned long long numOfWays(void);
    void gridAlgo(int x, int y);
};

#endif
