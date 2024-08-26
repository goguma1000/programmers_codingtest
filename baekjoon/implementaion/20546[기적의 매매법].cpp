#include <iostream>
#include <vector>

using namespace std;
int  calcBNP(const vector<int> prices, int cash) {
	int stocks(0);
	for (int i = 0; i < 14; i++) {
		if (prices[i] <= cash) {
			stocks += cash / prices[i];
			cash %= prices[i];
		}
	}
	return cash + prices[13] * stocks;
}

int calcTIMING(const vector<int> prices, int cash) {
	int stocks(0);
	int down(0);
	int up(0);
	for (int i = 1; i < 14; i++) {
		if (prices[i] < prices[i - 1]) {
			down++;
			up = 0;
		}
		else if (prices[i] > prices[i - 1]) {
			up++;
			down = 0;
		}
		if (down >= 3 && prices[i] <= cash) {
			stocks += cash / prices[i];
			cash %= prices[i];
		}
		else if (up >= 3 && stocks > 0) {
			cash += stocks * prices[i];
			stocks = 0;
		}
	}
	return cash + stocks * prices[13];
}

int main() {
	int cash;
	cin >> cash;
	std::vector<int> prices(14);
	for (int i = 0; i < 14; i++) {
		cin >> prices[i];
	}
	int jun = calcBNP(prices, cash);
	int sung = calcTIMING(prices, cash);
	if (jun > sung) cout << "BNP";
	else if (jun < sung) cout << "TIMING";
	else cout << "SAMESAME";
}
