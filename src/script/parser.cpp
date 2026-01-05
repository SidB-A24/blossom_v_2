//
// Created by Sid B on 22/12/25.
//

#include "parser.h"
#include "../cns/cns.h"

#include <sstream>

BLSL::Token & BLSL::Parser::_peek() const
{
    if (_tokIndex < _in->size())
    {
        return _in->at(_tokIndex);
    }


    CNS::inf(BLSLModuleTy::PARSER) << "Peeking end of token list. Returning last token.";
    return _in->back();

}

std::vector<BLSL::Token> BLSL::Parser::_peek(size_t n) const
{
    if (_tokIndex + n < _in->size())
    {
        std::vector<Token> result(n);

        for (size_t i = 0; i < n; i++)
        {
            result.emplace_back(*(_in->data()+i));
        }

        return result;
    }

    CNS::inf(BLSLModuleTy::PARSER) << "Peeking end of token list. Returning vector with last token.";
    std::vector tkv = {_in->back()};
    return tkv;

}

BLSL::Token BLSL::Parser::_next()
{
    if (_tokIndex < _in->size())
    {
        return _in->at(_tokIndex++);
    }

    CNS::inf(BLSLModuleTy::PARSER) << "Attempting to advance token list after end. Returning last token.";
    return _in->back();
}

std::vector<BLSL::Token> BLSL::Parser::_next(size_t n)
{
    if (_tokIndex + n < _in->size())
    {
        std::vector<Token> result(n);

        for (size_t i = 0; i < n; i++)
        {
            result.emplace_back(*(_in->data()+i));
        }

        _tokIndex += n;
        return result;
    }

    CNS::inf(BLSLModuleTy::PARSER) << "Attempting to advance token list after end. Returning vector with last token.";
    std::vector tkv = {_in->back()};
    return tkv;
}

void BLSL::Parser::_expect(TokenType tkty, const std::string &msg)
{
    if (_peek().type != tkty)
    {
        std::stringstream ss;
        ss << "Expected Token: " << static_cast<int>(tkty) << "Got token: " << static_cast<int>(_peek().type);
        ss << "\n \"" << msg << "\"" << std::endl;

        CNS::err(BLSLModuleTy::PARSER) << ss.str();
        throw std::runtime_error(ss.str());
    }
    _next();
}

std::vector<std::unique_ptr<BLSL::Callable>> BLSL::Parser::parse()
{
    _out.clear();

    while (_peek().type != TokenType::SCRIPT_END)
    {
        if (SUBPARSER_DISPATCH_TABLE.contains(_peek().type))
        {
            SUBPARSER_DISPATCH_TABLE[_next().type]();
        }

    }

    return std::move(_out);
}

