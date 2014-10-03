// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_TESTS_JSON
#define SSVU_TESTS_JSON

SSVUT_TEST(SSVUJsonNumTests)
{
	using namespace ssvu;
	using namespace ssvu::Json;
	using namespace ssvu::Json::Internal;

	#define EXEC_NUM_TESTS() \
		SSVUT_EXPECT(n.as<char>() == char{10}); \
		SSVUT_EXPECT(n.as<int>() == 10); \
		SSVUT_EXPECT(n.as<long int>() == 10l); \
		SSVUT_EXPECT(n.as<unsigned char>() == static_cast<unsigned char>(10)); \
		SSVUT_EXPECT(n.as<unsigned int>() == 10u); \
		SSVUT_EXPECT(n.as<unsigned long int>() == 10ul); \
		SSVUT_EXPECT(n.as<float>() == 10.f); \
		SSVUT_EXPECT(n.as<double>() == 10.);

	{
		Num n;

		n.set(10);
		SSVUT_EXPECT(n.getType() == Num::Type::IntS);
		EXEC_NUM_TESTS()

		n.set(10u);
		SSVUT_EXPECT(n.getType() == Num::Type::IntU);
		EXEC_NUM_TESTS()

		n.set(10.f);
		SSVUT_EXPECT(n.getType() == Num::Type::Real);
		EXEC_NUM_TESTS()
	}

	#undef EXEC_NUM_TESTS

	Num ns{15}, nsu{15u}, nsul{15ul}, nf{15.f}, nd{15.};
	SSVUT_EXPECT(ns == nsu);
	SSVUT_EXPECT(nsu == nsul);
	SSVUT_EXPECT(nsul == nf);
	SSVUT_EXPECT(nf == nd);
}

