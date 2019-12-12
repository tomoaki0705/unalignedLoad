#include "load.hpp"
#include <arm_neon.h>

void loadExperiment(const char* readPtr)
{
	volatile uint32x4_t v00 = vld1q_u32((const uint32_t*)readPtr);
	return;
}
