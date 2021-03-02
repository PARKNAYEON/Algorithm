#include <string>
#include <vector>
#include<algorithm>


using namespace std;
int answer = 987654321;
void dfs(int N, int number, int i, int sum) {
    if (i > 8)
        return;
    if (sum == number) {
        answer = min(i, answer);
    }
    int temp = 0;
    for (int j = 0; j < 8; j++) {
        temp = temp * 10 + N;
        dfs(N, number, i + j + 1, sum + temp);
        dfs(N, number, i + j + 1, sum - temp);
        dfs(N, number, i + j + 1, sum * temp);
        dfs(N, number, i + j + 1, sum / temp);
    }
}

int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if (answer > 8)
        return -1;
    else
        return answer;
}