SSVUT_TEST(SSVUJsonValTests)
{
	using namespace ssvu;
	using namespace ssvu::Json;
	using namespace ssvu::Json::Internal;

	#define EXEC_TEST_BASIC(mType, mVal) \
		{ \
			Val v0, v1, v2; \
			v0 = mVal; \
			SSVUT_EXPECT(v0.is<mType>()); \
			v1 = v0; \
			SSVUT_EXPECT(v1.is<mType>()); \
			SSVUT_EXPECT(v0.as<Val>() == v0); \
			SSVUT_EXPECT(v0.as<mType>() == mVal); \
			SSVUT_EXPECT(v1.as<mType>() == mVal); \
			SSVUT_EXPECT(v0 == v1); \
			v2 = std::move(v1); \
			SSVUT_EXPECT(v2.is<mType>()); \
			SSVUT_EXPECT(v2.as<mType>() == mVal); \
			v0 = Obj{}; \
			v0["inner"] = v2; \
			SSVUT_EXPECT(v0["inner"] == v2); \
			auto sv0(v0.getWriteToStr()); \
			auto sv2(v2.getWriteToStr()); \
			auto osv0(Val::fromStr(sv0)); \
			auto osv2(Val::fromStr(sv2)); \
			SSVUT_EXPECT(v0 == osv0); \
			SSVUT_EXPECT(v2 == osv2); \
			SSVUT_EXPECT(v0["inner"] == osv2); \
			SSVUT_EXPECT(osv0["inner"] == v2); \
			SSVUT_EXPECT(osv0["inner"] == osv2); \
		}

	EXEC_TEST_BASIC(bool, true)
	EXEC_TEST_BASIC(bool, false)
	EXEC_TEST_BASIC(char, 'a')
	EXEC_TEST_BASIC(int, 10)
	EXEC_TEST_BASIC(long int, 10l)
	EXEC_TEST_BASIC(unsigned char, 'a')
	EXEC_TEST_BASIC(unsigned int, 10u)
	EXEC_TEST_BASIC(unsigned long int, 10ul)
	EXEC_TEST_BASIC(float, 10.f)
	EXEC_TEST_BASIC(double, 10.)

	EXEC_TEST_BASIC(Str, "hello")
	EXEC_TEST_BASIC(Str, "hello"s)

	{
		Arr a{"hello", "bye"s, 10, 15.f, 'u'};
		EXEC_TEST_BASIC(Arr, a)
	}

	{
		Obj o{{"hello", "bye"}, {"welcome"s, "goodbye"s}, {"banana", 15}, {"best letter", 'v'}};
		EXEC_TEST_BASIC(Obj, o)
	}

	{
		using PP = std::pair<std::string, double>;
		PP p{"coolpair", 205.5};
		EXEC_TEST_BASIC(PP, p)
	}

	{
		using PP = std::pair<std::pair<int, std::string>, std::pair<float, double>>;
		PP p{std::pair<int, std::string>{10, "coolpair2"}, std::pair<float, double>{15.f, 205.5}};
		EXEC_TEST_BASIC(PP, p)
	}

	{
		using PP = std::tuple<int>;
		PP p{10};
		EXEC_TEST_BASIC(PP, p)
	}

	{
		using PP = std::tuple<int, float, std::string>;
		PP p{10, 15.5f, "swag"s};
		EXEC_TEST_BASIC(PP, p)
	}

	{
		using PP = std::tuple<int, float, std::string, int, float>;
		PP p{10, 15.5f, "more swag"s, 22, 0.f};
		EXEC_TEST_BASIC(PP, p)
	}

	{
		using PP = std::tuple<int, float, std::string, int, std::pair<double, int>, float, std::tuple<int, int, int>>;
		PP p{10, 15.5f, "ULTRA SWAG"s, 22, std::pair<double, int>{10.5, 99}, 0.f, std::tuple<int, int, int>{0, 1, 2}};
		EXEC_TEST_BASIC(PP, p)
	}

	// Equality with C-style arrays doesn't work
	#define EXEC_TEST_C_ARRAY(mType, mVal) \
	{ \
		Val v0, v1, v2; \
		v0 = mVal; \
		SSVUT_EXPECT(v0.is<mType>()); \
		v1 = v0; \
		SSVUT_EXPECT(v1.is<mType>()); \
		SSVUT_EXPECT(v0 == v1); \
		v2 = std::move(v1); \
		SSVUT_EXPECT(v2.is<mType>()); \
		v0 = Obj{}; \
		v0["inner"] = v2; \
		SSVUT_EXPECT(v0["inner"] == v2); \
		auto sv0(v0.getWriteToStr()); \
		auto sv2(v2.getWriteToStr()); \
		auto osv0(Val::fromStr(sv0)); \
		auto osv2(Val::fromStr(sv2)); \
		SSVUT_EXPECT(v0 == osv0); \
		SSVUT_EXPECT(v2 == osv2); \
		SSVUT_EXPECT(v0["inner"] == osv2); \
		SSVUT_EXPECT(osv0["inner"] == v2); \
		SSVUT_EXPECT(osv0["inner"] == osv2); \
	}

	{
		using PP = int[3];
		PP p{10, 20, 35};
		EXEC_TEST_C_ARRAY(PP, p)
	}

	{
		using PP = std::vector<int>;
		PP p{10, 20, 35};
		EXEC_TEST_BASIC(PP, p)
	}

	{
		using PP = std::vector<std::string>;
		PP p{"10", "20", "35"};
		EXEC_TEST_BASIC(PP, p)
	}

	{
		using PP = std::tuple<std::vector<std::string>, std::pair<std::vector<int>, std::vector<float>>, int, std::vector<int>>;
		PP p{std::vector<std::string>{"10", "20", "35"}, std::pair<std::vector<int>, std::vector<float>>{std::vector<int>{1, 2}, std::vector<float>{1.f, 2.f}}, 20, std::vector<int>{}};
		EXEC_TEST_BASIC(PP, p)
	}


	#undef EXEC_TEST_BASIC
	#undef EXEC_TEST_C_ARRAY
}

SSVUT_TEST(SSVUJsonReadTests)
{
	using namespace ssvu;
	using namespace ssvu::Json;
	using namespace ssvu::Json::Internal;

	auto testSrc(R"(
	{
		// Hello
		"a":1,//Comment // iko
		"b":null,//
		"c":"//",//
		"d":true,//////
		"e":"//\"//",//k
		"f"//a
		://a
		{//a
		 //a

				"oo"//a
		 ://g
		 [//a
		 1,//b // h
		 2,//h // ds
		 3//l
		 ]//g
		 ,//p
		 //p //pp p p
		 "2"://k
		 2
////////
		 ///s
   //s/s/

		}//a
	}
	)");

	auto v(Val::fromStr(testSrc));

	SSVUT_EXPECT(v["a"] == 1);
	SSVUT_EXPECT(v["b"] == Nll{});
	SSVUT_EXPECT(v["c"] == "//");
	SSVUT_EXPECT(v["d"] == true);
	SSVUT_EXPECT(v["e"] == "//\"//");
}

