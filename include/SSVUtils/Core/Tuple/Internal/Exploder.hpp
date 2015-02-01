// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_CORE_TUPLE_INTERNAL_EXPLODER
#define SSVU_CORE_TUPLE_INTERNAL_EXPLODER

#include <tuple>
#include "SSVUtils/Core/Common/Common.hpp"

namespace ssvu
{
	namespace Internal
	{
		template<SizeT TN> struct Exploder
		{
			template<typename TF, typename T, typename... TArgs> inline static auto explode(TF&& mF, T&& mT, TArgs&&... mArgs) noexcept
			{
				return Exploder<TN - 1>::explode(SSVU_FWD(mF), SSVU_FWD(mT), ::std::get<TN - 1>(SSVU_FWD(mT)), SSVU_FWD(mArgs)...);
			}
		};

		template<> struct Exploder<0>
		{
			template<typename TF, typename T, typename... TArgs> inline static auto explode(TF&& mF, T&&, TArgs&&... mArgs)
				noexcept(noexcept(SSVU_FWD(mF)(SSVU_FWD(mArgs)...)))
			{
				return SSVU_FWD(mF)(SSVU_FWD(mArgs)...);
			}
		};
	}
}

#endif