if( WIN32 )
add_executable( example.sink.OutputDebugString example.sink.OutputDebugString.cpp )
target_link_libraries( example.sink.OutputDebugString
    FastFormat
)
add_custom_target( examples DEPENDS example.sink.OutputDebugString )
endif( WIN32 )

