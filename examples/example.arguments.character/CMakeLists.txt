add_executable( example.arguments.character example.arguments.character.cpp )
target_link_libraries( example.arguments.character
    FastFormat
)
add_custom_target( examples DEPENDS example.arguments.character )

