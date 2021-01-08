#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[1005][1005];
string str1;
string str2;
string result;

int main() {

	string s1, s2;
	cin >> s1 >> s2;

	str1 = '0' + s1;
	str2 = '0' + s2;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (i == 0 || j == 0) {
				dp[i][j] == 0;
				continue;
			}
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int i = str1.length() - 1;
	int j = str2.length() - 1;
	while (dp[i][j] != 0) {
		if (dp[i][j - 1] == dp[i][j])
			j--;
		else if (dp[i - 1][j] == dp[i][j])
			i--;
		else {
			
			result += str1[i];
			i--;
			j--;
		}
	}
	

	cout << dp[str1.length()-1][str2.length()-1] << endl;
	if (result.length() == 0)
	{
		return 0;
	}
	else {
		for (int i = result.length()-1; i >=0; i--) {
			cout << result[i];
		}
	}


}