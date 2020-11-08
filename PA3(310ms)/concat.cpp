#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "concat.h"
using namespace std;

concat::concat(void) {
    this->num = 0;
    this->pa = 0;
    return;
}

concat::concat(int* priority, char** words, int n) {
    int i = 0;
    this->num = n;
    this->pa = new pri * [n];
    for (i = 0; i < n; i++)        this->pa[i] = new pri(priority[i], words[i]);
    return;
}

concat::~concat(void) {
    if (this->pa) {
        int i = 0, n = this->num;
        for (i = 0; i < n; i++)        if (this->pa[i])         delete this->pa[i];
        delete[] this->pa;
    }
    return;
}

char* concat::concatenate(void) {

    
    char* result = new char[num*num];
    const char* line = "-";

    memset(result, NULL,num*num);
 
   
    this->pa_sort = new pri * [num*num];
    
    
    countingSort(pa, pa_sort, num, 10000000);
    
    int count = 0;
    char* temp = result;
    for (int i = 0; i < num; i++) {
        
    
        if (i == 0) {
            while (*pa_sort[i]->word) {
                count++;
                *temp++ = *pa_sort[i]->word++;
            }
            *temp++ = ' ';
        }
        cout << " coumt" << count << endl;
      for(int i = 0; i < count; i++)
        cout << &temp << endl;

        if (i > 0 && i < num - 1) {
            while (*pa_sort[i]->word) {
                count++;
                *(temp)++ = *pa_sort[i]->word++;
            }
            *temp++ = ' ';
        }
        
        if (i == num - 1) {
            if (strcmp(pa_sort[i]->word, line) == 0) {
            
                /*while (*temp) {
                    
                    temp++;
                   
                }*/
                while (*line) {

                    *temp++ = *(line)++;
                }
                break;
            }
            else {
               
                /*char* temp = result;*/
            
                /*for (int i = 0; i < num; i++) {
                    cout << temp[i] << endl;
                }
                cout << "end" << endl;
                while (*temp) {
                 
                    temp++;
                }*/
                while (*pa_sort[i]->word) {

                    *temp++ = *(pa_sort[i]->word)++;
                }
                break;
            }
        }
       
          //strcat_(result, pa_sort[i]->word);
    }
     

    
   
    return result;
}

char* concat::strcat_(char* result, const char* w) {

    char* temp = result;
    
    
    while (*temp) {
        
        temp++;
    }

    while (*w) {
        
        *temp++ = *w++;
    }
    *temp = ' ';
    
    return result;
}


void concat::countingSort(pri** A, pri** B, int num, int k) {
    

    int* C = new int [k];
    const char* line = "-";

    char** word = new char* [5];
    word[0] = new char[1];
    strcpy(word[0], line);

    cout << word[0] << endl;

    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }

    for (int j = 0; j <= num - 1; j++) {
        C[A[j]->pr] = C[A[j]->pr] + 1;
       
    }

    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    
    for (int h = num - 1; h >= 0; h--) {
        C[A[h]->pr] = C[A[h]->pr] - 1;
        if (h < num / 2) {
            B[C[A[h]->pr]] = new pri(A[h]->pr, word[0]);  
       
        }
        else {
            B[C[A[h]->pr]] = new pri(A[h]->pr, A[h]->word);
       
        }
    }


 
}


