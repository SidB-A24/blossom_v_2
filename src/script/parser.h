//
// Created by Sid B on 22/12/25.
//

#ifndef BLOSSOM_V_2_PARSER_H
#define BLOSSOM_V_2_PARSER_H
#include <vector>
#include <memory>

#include "../coredef/callable.h"

namespace BLSL
{
    typedef std::function<std::unique_ptr<Callable> ()> parsec_t;


    class Parser
    {
    private:
        size_t _tokIndex;

        std::vector<std::unique_ptr<Callable>> _out;
        std::vector<Token>* _in;

    public:
        explicit Parser(std::vector<Token>* in);

    private:
        [[nodiscard]] Token& _peek() const;
        [[nodiscard]] std::vector<Token> _peek(size_t n) const;

        Token _next();
        std::vector<Token> _next(size_t n);

        void _expect(TokenType tkty, const std::string& msg = "");

    private:
        template <TokenType TkTy>
        std::unique_ptr<Callable> subparser();

    public:
        std::vector<std::unique_ptr<Callable>> parse();

    };

    static std::unordered_map<TokenType, parsec_t> SUBPARSER_DISPATCH_TABLE =
    {

    };

}




#endif //BLOSSOM_V_2_PARSER_H