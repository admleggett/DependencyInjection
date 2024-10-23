add_subdirectory(Model)
add_subdirectory(Service)
add_subdirectory(Repository)

add_executable(Main main.cpp)

target_link_libraries(Main PRIVATE
        Model
        Service
        Repository
        )
