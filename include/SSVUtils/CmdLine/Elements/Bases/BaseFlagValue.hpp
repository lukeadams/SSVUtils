// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVU_CMDLINE_ELEMENTS_BASES_BASEFLAGVALUE
#define SSVU_CMDLINE_ELEMENTS_BASES_BASEFLAGVALUE

#include <string>
#include "SSVUtils/Core/Core.hpp"
#include "SSVUtils/CmdLine/Elements/Bases/BaseFlag.hpp"

namespace ssvu
{
    namespace CmdLine
    {
        namespace Impl
        {
            struct BaseFlagValue : public BaseFlag
            {
                inline BaseFlagValue(
                    const std::string& mNameShort, const std::string& mNameLong)
                    : BaseFlag{mNameShort, mNameLong}
                {
                }
                virtual void set(const std::string&) = 0;
            };
        }
    }
}

#endif
