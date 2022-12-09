cmake_minimum_required(VERSION 3.2)

PROJECT(dmcoretest)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

SET(DMCORETEST_VERSION_MAJOR "1")
SET(DMCORETEST_VERSION_MINOR "0")
SET(DMCORETEST_VERSION_PATCH "1")
SET(DMCORETEST_VERSION "${DMCORETEST_VERSION_MAJOR}.${DMCORETEST_VERSION_MINOR}.${DMCORETEST_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMCORETEST_VERSION}")

OPTION(USE_DMCORETEST "use dmcoretest" OFF)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dmcoretest_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dmcoretest_config.h)

ModuleImportAll("thirdparty")
LibImport("dmcoretest_module" "src/dmcoretest_module")
ExeImport("test" "dmcoretest_module")

#ADD_CUSTOM_COMMAND(
#TARGET dmcoretesttest
#PRE_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${CMAKE_CURRENT_SOURCE_DIR}/config/test.csv
#$<TARGET_FILE_DIR:dmcoretesttest>
#)

#INSTALL(DIRECTORY include/ DESTINATION include)
#INSTALL(TARGETS dmcoretest
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#SET(DMCORETEST_LIBS "dmcoretest")
#MARK_AS_ADVANCED(${DMCORETEST_LIBS})