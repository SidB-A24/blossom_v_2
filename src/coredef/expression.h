//
// Created by Sid B on 25/12/25.
//

#ifndef BLOSSOM_V_2_EXPRESSION_H
#define BLOSSOM_V_2_EXPRESSION_H

#include "coredef.h"

namespace BLSL
{
    class Expression
    {
    private:
        std::unique_ptr<expr_t> _lvalue;
        std::optional<std::unique_ptr<expr_t>> _rvalue;
        OperatorType _opty;

    public:
        Expression(std::unique_ptr<expr_t> lvalue, OperatorType opty, std::optional<std::unique_ptr<expr_t>> _rvalue = std::nullopt);

    };
}

#endif //BLOSSOM_V_2_EXPRESSION_H