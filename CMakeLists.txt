cmake_minimum_required (VERSION 2.8.11)
project (sample-app)

find_package(PkgConfig)

pkg_check_modules(DLT REQUIRED automotive-dlt)

add_executable (sample-verbose main-unconverted.c)
add_executable (sample-non-verbose main.c)

target_compile_options(sample-verbose PUBLIC ${DLT_CFLAGS_OTHER})
target_compile_options(sample-non-verbose PUBLIC ${DLT_CFLAGS_OTHER})

target_link_libraries (sample-verbose LINK_PUBLIC ${DLT_LIBRARIES})
target_link_libraries (sample-non-verbose LINK_PUBLIC ${DLT_LIBRARIES})

