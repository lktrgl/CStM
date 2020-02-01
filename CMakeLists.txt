cmake_minimum_required(VERSION 3.5)

project ( CStM )

set ( CMAKE_C_STANDARD 99 )
set ( CMAKE_CXX_STANDARD 17 )
set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror -g3 -o0" )
set ( CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3 -o0" )

include_directories (
     include
     )

add_executable ( cstm
     src/main.c
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
     include/custom_state_enum.h
     src/custom_state_default_handler.c
     include/custom_state_default_handler.h
     src/custom_state_data.c
     include/custom_state_data.h
     src/custom_state_diagram.c
     include/custom_state_diagram.h
     src/custom_state_initial.c
     include/custom_state_initial.h
     src/custom_state_first_turn_on.c
     include/custom_state_first_turn_on.h
     src/custom_state_on_dark.c
     include/custom_state_on_dark.h
     src/custom_state_on_wet.c
     include/custom_state_on_wet.h
     src/custom_state_turn_off.c
     include/custom_state_turn_off.h
     src/custom_state_failure.c
     include/custom_state_failure.h
     )

