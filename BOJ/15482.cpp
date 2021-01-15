#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[3050][3050];
string str1;
string str2;

int main() {

	cin >> str1 >> str2;
	size_t s1_size = str1.size();
	size_t s2_size = str2.size();


	for (int i = 3; i <=s1_size; i = i + 3) {
		for (int j = 3; j <= s2_size; j = j + 3) {
			
			if (str1.substr(i-3, 3) == str2.substr(j-3,3)) {
				dp[i][j] = dp[i - 3][j - 3] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 3][j], dp[i][j - 3]);
			}
		}
	}

	/*for (int i = 3; i <= str1.length(); i = i+3) {
		for (int j = 3; j <= str2.length(); j = j +3) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}*/

	cout << dp[s1_size][s2_size] << endl;
	return 0;

}