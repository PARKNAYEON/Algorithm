#include "grid.h"
#include <iostream>
using namespace std;

unsigned long long grid::numOfWays(void) {
    result = 0;
    cout << " ";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            gridArray[i][j] = 0;
          
        }
    }

    gridAlgo(0, 0);
    
    return result;
}

void grid::gridAlgo(int x, int y) {

    gridArray[x][y] = 1;
    cout << x << "," << y << endl;

    if (x == n && y == n) {
        result++;
        gridArray[x][y] = 0;
        cout << "Result " << result << endl;
        return;
    }
    if (x != n && gridArray[x + 1][y] == 0) {
        gridAlgo(x + 1, y);
        //gridArray[x][y] = 0;
    }
    if (y != n && gridArray[x][y + 1] == 0) {
        gridAlgo(x, y + 1);
        //gridArray[x][y] = 0;
    }
    if (x > 0 && gridArray[x - 1][y] == 0) {
        gridAlgo(x - 1, y);
        //gridArray[x][y] = 0;
    }
    if (y > 0 &&gridArray[x][y - 1] == 0) {
        gridAlgo(x, y - 1);
        //gridArray[x][y] = 0;
    }

    gridArray[x][y] = 0;

}


// Define here if you declared additional functions...
