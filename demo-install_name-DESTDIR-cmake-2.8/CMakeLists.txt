cmake_minimum_required(VERSION 2.8)
set(MYLIBDIR "${CMAKE_SOURCE_DIR}/lib")

add_library(foo SHARED foo.c)
set_target_properties(
   foo
   PROPERTIES 
   INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
)

add_executable(x x.c)
target_link_libraries(x foo)

install(TARGETS foo x
   RUNTIME DESTINATION "${DESTDIR}${CMAKE_INSTALL_PREFIX}/bin"
   LIBRARY DESTINATION "${DESTDIR}${CMAKE_INSTALL_PREFIX}/lib"
)
