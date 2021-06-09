add_executable( example.overload.3.tabulations example.overload.3.tabulations.cpp )
target_link_libraries( example.overload.3.tabulations
    FastFormat
)
add_custom_target( examples DEPENDS example.overload.3.tabulations )

