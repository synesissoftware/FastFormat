add_executable( FILE FILE.cpp )
target_link_libraries( FILE
    FastFormat
)
add_custom_target( examples DEPENDS FILE )

