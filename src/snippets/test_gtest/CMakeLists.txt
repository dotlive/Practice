cmake_minimum_required(VERSION 2.8.6)
project(test_gtest)

set(proj_name my-gtest)

#plugins root path
set(plugins_path "../../plugins")
#include
set(plugins_inc_path ${plugins_path}/include)
#lib
if (WIN32)
	message("win32")
	set(plugins_lib_path ${plugins_path}/bin/win32/lib/)
	set(plugins_pre_name "")
	set(plugins_ext_name "lib")
elseif (APPLE)
	message("apple")
	set(plugins_lib_path ${plugins_path}/bin/macosx/lib/)
	set(plugins_pre_name "lib")
	set(plugins_ext_name "a")
elseif (UNIX)
	message("unix")
	set(plugins_lib_path ${plugins_path}/bin/unix/lib/)
	set(plugins_pre_name "lib")
	set(plugins_ext_name "a")
else()
	message("linux")
	set(plugins_lib_path ${plugins_path}/bin/linux/lib/)
	set(plugins_pre_name "lib")
	set(plugins_ext_name "a")
endif()

set(gtest_lib
	gtest.${plugins_ext_name}
	gtest_main.${plugins_ext_name}
)


set(src_path "./")
file(GLOB_RECURSE project_headers ${src_path}/*.h)
file(GLOB_RECURSE project_ccs ${src_path}/*.cc)
file(GLOB_RECURSE project_cpps ${src_path}/*.cpp)
set(all_files ${project_headers} ${project_ccs} ${project_cpps})

include_directories(${plugins_inc_path})
include_directories(${plugins_inc_path}/googletest)
include_directories(${src_path})

link_directories(${plugins_lib_path})

add_executable(${proj_name} ${all_files})
target_link_libraries(${proj_name} ${gtest_lib})

#该接口会自行添加库的扩展名
target_link_libraries(${proj_name} ${CMAKE_THREAD_LIBS_INIT})
