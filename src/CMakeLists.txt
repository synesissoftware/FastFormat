include_directories (${STLSoft_INCLUDE_DIRS})

add_library (api api.cpp)
target_link_libraries(api memory_pool fmt_cache fmt_spec_defect_handlers)

add_library (fmt_cache fmt_cache.cpp)

add_library (fmt_spec_defect_handlers fmt_spec_defect_handlers.cpp)

add_library (init_code_strings init_code_strings.cpp)

add_library (memory_pool memory_pool.cpp)

add_library (replacements replacements.cpp)
target_link_libraries(replacements api)

add_library (snprintf snprintf.cpp)