SSVUT_TEST(SSVUJsonWriteTests)
{
	using namespace ssvu;
	using namespace ssvu::Json;
	using namespace ssvu::Json::Internal;

	auto testSrc(R"(
	{
		"a": 15,
		"b": { "c": null },
		"c": ["x", "y", 10.5]
	}
	)");

	auto v(Val::fromStr(testSrc));

	SSVUT_EXPECT(v["a"] == 15);
	SSVUT_EXPECT(v["b"]["c"] == Nll{});
	SSVUT_EXPECT(v["c"][0] == "x");
	SSVUT_EXPECT(v["c"][1] == "y");
	SSVUT_EXPECT(v["c"][2] == 10.5);

	auto minified(v.getWriteToStr<WriterSettings<WMode::Minified>>());

	SSVUT_EXPECT(minified == R"({"a":15,"b":{"c":null},"c":["x","y",10.5]})");
}

SSVUT_TEST(SSVUJsonConvertTests)
{
	using namespace ssvu;
	using namespace ssvu::Json;
	using namespace ssvu::Json::Internal;

	#define EXEC_CV_TEST(mType, mBV) \
		{ \
			using Type = mType; \
			Val vIn; \
			const Type& in = mBV; \
			convert(vIn, in); \
			SSVUT_EXPECT(vIn.as<Type>() == mBV); \
			const Val& vOut{static_cast<Type>(mBV)}; \
			Type out; \
			convert(vOut, out); \
			SSVUT_EXPECT(out == mBV); \
		}

	// TODO: should array resize itself?
	#define EXEC_CV_TEST_ARR(mType, mBV0, mBV1, mBV2) \
		{ \
			using Type = mType; \
			auto x = Arr{Type{}, Type{}, Type{}}; \
			Val vIn{x}; \
			const Type& in0 = mBV0; \
			const Type& in1 = mBV1; \
			const Type& in2 = mBV2; \
			convertArr(vIn, in0, in1, in2); \
			SSVUT_EXPECT(vIn[0].as<Type>() == mBV0); \
			SSVUT_EXPECT(vIn[1].as<Type>() == mBV1); \
			SSVUT_EXPECT(vIn[2].as<Type>() == mBV2); \
			const Val& vOut(vIn); \
			Type out0, out1, out2; \
			convertArr(vOut, out0, out1, out2); \
			SSVUT_EXPECT(out0 == mBV0); \
			SSVUT_EXPECT(out1 == mBV1); \
			SSVUT_EXPECT(out2 == mBV2); \
		}

	#define EXEC_CV_TEST_OBJ(mType, mBV0, mBV1, mBV2) \
		{ \
			using Type = mType; \
			Val vIn{Obj{}}; \
			const Type& in0 = mBV0; \
			const Type& in1 = mBV1; \
			const Type& in2 = mBV2; \
			convertObj(vIn, "k0", in0, "k1", in1, "k2", in2); \
			SSVUT_EXPECT(vIn["k0"].as<Type>() == mBV0); \
			SSVUT_EXPECT(vIn["k1"].as<Type>() == mBV1); \
			SSVUT_EXPECT(vIn["k2"].as<Type>() == mBV2); \
			const Val& vOut(vIn); \
			Type out0, out1, out2; \
			convertObj(vOut, "k0", out0, "k1", out1, "k2", out2); \
			SSVUT_EXPECT(out0 == mBV0); \
			SSVUT_EXPECT(out1 == mBV1); \
			SSVUT_EXPECT(out2 == mBV2); \
		}

	EXEC_CV_TEST(bool, true)
	EXEC_CV_TEST(bool, false)
	EXEC_CV_TEST(char, 'a')
	EXEC_CV_TEST(int, 10)
	EXEC_CV_TEST(long int, 10l)
	EXEC_CV_TEST(unsigned char, 'a')
	EXEC_CV_TEST(unsigned int, 10u)
	EXEC_CV_TEST(unsigned long int, 10ul)
	EXEC_CV_TEST(float, 10.f)
	EXEC_CV_TEST(double, 10.)

	EXEC_CV_TEST_ARR(bool, true, true, false)
	EXEC_CV_TEST_ARR(bool, false, false, true)
	EXEC_CV_TEST_ARR(char, 'a', 'b', 'c')
	EXEC_CV_TEST_ARR(int, 10, 20, 30)
	EXEC_CV_TEST_ARR(long int, 10l, 0l, 2l)
	EXEC_CV_TEST_ARR(unsigned char, 'a', 'b', 'x')
	EXEC_CV_TEST_ARR(unsigned int, 10u, 22u, 6553u)
	EXEC_CV_TEST_ARR(unsigned long int, 10ul, 22u, 314u)
	EXEC_CV_TEST_ARR(float, 10.f, 5.f, 0.f)
	EXEC_CV_TEST_ARR(double, 10., 5.5, 1.2)

	EXEC_CV_TEST_OBJ(bool, true, true, false)
	EXEC_CV_TEST_OBJ(bool, false, false, true)
	EXEC_CV_TEST_OBJ(char, 'a', 'b', 'c')
	EXEC_CV_TEST_OBJ(int, 10, 20, 30)
	EXEC_CV_TEST_OBJ(long int, 10l, 0l, 2l)
	EXEC_CV_TEST_OBJ(unsigned char, 'a', 'b', 'x')
	EXEC_CV_TEST_OBJ(unsigned int, 10u, 22u, 6553u)
	EXEC_CV_TEST_OBJ(unsigned long int, 10ul, 22u, 314u)
	EXEC_CV_TEST_OBJ(float, 10.f, 5.f, 0.f)
	EXEC_CV_TEST_OBJ(double, 10., 5.5, 1.2)

	#undef EXEC_CV_TEST
	#undef EXEC_CV_TEST_ARR
	#undef EXEC_CV_TEST_OBJ

	{
		// Simulation of converting a struct
		int f0{10};
		float f1{5.5f};
		std::vector<std::pair<float, double>> f2
		{
			{5.f, 10.}, {5.5f, 10.5}, {5.f, 10.}
		};
		std::string f3{"yo"};
		std::tuple<std::string, int, int> f4{"hey", 5, 10};

		Val vIn{Obj{}};
		convertObj(vIn, "f0", f0, "f1", f1, "f2", f2, "f3", f3, "f4", f4);
		SSVUT_EXPECT(f0 == vIn["f0"].as<decltype(f0)>());
		SSVUT_EXPECT(f1 == vIn["f1"].as<decltype(f1)>());
		SSVUT_EXPECT(f2 == vIn["f2"].as<decltype(f2)>());
		SSVUT_EXPECT(f3 == vIn["f3"].as<decltype(f3)>());
		SSVUT_EXPECT(f4 == vIn["f4"].as<decltype(f4)>());
		const Val& vOut(vIn);
		decltype(f0) of0;
		decltype(f1) of1;
		decltype(f2) of2;
		decltype(f3) of3;
		decltype(f4) of4;
		convertObj(vOut, "f0", of0, "f1", of1, "f2", of2, "f3", of3, "f4", of4);
		SSVUT_EXPECT(f0 == of0);
		SSVUT_EXPECT(f1 == of1);
		SSVUT_EXPECT(f2 == of2);
		SSVUT_EXPECT(f3 == of3);
		SSVUT_EXPECT(f4 == of4);
	}
}

