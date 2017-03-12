if(WIN32)
	if(CMAKE_GENERATOR MATCHES "Win64")
		set(ARCH_NAME "x64")
		set(VS_PLATFORM_NAME "x64")
	elseif(CMAKE_GENERATOR MATCHES "ARM")
		set(ARCH_NAME "arm")
		set(VS_PLATFORM_NAME "ARM")
	else()
		set(ARCH_NAME "x86")
		set(VS_PLATFORM_NAME "Win32")
	endif()
	set(PLATFORM_NAME "nt")
elseif(APPLE)
	if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
		set(ARCH_NAME "x64")
	else()
		set(ARCH_NAME "x86")
	endif()
	set(PLATFORM_NAME "darwin")
else()
	if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
		set(ARCH_NAME "x64")
	else()
		set(ARCH_NAME "x86")
	endif()
	set(PLATFORM_NAME "unix")
endif()

set(PLATFORM_NAME ${PLATFORM_NAME}_${ARCH_NAME})