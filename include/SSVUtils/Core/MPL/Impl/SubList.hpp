// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_CORE_MPL_IMPL_SUBLIST
#define SSVU_CORE_MPL_IMPL_SUBLIST

#include "SSVUtils/Core/MPL/Impl/BaseTypes.hpp"

namespace ssvu
{
	namespace MPL
	{
		namespace Impl
		{
			template<SizeT, SizeT, SizeT, typename, typename, typename> struct SubListImpl;
			template<SizeT, SizeT, SizeT, typename, typename> struct SubListDispatch;
			template<SizeT TS1, SizeT TS2, SizeT TSC, typename... TLA1s, typename... TLA2s> struct SubListImpl<TS1, TS2, TSC, List<TLA1s...>, List<TLA2s...>, FalseT>
			{
				using Type = typename SubListDispatch<TS1, TS2, TSC + 1, List<TLA1s...>, typename List<TLA2s...>::template PushBack<typename List<TLA1s...>::template At<TSC>>>::Type;
			};
			template<SizeT TS1, SizeT TS2, SizeT TSC, typename... TLA1s, typename... TLA2s> struct SubListImpl<TS1, TS2, TSC, List<TLA1s...>, List<TLA2s...>, TrueT>
			{
				using Type = List<TLA2s...>;
			};
			template<SizeT TS1, SizeT TS2, SizeT TSC, typename TL1, typename TL2> struct SubListDispatch
			{
				using Type = typename SubListImpl<TS1, TS2, TSC, TL1, TL2, BoolResult<TSC == TS2 || TSC >= TL1::getSize()>>::Type;
			};
			template<SizeT, SizeT, SizeT, typename> struct SubListHlpr;
			template<SizeT TS1, SizeT TS2, SizeT TSC, typename... TLAs> struct SubListHlpr<TS1, TS2, TSC, List<TLAs...>>
			{
				using Type = typename SubListDispatch<TS1, TS2, TSC, List<TLAs...>, List<>>::Type;
			};
		}
	}
}

#endif