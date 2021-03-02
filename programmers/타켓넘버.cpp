#include <string>
#include <vector>
int answer = 0;


using namespace std;


void dfs(vector<int> numbers, int target, int i, int num) {
    if (num == target && i == numbers.size()) {
        answer++;
        return;
    }
    if (i < numbers.size()) {
        dfs(numbers, target, i + 1, num + numbers[i]);
        dfs(numbers, target, i + 1, num - numbers[i]);
    }
}
int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}