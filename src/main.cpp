#include "main.h"

using namespace BLSL;

int main()
{
    CNS::err(BLSLModuleTy::LEXER) << "Error! Sample Error haha" << CNS::ENDL << "This is without formatting!" << std::endl;
    CNS::err(BLSLModuleTy::PARSER) << "Error! Parser error!" << CNS::ENDL;
    CNS::err(BLSLModuleTy::VM) << "Error! VM 2!" << CNS::ENDL;
    CNS::err(BLSLModuleTy::PROGRAM) << "error!" << CNS::ENDL;

    CNS::inf(BLSLModuleTy::PARSER) << "Info!" << CNS::ENDL;

    CNS::out() << "Hello! This is a bunch of OUTPUT text. " << CNS::ENDL;


    CNS::flush();

    return 0;
}