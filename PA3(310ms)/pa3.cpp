#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include"concat.h"
using namespace std;
//"N", "EH", "K", "OWNVE", "PINUY", "JGM", "HRJPWG", "SUCWDA", "H", "EUMKICTXYT", "KCRZJJ", "AF", "JANNYQQH", "HLRTYBZT", "AMDKQVJ","GUCNMN","ZBMSTTPA","JVEKVZL","OO","EJQGRNIFBV","CYG","RBKTiVPOF", "OSJEHQISI", "
//const char* testSet[] = { "A","B","C","D","E","F","G","A","B","C",
//"D","E","F","G","A","B","C","D","E","F",
//"G","A","B","C","D","E","F","G","A","B",
//"C","D","E","F","G","A","B","C","D","E",
//"F","G","A","B","C","D","E","F","G","A",
//"B","C","D","E","F","G","A","B","C","D",
//"E","F","G","A","B","C","D","E","F","G",
//"A","B","C","D","E","F","G","A","B","C"};
//int priority[80] = {8,30,20,30,10,21,20,3,8,9,
//23,18,13,17,23,19,17,19,23,17,
//22,1,9,28,14,17,10,8,12,31,
//20,20,29,8,18,7,29,6,10,6,
//15,1,24,28,18,16,16,3,3,7,
//20,25,8,29,21,22,15,0,30,27,
//31,18,15,28,26,1,3,24,7,13
//,30,22,14,22,19,0,6,3,3,9};

const char* testSet[] = { "XMCQ", "TMVSSXW", "ZBNXSX", "MAMJO", "V", 
"VOUUAY", "EUXBM", "ZI", "YJZVDYS","AEAPOXIL",
"EIOFUUZT","NKV","UT","V","NVIEW",
"GN","DVRR","ZFGV", "HPVUZSTW", "BT"};
int priority[20] = {0,2,1,3,3,0,0,3,2,1,0,3,0,3,0,3,2,2,3,0};


int main(void) {
    int  i = 0;
    char** word = new char* [20];
    char* result = 0;

    for (i = 0; i < 20; i++) {
        word[i] = new char[strlen(testSet[i]) + 1];
        strcpy(word[i], testSet[i]);
    }
    concat* con = new concat(priority, word, 20);
    cout << (result = con->concatenate()) << endl;

    for (i = 0; i < 20; i++)       delete[] * (word + i);
    delete[] word;
    delete con;
    delete[] result;
    return 0;
}


