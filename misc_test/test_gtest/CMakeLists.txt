cmake_minimum_required(VERSION 2.8.6)
project(test_gtest)

set(proj_name test11)

#plugins root path
set(plugins_path "../../plugins")
#include
set(plugins_inc_path ${plugins_path}/include)
#lib
if(WIN32)
	set(plugins_lib_path ${plugins_path}/bin/win32/lib/)
	set(plugins_ext_name "lib")
else()
	set(plugins_lib_path ${plugins_path}/bin/linux/lib/)
	set(plugins_ext_name "a")
endif()
set(gtest_lib
	gtest.${plugins_ext_name}
	gtest_main.${plugins_ext_name}
)

enable_testing()
find_package (Threads)

set(src_path "./")

file(GLOB_RECURSE project_headers *.h)
file(GLOB_RECURSE project_cpps *.cc)
set(all_files ${project_headers} ${project_cpps})

include_directories(${plugins_inc_path})
include_directories(${plugins_inc_path}/googletest)
include_directories(${src_path})

link_directories(${plugins_lib_path})

add_executable(${proj_name} ${all_files})
#message(${gtest_lib})
target_link_libraries(${proj_name} ${gtest_lib})
target_link_libraries(${proj_name} ${CMAKE_THREAD_LIBS_INIT})
