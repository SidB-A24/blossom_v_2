cmake_minimum_required(VERSION 4.0)
project(blossom_v_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(blossom_v_2 src/main.cpp
        src/main.h
        src/coredef/token.cpp
        src/coredef/token.h
        src/coredef/Callable.cpp
        src/coredef/Callable.h
        src/script/parser.cpp
        src/script/parser.h
        src/script/lexer.cpp
        src/script/lexer.h
        src/coredef/coredef.h
        src/cns/cns.h
        src/cns/cns.cpp
        src/coredef/expression.cpp
        src/coredef/expression.h
        src/coredef/operator.cpp
        src/coredef/operator.h
        src/coredef/operator/add.cpp
        src/coredef/operator/add.h
        src/script/subparsers.cpp
        src/script/subparsers.cpp
        src/script/subparsers.cpp
        src/coredef/coredef.cpp
        src/vm/vm.cpp
        src/vm/vm.h
        src/vm/arena.cpp
        src/vm/arena.h)
