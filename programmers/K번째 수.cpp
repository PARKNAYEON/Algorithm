#include<iostream>
#include <string>
#include<algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int _size = commands.size();
    for (int i = 0; i < _size; i++) {
        vector<int> v;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            v.push_back(array[j]);
            cout << array[j];
        }
        sort(v.begin(), v.end());
        int re = commands[i][2];
        answer.push_back(v[re - 1]);

    }



    return answer;
}