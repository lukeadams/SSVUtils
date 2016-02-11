cmake_minimum_required(VERSION 3.0)
project(SSVUtils)
#-----------------------------------------------------------------------
# CPM configuration
#-----------------------------------------------------------------------
set(CPM_MODULE_NAME ${CMAKE_PROJECT_NAME})
set(CPM_LIB_TARGET_NAME ${CPM_MODULE_NAME})

if ((DEFINED CPM_DIR) AND (DEFINED CPM_UNIQUE_ID) AND (DEFINED CPM_TARGET_NAME))
	set(CPM_LIB_TARGET_NAME ${CPM_TARGET_NAME})
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CPM_DIR})
	include(CPM)
else()
	set(CPM_DIR "${CMAKE_CURRENT_BINARY_DIR}/cpm-packages" CACHE TYPE STRING)
	find_package(Git)
	if(NOT GIT_FOUND)
		message(FATAL_ERROR "CPM requires Git.")
	endif()
	if (NOT EXISTS ${CPM_DIR}/CPM.cmake)
		message(STATUS "Cloning repo (https://github.com/iauns/cpm)")
		execute_process(
			COMMAND "${GIT_EXECUTABLE}" clone https://github.com/iauns/cpm ${CPM_DIR}
			RESULT_VARIABLE error_code
			OUTPUT_QUIET ERROR_QUIET)
		if(error_code)
			message(FATAL_ERROR "CPM failed to get the hash for HEAD")
		endif()
	endif()
	include(${CPM_DIR}/CPM.cmake)
endif()

# Include SSVCmake.
SET(SSVDepsRoot "https://github.com/lukeadams/")
CPM_AddModule("SSVCMake"
	GIT_REPOSITORY "${SSVDepsRoot}SSVCMake"
	USE_EXISTING_VER false
	GIT_TAG "cpm")
SET(CMAKE_MODULE_PATH ${CPM_KV_SOURCEDIR_MAP_SSVCMake}/cmake/modules ${CMAKE_MODULE_PATH})
include(SSVCMake)

CPM_AddModule("vrm_pp"
	GIT_REPOSITORY "${SSVDepsRoot}vrm_pp"
	USE_EXISTING_VER false
	GIT_TAG "cpm")
SET(CMAKE_MODULE_PATH ${CPM_KV_SOURCEDIR_MAP_vrm_pp} ${CMAKE_MODULE_PATH})

include(vrm_pp)

# Basic project setup.
vrm_cmake_init_project(SSVUtils)
vrm_cmake_find_extlib(vrm_pp)

# Alias the include directory.
set(SSVUTILS_INC_DIR "${SSVUTILS_SOURCE_DIR}/include/")

# Other compiler flags.
vrm_cmake_add_common_compiler_flags()

# Setup user options.
vrm_cmake_add_option_memcheck()
vrm_cmake_add_option_no_exceptions()
vrm_cmake_add_option_werror()

# The `check` target runs all tests and examples.
vrm_check_target()

# Setup subdirectories.
add_subdirectory(test)

# Create header-only install target (automatically glob)
vrm_cmake_header_only_install_glob("${SSVUTILS_INC_DIR}" "include")

CPM_InitModule(${CPM_MODULE_NAME})
