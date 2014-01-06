// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_PREPROCESSOR_STRINGIFYWITHCOMMAS
#define SSVU_PREPROCESSOR_STRINGIFYWITHCOMMAS

#include "SSVUtils/Preprocessor/Utils.hpp"

namespace ssvu
{
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_0(...)			SSVU_PP_EMPTY()
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_1(m0, ...)		SSVU_PP_STRINGIFY(m0)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_2(m0, m1, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_STRINGIFY(m1) SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_1(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_3(m0, ...)		SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_2(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_4(m0, ...)		SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_3(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_5(m0, ...)		SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_4(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_6(m0, ...)		SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_5(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_7(m0, ...)		SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_6(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_8(m0, ...)		SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_7(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_9(m0, ...)		SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_8(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_10(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_9(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_11(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_10(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_12(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_11(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_13(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_12(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_14(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_13(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_15(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_14(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_16(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_15(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_17(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_16(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_18(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_17(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_19(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_18(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_20(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_19(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_21(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_20(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_22(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_21(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_23(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_22(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_24(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_23(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_25(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_24(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_26(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_25(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_27(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_26(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_28(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_27(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_29(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_28(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_30(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_29(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_31(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_30(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_32(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_31(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_33(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_32(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_34(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_33(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_35(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_34(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_36(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_35(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_37(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_36(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_38(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_37(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_39(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_38(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_40(m0, ...)	SSVU_PP_STRINGIFY(m0)", " SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_39(__VA_ARGS__)

	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_REVERSE_SEQUENCE()	40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, \
																20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1, \
																0

	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_DISPATCH_IMPL(	m01, m02, m03, m04, m05, m06, m07, m08, m09, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, \
															m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32, m33, m34, m35, m36, m37, m38, m39, m40, \
															mN, ...) SSVU_PP_TOKENPASTE_2(SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_, mN)

	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_DISPATCH(...)	SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_DISPATCH_IMPL(__VA_ARGS__)
	#define SSVU_PP_IMPL_STRINGIFYWITHCOMMAS(...)			SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_DISPATCH(__VA_ARGS__, SSVU_PP_IMPL_STRINGIFYWITHCOMMAS_REVERSE_SEQUENCE()) (__VA_ARGS__)

	#define SSVU_PP_STRINGIFYWITHCOMMAS(...)				SSVU_PP_IMPL_STRINGIFYWITHCOMMAS(__VA_ARGS__)
}

#endif