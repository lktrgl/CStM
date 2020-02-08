cmake_minimum_required(VERSION 3.5)

project ( CStM )

set ( CMAKE_C_STANDARD 99 )
set ( CMAKE_CXX_STANDARD 17 )
set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror -g3 -o0" )
set ( CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3 -o0" )

include_directories (
     include
     )

add_library ( cstm
     src/CStM/state_node.c
     include/CStM/state_node.h
     src/CStM/state_handler.c
     include/CStM/state_handler.h
     src/CStM/state_transition.c
     include/CStM/state_transition.h
     src/CStM/state_machine.c
     include/CStM/state_machine.h
     src/CStM/state_default_handler.c
     include/CStM/state_default_handler.h
     src/trace/dbgprn.c
     include/trace/dbgprn.h
     )

