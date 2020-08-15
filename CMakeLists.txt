cmake_minimum_required(VERSION 3.5)

project ( CStM )

set ( CMAKE_C_STANDARD 99 )
set ( CMAKE_CXX_STANDARD 17 )
set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror -g3 -o0" )
set ( CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3 -o0" )

include_directories (
     include
     contrib/lggm/include
     )

set (libsources ${libsources}
     src/CStM/state_node.c
     include/CStM/state_node.h
     src/CStM/state_handler.c
     include/CStM/state_handler.h
     src/CStM/state_transition.c
     include/CStM/state_transition.h
     src/CStM/state_machine.c
     include/CStM/state_machine.h
     src/CStM/vector_state_machine.c
     include/CStM/vector_state_machine.h
     src/CStM/state_default_handler.c
     include/CStM/state_default_handler.h
     contrib/lggm/src/lggm/dbgprn.c
     contrib/lggm/include/lggm/dbgprn.h
     )

add_library ( cstm
    ${libsources}
     )

add_executable(cstm_sample
     src/app/main.c
     include/app/app_states_enum.h
     src/app/app_data.c
     include/app/app_data.h
     src/app/app_state_init.c
     include/app/app_state_init.h
     src/app/app_state_work.c
     include/app/app_state_work.h
     src/app/app_state_failure.c
     include/app/app_state_failure.h
     src/app/app_failure_transition.c
     include/app/app_failure_transition.h
     src/app/app_state_machine.c
     include/app/app_state_machine.h
     )

target_link_libraries(cstm_sample
     cstm
     )
