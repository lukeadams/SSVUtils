// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_TEMPLATESYSTEM_INTERNAL_SYMBOLS
#define SSVU_TEMPLATESYSTEM_INTERNAL_SYMBOLS

namespace ssvu
{
	namespace TemplateSystem
	{
		namespace Internal
		{
			constexpr const char* keyLeft{"{{"};
			constexpr const char* keyRight{"}}"};
			constexpr const char* sectionStartLeft{"{{#"};
			constexpr const char* sectionStartRight{"}}"};
			constexpr const char* sectionEndLeft{"{{/"};
			constexpr const char* sectionEndRight{"}}"};

			inline auto getKey(const std::string& mStr)				{ return keyLeft + mStr + keyRight; }
			inline auto getSectionStart(const std::string& mStr)	{ return sectionStartLeft + mStr + sectionStartRight; }
			inline auto getSectionEnd(const std::string& mStr)		{ return sectionEndLeft + mStr + sectionEndRight; }
		}
	}
}

#endif
