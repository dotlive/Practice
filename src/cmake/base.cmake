##################################################
# Set postfix

set(CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "add a postfix, usually d on windows")
set(CMAKE_RELEASE_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
set(CMAKE_RELWITHDEBINFO_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
set(CMAKE_MINSIZEREL_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(WIN32)
	set(LIB_EXT_NAME "lib")
	set(LIB_PRE_NAME "")
	set(DYN_EXT_NAME "dll")
else()
	set(LIB_EXT_NAME "a")
	set(LIB_PRE_NAME "lib")
	set(DYN_EXT_NAME "so")
endif()


##################################################
# Set directories

set(HOME_DIR "${CMAKE_HOME_DIRECTORY}")
set(3RD_PARTY_HOME_DIR "${HOME_DIR}/3rd_party/")
set(3RD_PARTY_INC_DIR "${3RD_PARTY_HOME_DIR}/include/")
set(3RD_PARTY_BIN_DIR "${3RD_PARTY_HOME_DIR}/bin/${PLATFORM_NAME}/")
set(RUNTIME_OUTPUT_DIR "${HOME_DIR}/bin/${PLATFORM_NAME}")
set(LIBRARY_OUTPUT_DIR "${HOME_DIR}/lib/${PLATFORM_NAME}")


##################################################
macro(CONFIG_OUTPUT_PATHS TARGETNAME)
    set_target_properties(${TARGETNAME}
        PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${RUNTIME_OUTPUT_DIR}
        ARCHIVE_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_DIR}
        LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_DIR}
        DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
    )
endmacro(CONFIG_OUTPUT_PATHS)

macro(source_group_by_dir source_files strip_head)
    if(CMAKE_SYSTEM MATCHES "Windows" OR CMAKE_SYSTEM MATCHES "Darwin")
        set(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
        foreach(sgbd_file ${${source_files}})
            string(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})
            string(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
            string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
            if(sgbd_nogroup)
                set(sgbd_group_name "\\")
			  else()
				 set(strip_len 0)
				 string(LENGTH ${strip_head} strip_len)
				 set(group_len 0)
				 string(LENGTH ${sgbd_group_name}, group_len)
				 string(COMPARE EQUAL ${strip_head} "./" equal_cur)
				 if (NOT (${strip_head} STREQUAL "./"))
					string(SUBSTRING ${sgbd_group_name} ${strip_len} ${group_len} sgbd_group_name)
				 endif()
				 #message(${sgbd_group_name})
            endif(sgbd_nogroup)
            source_group(${sgbd_group_name} FILES ${sgbd_file})
        endforeach(sgbd_file)
    endif(CMAKE_SYSTEM MATCHES "Windows" OR CMAKE_SYSTEM MATCHES "Darwin")
endmacro(source_group_by_dir)