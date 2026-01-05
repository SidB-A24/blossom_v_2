//
// Created by Sid B on 25/12/25.
//

#ifndef BLOSSOM_V_2_OPERATOR_H
#define BLOSSOM_V_2_OPERATOR_H
#include "callable.h"
#include "coredef.h"

namespace BLSL
{
    typedef NSized (*opeval_t)(NSized& lvalue, NSized& rvalue);

    typedef std::vector<std::pair<std::pair<OperatorType, OperatorType>, opeval_t>> optable_t;
/*
    static const optable_t ADD_OPERATIONS = {
        {{ValueType::INT,ValueType::INT}, },
        {{ValueType::INT,ValueType::SCI}, }
    };
*/
}

#endif //BLOSSOM_V_2_OPERATOR_H