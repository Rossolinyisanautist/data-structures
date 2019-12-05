#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int calculate(char operation, int a, int b) {
	switch(operation) {
		case '*':
			a *= b;
			break;
		case '/':
			a /= b;
			break;
		case '+':
			a += b;
			break;
		case '-':
			a -= b;
			break;
	}
	return a;
}

int main() {
	vector<string> results;
	vector<int> values;
	string ops = "*/+-";

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				vector<int> nums;
				nums.resize(4,4);

				vector<char> opers;
				opers.push_back(ops[i]);
				opers.push_back(ops[j]);
				opers.push_back(ops[k]);

				for(int l = 0; l < opers.size(); l++) {
					if(opers[l] == '*' || opers[l] == '/') {
						nums[l] = calculate(nums[l], nums[l + 1], opers[l]);
						nums.erase(nums.begin() + l + 1);
						opers.erase(opers.begin() + l);
						l--;
					}
				}

				for(int l = 0; l < opers.size(); l++) {
					nums[l] = calculate(nums[l], nums[l + 1], opers[l]);
					nums.erase(nums.begin() + l + 1);
					opers.erase(opers.begin() + l);
					l--;
				}
				values.push_back(nums[0]);
				string result = "4 " + string(1, ops[i]) + " 4 " + string(1, ops[j]) + " 4 " + string(1, ops[k]) + " 4 " + "= " + to_string(nums[0]);
				results.push_back(result);
			}
		}
	}

	int n;
	cin >> n;
	while(n--) {
		int num;
		cin >> num;
		vector<int>::iterator it = find(values.begin(), values.end(), num);
		if(it != values.end()) {
			int index = distance(values.begin(), it);
			cout << results[index] << '\n';
		}
		else {
			cout << "no solution\n";
		}
	}

}




