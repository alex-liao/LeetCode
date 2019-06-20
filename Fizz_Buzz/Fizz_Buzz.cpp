// Fizz_Buzz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

class Solution
{
public:
	std::vector<std::string> fizzbuzz(int n)
	{
		for (int i=1; i <= n; i++)
		{
			std::string item = "";

			if (is_divisible_by_five(i) && is_divisible_by_three(i))
			{
				item = "FizzBuzz";
			}
			else if (is_divisible_by_three(i))
			{
				item = "Fizz";
			}
			else if (is_divisible_by_five(i))
			{
				item = "Buzz";
			}
			else
			{
				item = std::to_string(i);
			}
			_output.push_back(item);
		}

		for (std::vector<std::string>::iterator it = _output.begin(); it != _output.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}

private:
	bool is_divisible_by_three(int n)
	{
		return (n % 3) == 0;
	}

	bool is_divisible_by_five(int n)
	{
		return (n % 5) == 0;
	}

	std::vector<std::string> _output;
};

int main()
{
	Solution soln;
	soln.fizzbuzz(15);

	return 0;
}