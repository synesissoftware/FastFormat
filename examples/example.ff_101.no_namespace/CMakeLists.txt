add_executable( example.ff_101.no_namespace example.ff_101.no_namespace.cpp )
target_link_libraries( example.ff_101.no_namespace
    FastFormat
)
add_custom_target( examples DEPENDS example.ff_101.no_namespace )

