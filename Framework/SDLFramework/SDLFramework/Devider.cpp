#include "Devider.h"



Devider::Devider()
{
}


Devider::~Devider()
{
}

bool Devider::isDevidable(int input, std::vector<int> deviders)
{
	for (int devider : deviders)
	{
		if(input % devider == 0)
		{
			return true;
		}
	}
	return false;
}

std::vector<int> Devider::runList(int start, int end, std::vector<int> deviders)
{
	std::vector<int>input = std::vector<int>(start, end);

	std::vector<int> returnVal;
	for (int v : input)
	{
		if (isDevidable(v, deviders))
		{
			//only add if not in returnVal already
			returnVal.push_back(v);
			//remove from original
			
		}
	}
	return returnVal;
}
