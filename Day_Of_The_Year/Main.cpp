#include <string>

using namespace std;

class Solution {
public:
	int dayOfYear(string date) {
		unsigned int year = std::stoi(date.substr(0, 4));
		unsigned int month = std::stoi(date.substr(5, 2));
		unsigned int day = std::stoi(date.substr(8, 2));

		unsigned int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		unsigned int leap_feb_days = 29;

		// work out the total number of days before the given month
		int day_of_year = 0;
		for (unsigned int i = 0; i < (month - 1); i++) {
			// if february, need to check for leap year
			if (i == 1) {
				if (isLeapYear(year)) {
					day_of_year += leap_feb_days;
				}
				else {
					day_of_year += days_in_month[i];
				}
			}
			else {
				day_of_year += days_in_month[i];
			}
		}

		// finally, add-in the remaining days counting from this month
		day_of_year += day;

		return day_of_year;
	}

	bool isLeapYear(int year) {
		if (year % 4 != 0) {
			return false;
		}
		else {
			if (year % 100 == 0) {
				if (year % 400 == 0) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return true;
			}
		}
	}
};