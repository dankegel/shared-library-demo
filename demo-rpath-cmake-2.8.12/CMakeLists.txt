cmake_minimum_required(VERSION 2.8.12)
set(MYLIBDIR "${CMAKE_SOURCE_DIR}/lib")

add_library(foo SHARED foo.c)
set_target_properties(
    foo
    PROPERTIES
    INSTALL_NAME_DIR "@rpath"
)

add_executable(x x.c)
set_target_properties(
    x
    PROPERTIES
    BUILD_WITH_INSTALL_RPATH 1
    INSTALL_RPATH "${MYLIBDIR}"
)
target_link_libraries(x foo)
