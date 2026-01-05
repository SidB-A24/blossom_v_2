//
// Created by Sid B on 05/01/26.
//

#include "arena.h"
#include "../cns/cns.h"

BLSL::Arena::Arena(size_t size)
{
    _arenaStart = new(std::nothrow) byte_t[size];

    if (_arenaStart == nullptr)
    {
        CNS::err(BLSLModuleTy::VM) << "Unable to allocate memory of size: " << size << " in Arena." << CNS::ENDL;
        throw std::bad_alloc();
    }

    AllocationRegion aRegion;
    aRegion.loc = _arenaStart;
    aRegion.size = size;

    _allocationRegions.push_back(aRegion);

    CNS::inf(BLSLModuleTy::VM) << "Initialized Arena of size: " << size << " at: " << _arenaStart << CNS::ENDL;
}

BLSL::Arena::~Arena()
{
    _vTable.clear();
    _allocationRegions.clear();

    delete _arenaStart;
}

BLSL::byte_t * BLSL::Arena::get_var_address(const std::string &varName) const
{
    if (_vTable.contains(varName))
    {
        return (_vTable.at(varName).loc);
    }

    CNS::err(BLSLModuleTy::VM) << "Variable: '" << varName << "' not found in Arena." << CNS::ENDL;
    throw;
}

size_t BLSL::Arena::get_var_size(const std::string &varName) const
{
    if (_vTable.contains(varName))
    {
        return (_vTable.at(varName).size);
    }

    CNS::err(BLSLModuleTy::VM) << "Variable: '" << varName << "' not found in Arena." << CNS::ENDL;
    throw std::runtime_error("Variable not found in Arena.");
}

void BLSL::Arena::alloc_var(const std::string &varName, size_t size)
{

    for (size_t i = _allocationRegions.size(); i > 0; --i)
    {
        auto &aRegion = _allocationRegions[i];

        if (aRegion.size == size)
        {
            ArenaVar var;
            var.size = size;
            var.loc = aRegion.loc;

            _allocationRegions.erase(_allocationRegions.begin() + i);

            _vTable.insert(std::make_pair(varName, var));

            CNS::inf(BLSLModuleTy::PROGRAM) << "Allocated variable '" << varName << "' at: " << var.loc << CNS::ENDL;

            return;
        }

        if (aRegion.size > size)
        {
            ArenaVar var;
            var.size = size;
            var.loc = aRegion.loc;

            aRegion.size -= size;
            aRegion.loc += size;

            _vTable.insert(std::make_pair(varName, var));

            CNS::inf(BLSLModuleTy::PROGRAM) << "Allocated variable '" << varName << "' at: " << var.loc << CNS::ENDL;

            return;
        }
    }

    CNS::err(BLSLModuleTy::VM) << "Unable to locate valid allocation region of size: " << size << " in Arena." << CNS::ENDL;
    throw;
}






