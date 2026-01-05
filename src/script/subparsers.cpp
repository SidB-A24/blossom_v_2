//
// Created by Sid B on 05/01/26.
//

#include "parser.h"
#include "../cns/cns.h"

namespace BLSL
{
    template <TokenType TkTy>
    std::unique_ptr<Callable> Parser::subparser()
    {
        if (sizeof(TkTy) != 0)
        {
            CNS::err(BLSLModuleTy::PARSER) << "Undefined Parser Function" << CNS::ENDL;
            throw std::runtime_error("Undefined Parser Function");
        }
    }

    template <>
    std::unique_ptr<Callable> Parser::subparser<TokenType::MEM_MAKE>()
    {
        _expect(TokenType::INT_LT, "Expected integer literal denoting number of bytes.");

        size_t numberOfBytes = get_sizet_from_nsized(_next().value);

        return std::make_unique<MemMake>(numberOfBytes);
    }


}
