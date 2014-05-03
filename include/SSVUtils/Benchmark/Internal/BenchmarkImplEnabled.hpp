// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_BENCHMARK_INTERNAL_IMPL_ENABLED
#define SSVU_BENCHMARK_INTERNAL_IMPL_ENABLED

#include "SSVUtils/Core/Core.hpp"

namespace ssvu
{
	namespace Benchmark
	{
		namespace Internal
		{
			using TP = std::chrono::time_point<HRClock>;
			using Duration = std::chrono::milliseconds;

			struct Data
			{
				TP tp;
				std::string name;

				inline Data() = default;
				inline Data(const TP& mTP, std::string mName) : tp{mTP}, name{std::move(mName)} { }
			};

			using Stack = std::vector<Data>;

			inline Stack& getStack() noexcept
			{
				static Stack result;
				return result;
			}

			inline Data& getLastData()
			{
				SSVU_ASSERT(!Internal::getStack().empty());
				return getStack().back();
			}

			inline void start(std::string mTitle = "")
			{
				Internal::getStack().emplace_back(HRClock::now(), std::move(mTitle));
			}

			inline Internal::Data getEndData()
			{
				auto last(Internal::getLastData());
				Internal::getStack().pop_back();
				return last;
			}

			inline Internal::Duration getEndDuration()
			{
				return std::chrono::duration_cast<Internal::Duration>(HRClock::now() - getEndData().tp);
			}

			inline std::string getEndString()
			{
				return toStr(getEndDuration().count()) + " ms";
			}

			inline void endLo()
			{
				const auto& last(Internal::getLastData());
				lo("Benchmark #" + toStr(Internal::getStack().size()) + " - <" + last.name + ">") << getEndString() << std::endl;
			}
		}
	}
}

#endif