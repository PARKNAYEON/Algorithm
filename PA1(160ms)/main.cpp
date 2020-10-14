#include <iostream>
#include "inv.h"

using namespace std;
int main(void) {
    inv* inversion = new inv();
    int arr[16] = { 701, 639, 456, 602, 877, 570, 284, 690, 410, 46, 406, 733, 88, 697, 960, 375};
    inversion->reset(arr, 16);
    cout << "Number of Inversions: " << inversion->numOfInv() << endl;
    delete inversion;
    return 0;
}
