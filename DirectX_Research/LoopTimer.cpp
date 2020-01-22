#include "LoopTimer.h"

using namespace std::chrono;

LoopTimer::LoopTimer() noexcept
{
	last = steady_clock::now();
}

//Time elapsed since the last time called and resets
float LoopTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

//Time elapsed since the last time called Mark() but does not reset it
float LoopTimer::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}