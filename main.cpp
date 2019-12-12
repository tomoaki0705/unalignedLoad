#include <iostream>
#include "load.hpp"

char workArea[2048] = {0};// big enough memory area

int main(int argc, char**argv)
{
	for( size_t i = 0;i < 64;i++ )
	{
		std::cout << "loading from " << i;
		loadExperiment(workArea + i);
	}
	return 0;
}
