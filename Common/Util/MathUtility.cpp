#include "MathUtility.hpp"

#include <cassert>

namespace Common
{
	float MathUtility::ClampSwap(float x, float min, float max)
	{
		assert(max > min);

		float r = x < min ? max : x;
		return x > max ? min : r;
	}
}