#include <deque>
#include <iostream>
#include <cstdlib>


int main()
{
	int FRAME_MAX;
	int previousFaults = 10000;
	int anomolies = 0;
	for (int a = 1; a <= 100; ++a) //100 tests of entire process
	{
		std::cout << "Sequence: " << a << std::endl;
		for (int i = 1; i <= 100; ++i) // testing 1 through 100 frames
		{
			int pageFaults = 0;
			FRAME_MAX = i;
			std::deque<int> frames; //frames, going up to 100
			for (int j = 0; j < 1000; ++j)
			{
				int k = rand() % 250 + 1;
				//std::cout << k << " generated.\n";
				//check if the number is already in the frames
				bool inFrame = false;
				for (size_t p = 0; p < frames.size() && !inFrame; ++p)
				{
					if (k == frames[p]) //number is already in frame
					{
						//std::cout << k << " is already in frame.\n";
						inFrame = true;
					}
				}
				if (!inFrame) //number not in frame
				{
					//check if frames are at 100
					if (frames.size() == FRAME_MAX) //frames are full; replace
					{
						pageFaults++;
						//std::cout << "Page fault! " << frames.back() << " replaced by " << k << ".\n";
						frames.pop_back();
						frames.push_front(k);
					}
					else //frames not full
					{
						//std::cout << k << " added to frame.\n";
						frames.push_front(k);
					}
				}
			}
			

			if (pageFaults > previousFaults && FRAME_MAX > 1)
			{
				std::cout << "Frame Max: " << FRAME_MAX - 1 << "; Page Faults: " << previousFaults << ".\n";
				std::cout << "Frame Max: " << FRAME_MAX << "; Page Faults: " << pageFaults << ".\n";
				std::cout << "Anomaly discovered!\n";
				anomolies++;
			}
			previousFaults = pageFaults;
		}
	}
	std::cout << "Anomalies: " << anomolies << std::endl;
}
