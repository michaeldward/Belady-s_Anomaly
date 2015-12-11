#include <deque>
#include <iostream>
#include <cstdlib>

class PageSequence : std::deque<int>
{

};

int main()
{
	for (int q = 0; q < 100; ++q)
	{
		std::deque<int> memory[100];
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < 1000; ++j)
			{
				int k = rand() % 250 + 1;
				memory[i].push_back(k);
				std::cout << k << " ";
			}
			std::cout << "\n\n";
		}
		std::cout << "\n\n\n\n";
	}
}