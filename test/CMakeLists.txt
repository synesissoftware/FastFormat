cmake_policy(SET CMP0002 OLD) # to allow several times the non global target tests
add_subdirectory (component)
add_subdirectory (performance)
add_subdirectory (scratch)
add_subdirectory (unit)

