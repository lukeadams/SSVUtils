cmake_minimum_required(VERSION 3.0)

set(CPM_MODULE_NAME ${CMAKE_PROJECT_NAME})
include(./cmake/modules/CPM-mod.cmake)

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

CPM_ExportAdditionalIncludeDir("./include")
CPM_InitModule(${CPM_MODULE_NAME})
