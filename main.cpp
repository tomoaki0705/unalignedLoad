#include <iostream>
#include "load.hpp"

char workArea[2048] = {0};// big enough memory area

int main(int argc, char**argv)
{
	for( size_t i = 0;i < 16;i++ )
	{
		std::cout << "loading from " << i;
		loadExperiment(workArea + i);
		std::cout << " DONE" << std::endl;
	}
	return 0;
}
