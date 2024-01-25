if( WIN32 )
add_executable( example.inserter.integers.WindowsLargeIntegers example.inserter.integers.WindowsLargeIntegers.cpp )
target_link_libraries( example.inserter.integers.WindowsLargeIntegers
    FastFormat
)
add_custom_target( examples DEPENDS example.inserter.integers.WindowsLargeIntegers )
endif( WIN32 )

