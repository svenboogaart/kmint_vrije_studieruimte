#pragma once
#include <vector>
class Devider
{
public:
	Devider();
	~Devider();
	bool isDevidable(int input, std::vector<int> deviders);
	std::vector<int> runList(int start, int end,  std::vector<int> deviders);
};

