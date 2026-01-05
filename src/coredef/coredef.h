//
// Created by Sid B on 22/12/25.
//

#ifndef BLOSSOM_V_2_COREDEF_H
#define BLOSSOM_V_2_COREDEF_H
#include <memory>
#include <unordered_map>
#include <variant>
#include <vector>

namespace BLSL
{
    class Expression;
#define BLSL_USE_CNS_COLORS 1

    enum class BLSLModuleTy
    {
        LEXER,
        PARSER,
        VM,
        PROGRAM
    };

    enum class ValueType
    {
        INT,
        SCI,
        ASCII
    };

    enum class OperatorType
    {
        ADD,
        SUB,
        MUL,
        DIV
    };

    static const std::unordered_map<BLSLModuleTy, std::string> MODULE_NAMES = {
        {BLSLModuleTy::LEXER, "Lexer"},
        {BLSLModuleTy::PARSER, "Parser"},
        {BLSLModuleTy::VM, "VM"},
        {BLSLModuleTy::PROGRAM, "Program"}
    };

    struct pos_t
    {
        unsigned int line;
        unsigned short offset;
    };

    static const std::unordered_map<std::string, std::string> ESCAPE_SEQUENCES = {
        {"n", "\n"},
        {"r", "\r"},
        {"t", "\t"},
        {"\\", "\\"},
        {"\"", "\""},
        {"0", "\0"}
    };


    typedef std::variant<long long, std::string> literal_t;

    typedef uint8_t byte_t;
    typedef uint16_t longbyte_t;
    typedef int8_t signedbyte_t;


    // Stores from MSB to LSB
    typedef std::vector<byte_t> bytes_t;

    struct NSized
    {
        bytes_t bytes;
        ValueType type;
    };

    size_t get_sizet_from_nsized(NSized ns);

    typedef std::variant<Expression, NSized> expr_t;

    bool is_identifier_character(char c);
}

#endif //BLOSSOM_V_2_COREDEF_H