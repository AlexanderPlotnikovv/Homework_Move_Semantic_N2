#include <iostream>
#include <string>
#include <algorithm>

class BigNumbers
{
	std::string first_num;
public:
	BigNumbers(std::string first_num) : first_num(first_num) {}
	BigNumbers() = default;
	BigNumbers(const BigNumbers& num)
	{
		first_num = num.first_num;
	}
	BigNumbers& operator=(const BigNumbers& num)
	{
		if (this == &num)
		{
			return *this;
		}
		else
		{
			first_num = num.first_num;
			return *this;
		}
	}
	BigNumbers(BigNumbers&& num) noexcept
	{
		first_num = std::move(num.first_num);
	}
	BigNumbers& operator=(BigNumbers&& num)
	{
		if (this == &num)
		{
			return *this;
		}
		else
		{
			first_num = std::move(num.first_num);
			return *this;
		}
	}
	BigNumbers operator+(BigNumbers num) const
	{
		std::string firstnum = first_num;
		std::reverse((num.first_num).begin(), (num.first_num).end());
		std::reverse((firstnum).begin(), (firstnum).end());
		std::string strhelp;
		for (int i = 0; i != std::max(num.first_num.size(), firstnum.size())+1; ++i)
		{
			strhelp.push_back('0');
		}
		for (int i = num.first_num.size(); i != strhelp.size(); ++i)
		{
			num.first_num.push_back('0');
		}
		for (int i = firstnum.size(); i != strhelp.size(); ++i)
		{
			firstnum.push_back('0');
		}
		for (int i = 0; i != std::max(num.first_num.size(), firstnum.size()); ++i)
		{
			std::string first_num_elem(1, firstnum[i]);
			std::string num_first_num_elem(1, num.first_num[i]);
			if ((std::stoi(num_first_num_elem) + std::stoi(first_num_elem)) > 9)
			{
				int a = (std::stoi(num_first_num_elem) + std::stoi(first_num_elem)) % 10;
				if (strhelp[i] == '1')
				{
					++a;
				}
				strhelp[i] = std::to_string(a)[0];
				std::string c(1, strhelp[i + 1]);
				strhelp[i+1] = '1';
			}
			else
			{
				int a = (std::stoi(num_first_num_elem) + std::stoi(first_num_elem));
				if (strhelp[i] == '1')
				{
					++a;
				}
				if (a == 10)
				{
					strhelp[i] = '0';
					strhelp[i + 1] = '1';
				}
				else
				{
					strhelp[i] = std::to_string(a)[0];
				}
			}
		}
		while (strhelp[strhelp.size() - 1] == '0')
		{
			strhelp.pop_back();
		}
		std::reverse(strhelp.begin(), strhelp.end());
		//first_num = strhelp;
		return strhelp;
	}
	BigNumbers operator*(const int num) const
	{
		BigNumbers number("0");
		for (int i = 0; i != num; ++i)
		{
			number = *this + number;
		}
		return number;
	}
	friend std::istream& operator>>(std::istream& cin, BigNumbers& num)
	{
		cin >> num.first_num;
		return cin;
	}
	friend std::ostream& operator<<(std::ostream& cout,const BigNumbers& num)
	{
		cout << num.first_num;
		return cout;
	}
};

int main()
{
	auto number1 = BigNumbers("114575");
	auto number2 = BigNumbers("78524");
	auto result = number1 + number2;
	std::cout << result;
	return 0;
}