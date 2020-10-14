#ifndef __CLOSEST_H__
#define __CLOSEST_H__

#include "point.h"

class closest {
private:
    point* pnt;
    point* pntY;
    int num;
    double minDistance;
    double divideConquer(point *pnt, int left, int right);
    void makeheap(point* pnt,int root, int i);
    void heapsort(point* pnt, int n);
    void makeYheap(point* pnt, int root, int n);
    void heapYsort(point* pnt, int n);
    // If you need more member variables or member functions, declare here...

public:
    closest();
    ~closest();

    void setPoints(point* p, int n);
    double getMinDist(void);

};

#endif

