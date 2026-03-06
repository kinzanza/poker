add_library(controller src/*)
target_include_directories(include)
target_link_libraries(controller PUBLIC logic )
target_link_libraries(controller PUBLIC net )
target_link_libraries(controller PUBLIC ui )

