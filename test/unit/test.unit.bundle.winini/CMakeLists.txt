include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

if( WIN32 )
  add_executable( test.unit.bundle.winini test.unit.bundle.winini.cpp )
  target_link_libraries( test.unit.bundle.winini
      api
      fmt_cache
      fmt_spec_defect_handlers
      init_code_strings
      memory_pool
      replacements
      snprintf
      xTests::xTests
  )
  add_test( test.unit.bundle.winini test.unit.bundle.winini )
  add_custom_target( tests DEPENDS test.unit.bundle.winini )
endif( WIN32 )

