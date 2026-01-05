//
// Created by Sid B on 05/01/26.
//

#ifndef BLOSSOM_V_2_ARENA_H
#define BLOSSOM_V_2_ARENA_H
#include <memory>
#include "../coredef/coredef.h"

namespace BLSL
{
    struct ArenaVar
    {
        byte_t* loc;
        size_t size;
    };
    class Arena
    {
    private:
        struct AllocationRegion
        {
            byte_t* loc;
            size_t size;
        };
    private:
        byte_t* _arenaStart;
        std::unordered_map<std::string, ArenaVar> _vTable;
        std::vector<AllocationRegion> _allocationRegions;

    public:
        explicit Arena(size_t size);
        ~Arena();

        byte_t* get_var_address(const std::string& varName) const;
        size_t get_var_size(const std::string& varName) const;
        void alloc_var(const std::string& varName, size_t size);

    };
}


#endif //BLOSSOM_V_2_ARENA_H