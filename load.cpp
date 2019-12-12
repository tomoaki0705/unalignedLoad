#include "load.hpp"
#include <arm_neon.h>

void loadExperiment(const char* readPtr)
{
	volatile uint64x2_t v00 = vld1q_u64((const uint64_t*)readPtr);
	return;
}
