# Required for ctest (which is just an easier way to run in cross-platform CI)
enable_testing()

# Go into detail when there's a CTest failure
set(CTEST_OUTPUT_ON_FAILURE ON)
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

# "GLOBS ARE BAD" is brittle and silly dev UX, sorry CMake!
file(GLOB_RECURSE TestFiles CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# Organize the test source in the Tests/ folder
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${TestFiles})

# Use GoogleTest
Include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
        GIT_TAG v1.14.0) # Specify the version of GoogleTest you want to use
FetchContent_MakeAvailable(googletest)

# Setup the test executable C++20
add_executable(GTests ${TestFiles})

# Link with GoogleTest (this automatically sets up include directories for GoogleTest)
target_link_libraries(GTests PRIVATE gtest gtest_main gmock gmock_main)


# Our test executable needs to know about our domain code
target_include_directories(GTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../source
)

# Copy over compile definitions from our app target
target_compile_definitions(GTests PRIVATE $<TARGET_PROPERTY:Main,COMPILE_DEFINITIONS>)

# Give GTests access to our shared code
target_link_libraries(GTests PRIVATE
        gtest_main
        Service
        Repository
        gtest
        gmock
        gmock_main
)


# Now that we're using GoogleTest, we can use the GoogleTest module to add GTests
include(GoogleTest)
if(RUN_TESTS)
    gtest_add_tests(TARGET GTests EXTRA_ARGS ${g_testArgs})
endif()
