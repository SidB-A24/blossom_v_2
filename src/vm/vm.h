//
// Created by Sid B on 05/01/26.
//

#ifndef BLOSSOM_V_2_VM_H
#define BLOSSOM_V_2_VM_H
#include <queue>
#include <stack>

#include "arena.h"
#include "../coredef/callable.h"

namespace BLSL
{
    class VM
    {
    private:
        std::stack<std::unique_ptr<Callable>> _callStack;
        std::queue<std::unique_ptr<Callable>> _programQueue;

        friend class Callable;
        Arena _arena;

    public:
        void init(size_t stackSize);
        void callstack_populate();
        void callstack_exec();
        void set_program_queue(std::queue<std::unique_ptr<Callable>>&& programQueue);

    };
}

#endif //BLOSSOM_V_2_VM_H