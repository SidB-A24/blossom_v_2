//
// Created by Sid B on 22/12/25.
//

#ifndef BLOSSOM_V_2_LEXER_H
#define BLOSSOM_V_2_LEXER_H

#include "../coredef/token.h"
#include "../coredef/coredef.h"

#include <vector>
#include <optional>

namespace BLSL
{
    class Lexer
    {
    private:
        std::string _source;
        size_t _carat;
        pos_t _pos;
        std::vector<Token>* _out;

    public:
        Lexer(std::string&& source, std::vector<Token>* out);

    private:
        void _step();                                                   // Steps the carat and pos forward by 1 character
        void _step(unsigned short n);                                   // Steps the carat and pos forward by n characters
        std::optional<char> _peekc() const;                             // Returns 1 character from source as a char
        std::optional<std::string> _peeks(unsigned short n) const;      // Returns n characters from source as a string

    private:
        bool _lex_operators();                                          // Checks and lexes if the current character starts an operator sequence
        bool _lex_string();                                             // Checks and lexes if the current character starts a string sequence
        bool _lex_number();                                             // Checks and lexes if the current character starts a numerical sequence
        bool _lex_identifier_keyword();                                 // Checks and lexes if the current character starts an identifier sequence

    public:
        std::vector<Token>* lex();
    };
}



#endif //BLOSSOM_V_2_LEXER_H