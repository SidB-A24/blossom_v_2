//
// Created by Sid B on 05/01/26.
//

#include "coredef.h"

#include "token.h"
#include "../cns/cns.h"

size_t BLSL::get_sizet_from_nsized(NSized ns)
{
    if (ns.type != ValueType::INT)
    {
        CNS::err(BLSLModuleTy::PARSER) << "Undefined conversion to size_t from non integral value" << CNS::ENDL;
        throw;
    }

    if (ns.bytes.size() > sizeof(size_t))
    {
        CNS::err(BLSLModuleTy::PARSER) << "Value too large to represent as size_t" << CNS::ENDL;
        throw;
    }

    size_t out = 0;
    for (size_t i = 0; i < ns.bytes.size(); ++i)
    {
        out += ns.bytes[i];
        out <<= sizeof(byte_t);
    }
    return out;
}

bool BLSL::is_identifier_character(char c)
{
    return isalnum(c) || c == '_';
}
