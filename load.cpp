#include "load.hpp"
#include <arm_neon.h>

#define MAKE_TEMPLATED_FUNCTION(tpVec, suffix, T) \
void loadExperiment(const T* readPtr)             \
{                                                 \
	volatile tpVec v00 = vld1q_##suffix(readPtr); \
	return;                                       \
}

MAKE_TEMPLATED_FUNCTION(int8x16_t,   s8,  int8_t);
MAKE_TEMPLATED_FUNCTION(uint8x16_t,  u8,  unsigned char);
MAKE_TEMPLATED_FUNCTION(int16x8_t,   s16, short);
MAKE_TEMPLATED_FUNCTION(uint16x8_t,  u16, unsigned short);
MAKE_TEMPLATED_FUNCTION(int32x4_t,   s32, int);
MAKE_TEMPLATED_FUNCTION(uint32x4_t,  u32, unsigned int);
MAKE_TEMPLATED_FUNCTION(int64x2_t,   s64, int64_t);
MAKE_TEMPLATED_FUNCTION(uint64x2_t,  u64, uint64_t);
MAKE_TEMPLATED_FUNCTION(float32x4_t, f32, float);

