# Define the service layer target
add_library(Service STATIC
        PersonService.cpp
)

target_include_directories(Service PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        Model
        Repository
)

target_link_libraries(Service PUBLIC
        Model
        Repository
)