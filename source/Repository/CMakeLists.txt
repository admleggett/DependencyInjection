add_library(Repository STATIC
        PersonRepository.cpp
)

target_include_directories(Service PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        Model
)

target_link_libraries(Service PUBLIC
        Model
)