# See e.g. https://wincent.com/wiki/@executable_path,_@load_path_and_@rpath

cmake_minimum_required(VERSION 2.8.12)
cmake_policy(SET CMP0042 NEW)     # value not critical for this demo?
set(THELIBDIR "${CMAKE_INSTALL_PREFIX}/lib")

add_library(foo SHARED foo.c)
set_target_properties(
    foo
    PROPERTIES
    INSTALL_NAME_DIR "@rpath"     # so consumers refer to this as @rpath/foo.dylib automatically
)

add_executable(x x.c)
set_target_properties(
    x
    PROPERTIES
    INSTALL_RPATH "${THELIBDIR}"  # add this to the list searched to match @rpath during loading of dylibs this binary consumes
)
target_link_libraries(x foo)
install(TARGETS x foo)
