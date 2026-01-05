//
// Created by Sid B on 22/12/25.
//

#ifndef BLOSSOM_V_2_TOKEN_H
#define BLOSSOM_V_2_TOKEN_H
#include <string>
#include <unordered_map>
#include <variant>

#include "coredef.h"

namespace BLSL
{
    enum class TokenType
    {
        /*
        LITERALS
        */
        IDENT,

        STR_LT,
        INT_LT,

        /*
        KEYWORDS
        */

        //Memory
        MEM_MAKE,                  // Memory Initialization Call
        MEM_ALLOC,                 // Memory Allocation Call
        MEM_COPY,                  // Memory Copy Call
        MEM_SET,                   // Memory Assignment Call
        MEM_SQUASH,                // Assigning to part of an allocation block's memory.

        //Type Interpretation
        INT_T,                    // N byte integer
        SCI_T,                    // N byte decimal
        ASCII_T,                  // N byte ascii string

        //Utility
        CNS_DUMP,                 // Write out memory to console
        SCRIPT_END,               // EOF Keyword

        /*
        OPERATORS
        */

        //String Operators
        DQUOTE_O,                 // " For opening closing strings
        SQUOTE_O,                 // ' Possible unused

        //Bit Operations
        OR_O,                     // | Bitwise OR
        AND_O,                    // & Bitwise AND
        LSHIFT_O,                 // << Bitwise Left Shift
        RSHIFT_O,                 // >> Bitwise Right Shift

        //Math
        NUMPLUS_O,                // + For numeric addition
        NUMMINUS_O,               // - For numeric subtraction / setting sign bit
        NUMTIMES_O,               // * For numeric multiplication
        NUMDIV_O,                 // / For numeric division

        //Utility
        ASSIGN_O,                 // = For value assignment
        PASS_O,                   // < For passing memory content
        TYPE_O,                   // : For specifying literal type
        SEMIC_O                   // ; For end line

    };

    static const TokenType OPERATORS[] = {

        TokenType::DQUOTE_O,                 // " For opening closing strings
        TokenType::SQUOTE_O,                 // ' Possible unused

       //Bit Operations
        TokenType::OR_O,                     // | Bitwise OR
        TokenType::AND_O,                    // & Bitwise AND
        TokenType::LSHIFT_O,                 // << Bitwise Left Shift
        TokenType::RSHIFT_O,                 // >> Bitwise Right Shift

       //Math
        TokenType::NUMPLUS_O,                // + For numeric addition
        TokenType::NUMMINUS_O,               // - For numeric subtraction / setting sign bit
        TokenType::NUMTIMES_O,               // * For numeric multiplication
        TokenType::NUMDIV_O,                 // / For numeric division

       //Utility
        TokenType::ASSIGN_O,                 // = For value assignment
        TokenType::PASS_O,                   // < For passing memory content
        TokenType::TYPE_O,                   // : For specifying literal type
        TokenType::SEMIC_O
    };

    static const TokenType KEYWORDS[] = {
        //Memory
        TokenType::MEM_MAKE,                  // Memory Initialization Call
        TokenType::MEM_ALLOC,                 // Memory Allocation Call
        TokenType::MEM_COPY,                  // Memory Copy Call
        TokenType::MEM_SET,                   // Memory Assignment Call
        TokenType::MEM_SQUASH,                // Assigning to part of an allocation block's memory.

        //Type Interpretation
        TokenType::INT_T,                    // N byte integer
        TokenType::SCI_T,                    // N byte decimal
        TokenType::ASCII_T,                  // N byte ascii string

        //Utility
        TokenType::CNS_DUMP                 // Write out memory to console
    };

    static const std::pair<std::string, TokenType> TOKEN_STRINGS[] = {
        /*
        KEYWORDS
        */

        //Memory
        {"memmake", TokenType::MEM_MAKE},
        {"memalloc", TokenType::MEM_ALLOC},
        {"memcopy", TokenType::MEM_COPY},
        {"memset", TokenType::MEM_SET},
        {"memsquash", TokenType::MEM_SQUASH},

        //Type Interpretation
        {"int", TokenType::INT_T},
        {"sci", TokenType::SCI_T},
        {"ascii", TokenType::ASCII_T},

        //Utility
        {"cdump", TokenType::CNS_DUMP},

        /*
        Operators
        */

        //String Operators
        {"\"", TokenType::DQUOTE_O},
        {"\'", TokenType::SQUOTE_O},

        //Bit Operations
        {"|", TokenType::OR_O},
        {"&", TokenType::AND_O},
        {"<<", TokenType::LSHIFT_O},
        {">>", TokenType::RSHIFT_O},

        //Math
        {"+", TokenType::NUMPLUS_O},
        {"-", TokenType::NUMMINUS_O},
        {"*", TokenType::NUMTIMES_O},
        {"/", TokenType::NUMDIV_O},

        //Utility
        {"=", TokenType::ASSIGN_O},
        {"<", TokenType::PASS_O},
        {":", TokenType::TYPE_O},
        {";", TokenType::SEMIC_O}
    };

    struct Token
    {
        TokenType type;
        NSized value;
        pos_t pos;
    };

}





#endif //BLOSSOM_V_2_TOKEN_H