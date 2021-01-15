#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[105][105][105];
string str1;
string str2;
string str3;
string real_res;
string result;


int main() {

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	str1 = '0' + s1;
	str2 = '0' + s2;
	str3 = '0' + s3;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			for (int k = 0; k < str3.length(); k++) {
				if (i == 0 || j == 0 || k == 0) {
					dp[i][j][k] == 0;
					continue;
				}
				if (str1[i] == str2[j] && str2[j] == str3[k]) {
					dp[i][j][k] = dp[i - 1][j - 1][k-1] + 1;
				}
				else {
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k-1]);
				}
			}
		}
	}

	cout << dp[str1.length() - 1][str2.length() - 1][str3.length() - 1] << endl;
	
}