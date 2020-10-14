#include <cmath>
#include <iostream>
#include "closest.h"
using namespace std;

#if 0

DO NOT MODIFY closest(void), ~closest(void), and setPoints(point* p, int n)!

#endif

closest::closest(void) {
    this->pnt = NULL;
    this->num = 0;
    return;
}

closest::~closest(void) {
    if (this->pnt)   delete this->pnt;
    return;
}

void closest::setPoints(point* p, int n) {
    int i = 0;
    if (this->pnt)   delete this->pnt;
    this->pnt = new point[n];
    this->num = n;
    for (i = 0; i < n; i++)        this->pnt[i] = p[i];
    return;
}

double closest::getMinDist(void) {

    this->minDistance = 100;
    this->pntY = NULL;

    double result;
    heapsort(pnt, num-1);
    
    int j;
    for (j = 0; j < num; j++)
    {
        cout << pnt[j].x << "," << pnt[j].y << endl;
    }
    
    result = divideConquer(pnt, 0, num-1);
    
    return result;
}


void closest:: makeheap(point *pnt, int root, int n) {
    
    int child, temp, tempY, Xtmp, Ytmp;
    temp = pnt[root].x;
    tempY = pnt[root].y;
    child = 2 * root + 1;

    while (child < n)
    {
        if ((child < n-1) && (pnt[child].x < pnt[child+1].x))
            child++;
        if (temp > pnt[child].x)
            break;
        else {
            Xtmp = pnt[child].x;
            Ytmp = pnt[child].y;
            pnt[child].x = pnt[child / 2].x;
            pnt[child].y = pnt[child / 2].y;
            pnt[child / 2].x = Xtmp;
            pnt[child / 2].y = Ytmp;
            child *= 2;
          
        }
    }

    pnt[child / 2].x = temp;
    pnt[child / 2].y = tempY;

}

void closest::makeYheap(point* pnt, int root, int n) {

    int child, temp, tempY, Xtmp, Ytmp;
    temp = pnt[root].x;
    tempY = pnt[root].y;
    child = 2 * root + 1;

    while (child < n)
    {
        if ((child < n - 1) && (pnt[child].y < pnt[child + 1].y))
            child++;
        if (temp > pnt[child].y)
            break;
        else {
            Xtmp = pnt[child].x;
            Ytmp = pnt[child].y;
            pnt[child].x = pnt[child / 2].x;
            pnt[child].y = pnt[child / 2].y;
            pnt[child / 2].x = Xtmp;
            pnt[child / 2].y = Ytmp;
            child *= 2;

        }
    }

    pnt[child / 2].x = temp;
    pnt[child / 2].y = tempY;

}

void closest:: heapsort(point* pnt, int n) {
    
    int i, temp, tempY;
    for (i = n / 2 - 1; i >= 0; i--) {
        makeheap(pnt, i, n);
    }

    for (i = n - 1; i >= 0; i--) {
        temp = pnt[0].x;
        tempY = pnt[0].y;
        pnt[0].x = pnt[i + 1].x;
        pnt[0].y = pnt[i + 1].y;
        pnt[i + 1].x = temp;
        pnt[i + 1].y = tempY;
        makeheap(pnt, 0, i+1);
       
    }
    
}

void closest::heapYsort(point* pnt, int n) {

    int i, temp, tempY;
    for (i = n / 2 - 1; i >= 0; i--) {
        makeYheap(pnt, i, n);
    }

    for (i = n - 1; i >= 0; i--) {
        temp = pnt[0].x;
        tempY = pnt[0].y;
        pnt[0].x = pnt[i + 1].x;
        pnt[0].y = pnt[i + 1].y;
        pnt[i + 1].x = temp;
        pnt[i + 1].y = tempY;
        makeYheap(pnt, 0, i + 1);

    }

}


double closest::divideConquer(point* pnt, int l, int r) {


    if (l == r)
        return 1000000.0;

    int mid = (l + r) / 2;
    double recurMin;
    
    double m1 = divideConquer(pnt, l, mid);
    double m2 = divideConquer(pnt, mid + 1, r);
    recurMin = min(m1, m2);
    //cout << recurMin << endl;
    
    
    double midline = (pnt[mid].x + pnt[mid + 1].x) / 2;
    cout << l << " " << mid << " "<< r << " " <<  midline <<endl;
    
    int midleft = 0;
    int midright = 0;
    

    for (int i = mid; i >= l; i--) {
        if (mid == l) {
            midleft = l;
            break;
        }
        if (pnt[i].x < midline - recurMin/2 ) {
            midleft = i;
            break;
        }
        midleft = mid;
    }
    
    for (int i = mid + 1; i <= r; i++) {
        if (mid + 1 == r) {
            midright = r;
            break;
        }
        if (pnt[i].x > midline + recurMin/2) {
            midright = i;
            break;
        }
        midright = mid + 1;
    }

    this->pntY = new point[abs(midright-midleft)+1];
    //cout << midleft << "midright :  " << midright << endl;
    //cout <<"abs "<< abs(midright) - abs(midleft) + 1 << endl ;
    /*
    for (int i = midleft; i <= midright; i++) {
        pntY[i].x = pnt[i].x;
        pntY[i].y = pnt[i].y;
    }
    cout << pntY[midleft].x;
    */
    
    //cout << midleft << "midright :  " << midright << endl;
    
    for (int i = midleft; i <= mid; i++) {
        //cout << "ddd" << endl;
        for (int j = mid + 1; j <= midright; j++) {
            double len =(pnt[i].x - pnt[j].x)*(pnt[i].x - pnt[j].x) + (pnt[i].y - pnt[j].y)*(pnt[i].y - pnt[j].y);
            if (recurMin > sqrt(len)) {
                recurMin = sqrt(len);
                
            }
           
        }
    }
    
    return recurMin;

}


