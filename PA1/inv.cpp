#include <iostream>
#include "inv.h"

#define MODE 0

using namespace std;
inv::inv() {
	this->array = NULL;
	this->size = 0;
	this->count = 0;
	this->array2 = NULL;

}
inv::~inv() {
	if (this->array)	delete this->array;
	if (this->array2) delete this->array2;
	//	if(this->array3) delete this->array3;

	return;
}
void inv::reset(int* a, int s) {
	int i = 0;
	if (this->array)	delete this->array;
	if (this->array2) delete this->array2;
	//	if(this->array3) delete this->array3;
	this->array = new int[s];
	this->size = s;
	this->array2 = new int[s];
	//	this->array3 = new int[s+1];
	for (i = 0;i < s;i++)	*(this->array + i) = *(a + i);
	return;
}
void inv::printArray(void) {
	int i = 0;
	for (i = 0;i < size;i++)	cout << *(this->array + i) << " ";
	cout << endl;
}
int inv::numOfInv(void) {
	//Input source code here...
	mergeSort(array, array2, 0, size - 1);
	return count;
}

void inv::mergeSort(int inv[], int inv2[], int p, int r) {

	int q;//중간값

	if (p < r) {
		q = (p + r) / 2;
		mergeSort(inv, inv2, p, q);
		mergeSort(inv, inv2, q + 1, r);
		merge(inv, inv2, p, q, r);
	}
}

void inv::merge(int inv[], int inv2[], int p, int q, int r) {

	int i = p;
	int j = q + 1;
	int k = p;

	while (i <= q && j <= r) {
		if (inv[i] <= inv[j]) {
			inv2[k++] = inv[i++];

		}

		else {
			inv2[k++] = inv[j++];
			count = count + q - i + 1;
		}
	}
	int temp = 0;
	if (i <= q)
		temp = i;
	else
		temp = j;

	while (k <= r) {
		inv2[k++] = inv[temp++];
	}

	for (int i = p; i <= r; i++) {
		inv[i] = inv2[i];
	}


}

// If you declared additional methods, define here...