/*
namespace ssvu
{
	namespace Json
	{
		namespace Internal
		{
			struct __ssvjTestStruct
			{
				SSVJ_CNV_FRIEND();

				int f0{10};
				float f1{5.5f};
				std::vector<std::pair<float, double>> f2
				{
					{5.f, 10.}, {5.5f, 10.5}, {5.f, 10.}
				};
				std::string f3{"yo"};
				std::tuple<std::string, int, int> f4{"hey", 5, 10};

				inline operator==(const __ssvjTestStruct& mT)
				{
					return f0 == mT.f0
						&& f1 == mT.f1
						&& f2 == mT.f2
						&& f3 == mT.f3
						&& f4 == mT.f4;
				}
			};

			template<> SSVJ_CNV_SIMPLE(__ssvjTestStruct, mV, mX)
			{
				ssvj::convertArr(mV, mX.f0, mX.f1, mX.f2, mX.f3, mX.f4);
			}
			SSVJ_CNV_END();
		}

	}
}

SSVUT_TEST(SSVUJsonCnvTest)
{
	using Type = ssvu::Json::Internal::__ssvjTestStruct;

	Type s1;
	ssvj::Val k = s1;
	SSVUT_EXPECT(k.as<Type>() == s1);
}*/

#endif

// TODO: iteration tests, missing tests (check all source)
