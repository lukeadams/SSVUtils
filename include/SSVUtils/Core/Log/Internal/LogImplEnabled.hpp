// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_CORE_LOG_INTERNAL_IMPL_ENABLED
#define SSVU_CORE_LOG_INTERNAL_IMPL_ENABLED

namespace ssvu
{
	namespace Internal
	{
		inline const std::string& getUniqueColor(const std::string& mStr)
		{
			static int lastColorIdx{2};
			static std::unordered_map<std::string, Console::Color> map;

			if(map.count(mStr) == 0) map[mStr] = Console::Color(getWrapIdx(lastColorIdx++, 2, 7));
			return Console::setColorFG(map[mStr]);
		}

		inline std::ostringstream& getLogStream() noexcept { static std::ostringstream logStream; return logStream; }

		struct LOut
		{
			std::string title;
			inline void flush() const { std::cout.flush(); getLogStream().flush(); }
		};

		template<typename T> inline LOut& operator<<(LOut& mLOut, const T& mValue)
		{
			if(mLOut.title != "")
			{
				const auto& tStr("[" + mLOut.title + "] ");
				std::cout << getUniqueColor(mLOut.title) << Console::setStyle(Console::Style::Bold) << std::left << std::setw(38) << tStr;
				getLogStream() << std::left << std::setw(38) << tStr;
				mLOut.title = "";
			}

			std::cout << Console::resetFmt();
			stringify<true>(std::cout, mValue);
			std::cout << Console::resetFmt();

			stringify<false>(getLogStream(), mValue);

			return mLOut;
		}
		inline LOut& operator<<(LOut& mLOut, StdEndLine manip)
		{
			manip(std::cout); manip(getLogStream());
			return mLOut;
		}

		inline LOut& getLOutInstance() noexcept { static LOut loInstance; return loInstance; }

		inline LOut& lo() noexcept { return getLOutInstance(); }

		template<typename T> inline LOut& lo(const T& mTitle)
		{
			lo().title = toStr(mTitle);
			return lo();
		}

		inline const char* hr() noexcept				{ static std::string str(Console::Info::getColumnCount(), '_'); return str.c_str(); }
		inline std::string hr(int mOffset, char mChar)	{ return std::string(Console::Info::getColumnCount() + mOffset, mChar); }
	}
}

#endif