// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_JSON_VAL_INTERNAL_VALITRHELPER
#define SSVU_JSON_VAL_INTERNAL_VALITRHELPER

namespace ssvu
{
	namespace Json
	{
		namespace Internal
		{
			struct ValItrHelper
			{
				template<typename TK, typename TV> struct KVPair { TK key; TV value; };
				template<typename TK, typename TV> inline static constexpr auto makeKVPair(TK&& mK, TV&& mV) noexcept { return KVPair<TK, TV>{fwd<TK>(mK), fwd<TV>(mV)}; }

				template<typename T> struct ImplAsObj
				{
					template<typename TItr> inline static constexpr auto get(TItr mItr) noexcept { return makeKVPair(mItr->first, mItr->second.template as<T>());  }
				};

				template<typename T> struct ImplAsArr
				{
					template<typename TItr> inline static constexpr auto get(TItr mItr) noexcept { return mItr->template as<T>();  }
				};

				template<template<typename> class TImpl, typename T, typename TItr> using ItrAs = ssvu::Internal::AdaptorFromItr<TItr, TImpl<T>>;
				template<template<typename> class TImpl, typename T, typename TItr> inline constexpr static auto makeItrAs(TItr mItr) noexcept { return ItrAs<TImpl, T, TItr>{mItr}; }
				template<template<typename> class TImpl, typename T, typename TItr> inline constexpr static auto makeItrAsRange(TItr mBegin, TItr mEnd) noexcept { return makeRange(makeItrAs<TImpl, T>(mBegin), makeItrAs<TImpl, T>(mEnd)); }

				template<typename T, typename TItr> inline static constexpr auto makeItrObjRange(TItr mBegin, TItr mEnd) noexcept { return makeItrAsRange<ImplAsObj, T>(mBegin, mEnd); }
				template<typename T, typename TItr> inline static constexpr auto makeItrArrRange(TItr mBegin, TItr mEnd) noexcept { return makeItrAsRange<ImplAsArr, T>(mBegin, mEnd); }
			};
		}
	}
}

#endif
