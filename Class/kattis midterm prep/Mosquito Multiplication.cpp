#include<iostream>

using namespace std;

int main() {
	int mosq, pupae, larvae, eggs, rateLarva, ratePupae, weeks;
	while(cin >> mosq >> pupae >> larvae >> eggs >> rateLarva >> ratePupae >> weeks) {
		for (int i = 0; i < weeks; ++i) {
			int newMosq, newPupae, newLarvae;
			newMosq = pupae / ratePupae;
			newPupae = larvae / rateLarva;
			newLarvae = eggs * mosq;

			mosq = newMosq;
			larvae = newLarvae;
			pupae = newPupae;
		}
		cout << mosq << '\n';
	}
	
}