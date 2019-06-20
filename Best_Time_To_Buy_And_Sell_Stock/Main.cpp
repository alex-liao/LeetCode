#include <string>
#include <iostream>
#include <vector>

// Problem: Best Time To Buy And Sell Stock

// «ä¸ô: 



class Solution {
public:
	int maxProfit(std::vector<int>& prices) {
		int max_profit = 0;

		// special handling empty input and single element input
		if (!prices.size() || prices.size() == 1)
			return max_profit;

		for (int i = 0; i < prices.size()-1; i++)
		{
			int buy = prices[i];
			for (int j = i + 1; j < prices.size(); j++)
			{
				int sell = prices[j];
				int profit = sell - buy;
				if (profit > max_profit)
					max_profit = profit;
			}
		}

		return max_profit;
	}
};

int main()
{
	Solution *soln = new Solution();

	// data initialization
	std::vector<int> prices;
	prices.push_back(7);
	prices.push_back(6);
	prices.push_back(4);
	prices.push_back(3);
	prices.push_back(1);

	std::cout << soln->maxProfit(prices) << std::endl;

	return 0;
}