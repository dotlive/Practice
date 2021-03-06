
if(WIN32)
	add_definitions(-DUNICODE -D_UNICODE)

	#编译选项
	set(CMAKE_C_FLAGS "/DWIN32 /D_WINDOWS /W4 /WX /GR /EHsc /wd4503")
	set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W4 /WX /GR /EHsc /wd4503 /wd4512 /wd4244 /wd4996 /wd4125 /wd4127")

	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /fp:fast /GS-")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /fp:fast /GS-")
	set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /fp:fast /GS-")

	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MP")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MP")
	set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /MP")

	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /LARGEADDRESSAWARE")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LARGEADDRESSAWARE")

	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Qpar")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /Qpar")
	set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /Qpar")

	set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MDd /Zi /Ob0 /Od /RTC1")
	set(CMAKE_CXX_FLAGS_MINSIZEREL "/MD /O1 /Ob1 /D NDEBUG")
	set(CMAKE_CXX_FLAGS_RELEASE "/MD /O2 /Ob2 /D NDEBUG")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MD /Zi /O2 /Ob1 /D NDEBUG")

	set(CMAKE_EXE_LINKER_FLAGS "/WX")
	set(CMAKE_SHARED_LINKER_FLAGS "/WX")

	#链接选项
	set(CMAKE_EXE_LINKER_FLAGS_DEBUG "/DEBUG /INCREMENTAL /SAFESEH:NO")
	set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "/DEBUG /INCREMENTAL /SAFESEH:NO")
	set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "/DEBUG /INCREMENTAL /SAFESEH:NO")
	set(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO "/DEBUG /INCREMENTAL /SAFESEH:NO")

	if(ARCH_NAME MATCHES "x86")
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /arch:SSE")
		set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /arch:SSE")
		set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /arch:SSE")
	endif()

	#编译器定义，仅支持vc14
	set(COMPILER_NAME "vc")
	set(COMPILER_VERSION "14")
	set(VC_NAME ${COMPILER_NAME}${COMPILER_VERSION})

	# create vcproj.user file for Visual Studio to set debug working directory
	function(CREATE_VCPROJ_USERFILE TARGETNAME proj_dir)
		SET(SYSTEM_NAME $ENV{USERDOMAIN})
		SET(USER_NAME $ENV{USERNAME})

		configure_file(
				${proj_dir}/../cmake/VSUserFile.vcxproj.user.in
				${CMAKE_CURRENT_BINARY_DIR}/${TARGETNAME}.vcxproj.user
				@ONLY
			)
	endfunction()
elseif(APPLE)
	set(COMPILER_NAME "xcode")
	set(COMPILER_VERSION "8")
	set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
	set(CMAKE_EXE_LINKER_FLAGS "-stdlib=libc++")
	set(CMAKE_SHARED_LINKER_FLAGS "-stdlib=libc++")

	if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG=3")
		set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG=4")
        add_definitions(-DDEBUG)
	endif()
endif()