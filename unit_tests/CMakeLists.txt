string(CONCAT GCC_WARNINGS
    " -Wall -Wextra"
	" -Wshadow"
	" -Wnon-virtual-dtor"
	" -Wcast-align"
	" -Wunused"
	" -Woverloaded-virtual"
	" -Wpedantic"
	" -Wmisleading-indentation"
	" -Wduplicated-cond"
	" -Wduplicated-branches"
	" -Wlogical-op"
	" -Wnull-dereference"
	" -Wuseless-cast"
	" -Wdouble-promotion"
	" -Wformat=2"
    )

SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++17 -O2 ${GCC_WARNINGS}")
SET(GCC_COVERAGE_LINK_FLAGS    "-lbenchmark -lpthread -latomic")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

set(UNIT_TEST_LIST slab slab2)

add_library(tests-main OBJECT tests-main.cpp)
 
foreach(NAME IN LISTS UNIT_TEST_LIST)
    #list(APPEND UNIT_TEST_SOURCE_LIST ${NAME}.test.cpp)

    set(TARGET_NAME ${NAME})
     
    add_executable(${TARGET_NAME} ${NAME}.test.cpp $<TARGET_OBJECTS:tests-main>)
     
    add_test(
      NAME ${TARGET_NAME}
      COMMAND ${TARGET_NAME} -o report.xml -r junit)
endforeach()
 
