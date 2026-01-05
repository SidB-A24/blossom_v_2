//
// Created by Sid B on 23/12/25.
//

#ifndef BLOSSOM_V_2_CND_H
#define BLOSSOM_V_2_CND_H
#include <unordered_map>
#include <iostream>

#include "../coredef/coredef.h"

namespace BLSL
{


    namespace CNS
    {
        enum class ColorTy
        {
            RESET,
            BOLD,
            ITALIC,
            END_ITALIC,

            CNS_OUT_LABEL,
            CNS_OUT_TEXT
        };

        static const std::unordered_map<ColorTy, const char*> COLORS = {
            {ColorTy::RESET, "\033[0m"},
            {ColorTy::BOLD, "\033[1m"},
            {ColorTy::ITALIC, "\033[3m"},
            {ColorTy::END_ITALIC, "\033[23m"},

            {ColorTy::CNS_OUT_LABEL, "\033[38;5;232m\033[48;5;240m"},
            {ColorTy::CNS_OUT_TEXT, "\033[38;5;231m"},

        };

        static const std::unordered_map<BLSLModuleTy, const char*> CALLER_ERROR_FG_COLORS = {
            {BLSLModuleTy::LEXER, "\033[38;5;202m"},
            {BLSLModuleTy::PARSER, "\033[38;5;200m"},
            {BLSLModuleTy::VM, "\033[38;5;197m"},
            {BLSLModuleTy::PROGRAM, "\033[38;5;220m"}
        };

        static const std::unordered_map<BLSLModuleTy, const char*> CALLER_ERROR_BG_COLORS = {
            {BLSLModuleTy::LEXER, "\033[48;5;202m"},
            {BLSLModuleTy::PARSER, "\033[48;5;200m"},
            {BLSLModuleTy::VM, "\033[48;5;197m"},
            {BLSLModuleTy::PROGRAM, "\033[48;5;214m"}
        };

        static const std::unordered_map<BLSLModuleTy, const char*> CALLER_INFO_BG_COLORS = {
            {BLSLModuleTy::LEXER, "\033[48;5;215m"},
            {BLSLModuleTy::PARSER, "\033[48;5;212m"},
            {BLSLModuleTy::VM, "\033[48;5;218m"},
            {BLSLModuleTy::PROGRAM, "\033[48;5;146m"}
        };


        static std::string END = std::string(COLORS.at(ColorTy::RESET));
        static std::string ENDL = std::string(COLORS.at(ColorTy::RESET)) + std::string("\n");

        std::ostream& err(BLSLModuleTy caty);
        std::ostream& inf(BLSLModuleTy caty);
        std::ostream& out();

        void flush();

    }

}

#endif //BLOSSOM_V_2_CND_H