SET(oc_SOURCES oc.c daplex.c dapparse.c dapy.c occlientparams.c occompile.c occurlfunctions.c ocdata.c ocdebug.c ocdump.c ocinternal.c ocnode.c ochttp.c ocrc.c ocread.c ocutil.c occurlflags.c xxdr.c)

add_library(oc2 OBJECT ${oc_SOURCES}) 

# Apparently fails under cmake
#set(ocprint_FILES ocprint.c )
#ADD_EXECUTABLE(ocprint ${ocprint_FILES})
#TARGET_LINK_LIBRARIES(ocprint oc2 ${ALL_TLL_LIBS})

## Specify files to be distributed by 'make dist'
FILE(GLOB CUR_EXTRA_DIST RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.c ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.sh)
SET(CUR_EXTRA_DIST ${CUR_EXTRA_DIST} CMakeLists.txt Makefile.am)
SET(CUR_EXTRA_DIST ${CUR_EXTRA_DIST} dap.y)
SET(CUR_EXTRA_DIST ${CUR_EXTRA_DIST} ocauth.html)
ADD_EXTRA_DIST("${CUR_EXTRA_DIST}")
