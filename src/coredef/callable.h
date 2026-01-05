//
// Created by Sid B on 22/12/25.
//

#ifndef BLOSSOM_V_2_CALLABLE_H
#define BLOSSOM_V_2_CALLABLE_H

#include "token.h"
#include <functional>

namespace BLSL
{
    class VM;

    class Callable
    {
    public:
        virtual ~Callable() = default;

        virtual void call(VM& vm) = 0;
    private:
    };

    class Parser;

    //typedef std::shared_ptr<Callable> (*parsec_t)(Parser& parser);


}

namespace BLSL
{
    class MemMake : virtual public Callable
    {
    private:
        size_t bytes;
    public:
        MemMake(size_t size) : bytes(size) {}
        ~MemMake() override;

        void call(VM& vm) override;
    };

}



#endif //BLOSSOM_V_2_CALLABLE_H