cmake_minimum_required(VERSION 3.16)
project(lexmath LANGUAGES C VERSION 1.0)

include(GNUInstallDirs)

add_library(lexmath SHARED
    src/lexmath.c
)
add_library(lexmathstatic STATIC
    src/lexmath.c
)
set_target_properties(lexmathstatic PROPERTIES OUTPUT_NAME lexmath)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS lexmath lexmathstatic)
install(FILES include/lexmath.h DESTINATION include)

if(UNIX AND NOT DO_NOT_LDCONFIG)
    install(CODE "execute_process(COMMAND ldconfig)")
endif()
