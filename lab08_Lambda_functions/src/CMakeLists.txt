# Source files
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Add the executable target
add_executable(MyApp ${SOURCES})

# Link any additional libraries if needed
# target_link_libraries(MyApp YourAdditionalLibraries)

# Add autorun for lldb
# # Add a custom target to run lldb
# add_custom_target(run-lldb
#     COMMAND lldb ${CMAKE_CURRENT_BINARY_DIR}/MyApp
#     DEPENDS MyApp
#     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
# )

# # Make 'run-lldb' target the default target
# add_custom_target(default_target ALL
#     DEPENDS run-lldb
# )
