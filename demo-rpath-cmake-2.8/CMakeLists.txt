cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0042 OLD)       # value not critical for this demo?
set(MYLIBDIR "${CMAKE_SOURCE_DIR}/lib")

add_library(foo SHARED foo.c)
ADD_CUSTOM_COMMAND(TARGET foo POST_BUILD
   COMMAND install_name_tool -id @rpath/libfoo.dylib libfoo.dylib
)

add_executable(x x.c)
set_target_properties(x PROPERTIES LINK_FLAGS "-Wl,-rpath ${MYLIBDIR}")
target_link_libraries(x foo)
