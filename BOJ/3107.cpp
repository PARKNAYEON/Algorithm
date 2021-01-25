#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string ip;
string result;

int main() {

	cin >> ip;

	int count = 0;
	int g = 0; //7개가 있어야 함
	//몇개의 그룹이 있는지
	for (int i = 0; i < ip.size(); i++) {
		if (ip[i] == ':') {
			g++;
		}
	}
	
	for (int i = 0; i < ip.size(); i++) {
		count++;
		if (ip[i] == ':') {
			count--;
			if (ip[i + 1] == ':') {
				continue;
			}
			for (int j = 0; j < 4-count; j++) {
				result = result + '0';
			}
			for (int j = count; j > 0; j--) {
				result = result + ip[i-j];
			}
			result = result + ':';
			count = 0;
		}
		if (ip[i] != ':' && i == ip.size() - 1) {
			for (int j = 0; j < 4 - count; j++) {
				result = result + '0';
			}
			for (int j = count-1; j >= 0; j--) {
				result = result + ip[i - j];
			}
		}
	}
	//cout << g << endl;
	cout << result;

	


}