#include "maxSum.h"
#include<iostream>
using namespace std;
// DO NOT modify constuctor and distructor...

maxSum::maxSum(int n, int* m) {
    int i = 0;
    if (!m)  return;

    num = n;
    money = new int[n];

    for (i = 0; i < n; i++) {
        money[i] = m[i];
    }
    return;
}

maxSum::~maxSum() {
    if (money) {
        delete[] money;
    }
    return;
}

int maxSum::max(void) {
    int r = 0;
    // Insert source code here...

    int* dp = new int[num+1];

    for (int i = 0; i <= num; i++) {
        dp[i] = -1;
    }
    dp[0] = 0;
    dp[1] = money[0];
    if (num > 2) { 
        dp[2] = money[0] + money[1]; }
    r = moneyDp(money, num, dp);

    return r;
}

int maxSum::moneyDp(int money[], int n, int dp[]) {
    int q = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    if (dp[n] >= 0) {
        return dp[n];
    }

    if (n == 0) {
        q = 0;
    }

   else {
       
        for (int i = 3; i <= n; i++) {
            cout << "money " << ":" << money[i-1] <<"."<<money[i] << endl;
            a = money[i-2] +moneyDp(money, i - 3, dp);
            cout << "a " <<i << ":" << a << endl;
            b = moneyDp(money,i - 2, dp);
            cout << "b :" << b << endl;
            if (a < b) {
                q = b + money[i-1];
                cout << "b에서 q :" << q << endl;
            }
            else {
                q = a + money[i-1];
                cout << "a 에서 q" << a << endl;
            }
            c = moneyDp(money,i-1, dp);
            cout << "c :" << c << endl;
            cout << "q : " << q << endl;
         
            cout << "a " << a << endl;
            if (q < c) {
                  q = c;
              }
         

       }

    }


    dp[n] = q;
    cout << "dp" << n << ":" << dp[n] << endl;
    return q;
}
//// Define additional functions here if you declared in maxSum.h ...
