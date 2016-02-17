include_directories(
    ${STLSoft_INCLUDE_DIRS}
    ${xTests_INCLUDE_DIRS}
)

if( WIN32 )
  add_executable( test.scratch.overload.3.BSTR_out_parameter test.scratch.overload.3.BSTR_out_parameter.cpp )
  target_link_libraries( test.scratch.overload.3.BSTR_out_parameter
      api
      fmt_cache
      fmt_spec_defect_handlers
      init_code_strings
      memory_pool
      replacements
      snprintf
      xTests::xTests
  )
  add_test( test.scratch.overload.3.BSTR_out_parameter test.scratch.overload.3.BSTR_out_parameter )
  add_custom_target( tests DEPENDS test.scratch.overload.3.BSTR_out_parameter )
endif( WIN32 )

