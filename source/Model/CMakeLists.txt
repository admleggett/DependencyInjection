# Model/CMakeLists.txt

# Define the model target
add_library(Model STATIC
        Person.cpp
)

target_include_directories(Model PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
