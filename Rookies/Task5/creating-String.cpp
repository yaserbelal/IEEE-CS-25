#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#define ll long long
using namespace std;
void creatingStrings(string s, set<string>& strings, int left, int right) {
	if (left == right) {
		strings.insert(s);
		return;
	}
	for (int i = left; i <= right; i++) {
		swap(s[left], s[i]);
		creatingStrings(s, strings, left + 1, right);
		swap(s[left], s[i]);
	}
}

int main() {
	string str;
	cin >> str;

	set<string> strings;
	creatingStrings(str, strings, 0, str.size() - 1);

	cout << strings.size() << endl;

	for (const auto& str : strings)
	{
		cout << str << endl;
	}

	return 0;
}

