#include <iostream>
#include <string>
#include "load.hpp"

char __attribute__ ((aligned(16))) workArea[2048] = {0};// big enough memory area

int main(int argc, char**argv)
{
	for( size_t i = 0;i < 16;i++ )
	{
		std::cout << "loading from " << i << std::flush;
		if (argc < 2 || std::string(argv[1]) == std::string("s8"))
		{
			loadExperiment((const char*)(workArea + i));
		}
		else if (std::string(argv[1]) == std::string("u8"))
		{
			loadExperiment(workArea + i);
		}
		else if (std::string(argv[1]) == std::string("s16"))
		{
			loadExperiment((const short*)(workArea + i));
		}
		else if (std::string(argv[1]) == std::string("u16"))
		{
			loadExperiment((const unsigned short*)(workArea + i));
		}
		else if (std::string(argv[1]) == std::string("s32"))
		{
			loadExperiment((const int*)(workArea + i));
		}
		else if (std::string(argv[1]) == std::string("u32"))
		{
			loadExperiment((const unsigned int*)(workArea + i));
		}
		else if (std::string(argv[1]) == std::string("s64"))
		{
			loadExperiment((const int64_t*)(workArea + i));
		}
		else if (std::string(argv[1]) == std::string("u64"))
		{
			loadExperiment((const uint64_t*)(workArea + i));
		}
		else if (std::string(argv[1]) == std::string("f32"))
		{
			loadExperiment((const float*)(workArea + i));
		}
		std::cout << " DONE" << std::endl;
	}
	return 0;
}
