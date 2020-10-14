#ifndef __INV_H__
#define __INV_H__

class inv {
private:
	int* array;
	int size;
	int count;
	int* array2;

	// If you need more attributes or methods, declare here...


public:
	inv(void);
	~inv();
	void reset(int* a, int s);
	void printArray(void);
	int numOfInv(void);
	void mergeSort(int inv[], int inv2[], int p, int r);
	void merge(int inv[], int inv2[], int p, int q, int r);
};

#endif

