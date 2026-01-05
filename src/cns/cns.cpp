//
// Created by Sid B on 23/12/25.
//

#include "cns.h"

#include "../coredef/coredef.h"

std::ostream & BLSL::CNS::err(BLSLModuleTy caty)
{
#if BLSL_USE_CNS_COLORS
    return std::cout << CALLER_ERROR_BG_COLORS.at(caty) << COLORS.at(ColorTy::BOLD) <<  "[" << COLORS.at(ColorTy::ITALIC) << MODULE_NAMES.at(caty) << COLORS.at(ColorTy::END_ITALIC) << " ERR]" << END << "  " << CALLER_ERROR_FG_COLORS.at(caty);
#else
    return std::cout << "[" << MODULE_NAMES.at(caty) << " ERR]" << END << "  ";
#endif
}

std::ostream & BLSL::CNS::inf(BLSLModuleTy caty)
{
#if BLSL_USE_CNS_COLORS
    return std::cout << CALLER_INFO_BG_COLORS.at(caty) << COLORS.at(ColorTy::BOLD) <<  "[" << COLORS.at(ColorTy::ITALIC) << MODULE_NAMES.at(caty) << COLORS.at(ColorTy::END_ITALIC) << " INF]" << END << "  ";
#else
    return std::cout << "[" << MODULE_NAMES.at(caty) << " INF]" << END << "  ";
#endif

}

std::ostream & BLSL::CNS::out()
{
    return std::cout << COLORS.at(ColorTy::CNS_OUT_LABEL) << "[OUT]" << END << "  " << COLORS.at(ColorTy::CNS_OUT_TEXT);
}


void ::BLSL::CNS::flush()
{
    std::cout << std::endl;
}

