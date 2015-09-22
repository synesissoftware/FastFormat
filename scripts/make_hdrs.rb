
# Created: 21st September 2006
# Updated: 20th April 2009

require 'recls'

REL_DIR			=	"../include/fastformat/internal/generated"

NUM_PARAMS		=	48
ENDL			=	"\n"

dir = Recls::stat(REL_DIR)

if not dir
		puts "Cannot stat #{REL_DIR}. Run this only from the scripts directory"
		exit
end

path1	=	Recls::combinePaths(REL_DIR, "helper_functions.hpp")
path2	=	Recls::combinePaths(REL_DIR, "api_functions.hpp")

puts "Generating helper functions: #{path1}"

f1 = File::new(path1, "w")

f1 << "" << "\n"
f1 << "/* File:    #{path1} */" << "\n"
f1 << "/* This file is auto-generated. DO NOT EDIT!!!!! */" << "\n"
f1 << "" << "\n"
f1 << "#ifndef FASTFORMAT_INCLUDING_HELPER_FUNCTIONS" << "\n"
f1 << "# error This file is included by fastformat/fastformat.hpp. It cannot be included directly." << "\n"
f1 << "#endif /* FASTFORMAT_INCLUDING_HELPER_FUNCTIONS */" << "\n"
f1 << "" << "\n"

(0 .. NUM_PARAMS).each \
{ |param|

		# fmt_inner_helper_?()

		f1 << "" << "\n"
		f1 << "template <typename S>" << "\n"
		f1 << "inline S& fmt_inner_helper_#{param}(S& sink, int flags" << "\n"
		if 0 == param
		        f1 << " , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements)" << "\n"
		else
		        f1 << " , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements" << "\n"
				(1 ... param).each \
				{ |n|
						f1 << " , ff_char_t const* p#{n-1}, size_t l#{n-1}" << "\n"
				}
				f1 << " , ff_char_t const* p#{param-1}, size_t l#{param-1})" << "\n"
		end
		f1 << "{" << "\n"
		f1 << " FASTFORMAT_DECLARE_fmt_slices_();" << "\n"
		f1 << " defs::slices_buffer_t results(numResultElements);" << "\n"
		f1 << " size_t actualNumResultElements;" << "\n"
		if param > 0
				f1 << " ff_string_slice_t prms[#{param}];" << "\n"
				f1 << "" << "\n"
		end
		(0 ... param).each \
		{ |n|
				f1 << " prms[#{n}].len = l#{n};" << "\n"
				f1 << " prms[#{n}].ptr = p#{n};" << "\n"
		}
		f1 << "" << "\n"
		if 0 == param
				f1 << " size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, NULL, 0, NULL, NULL, &actualNumResultElements);" << "\n"
		else
				f1 << " size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);" << "\n"
		end
		f1 << " FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), \"actual number of result elements exceeds capacity\");" << "\n"
		if param < 2
				f1 << " // This is a function call, to facilitate customisation" << "\n"
		end
		f1 << " return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);" << "\n"
		f1 << "}" << "\n"

		if param == 0
				f1 << "template <typename S>" << "\n"
		else
				f1 << "template<typename S" << "\n"
				targs = ""
				(0 ... param).each { |n| targs = targs + ", typename A#{n}" }
				f1 << targs << "\n"
				f1 << ">" << "\n"
		end

		if 0 == param
				f1 << "inline S& fmt_outer_helper_#{param}(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements)" << "\n"
		else
				f1 << "inline S& fmt_outer_helper_#{param}(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements" << "\n"
				args = ""
				(0 ... param).each { |n| args = args + ", A#{n} const& arg#{n}" }
				f1 << args << ")" << "\n"
		end
		f1 << "{" << "\n"
		if 0 == param
				f1 << " return fmt_inner_helper_#{param}(sink, flags, formatElements, numFormatElements, numResultElements);\n"
		else
				f1 << " FASTFORMAT_DECLARE_c_str_datalen_PAIR_();" << "\n"
				f1 << "\n"
				f1 << " return fmt_inner_helper_#{param}(sink, flags, formatElements, numFormatElements, numResultElements" << "\n"
				(1 ... param).each \
				{ |n|
					f1 << " , FASTFORMAT_INVOKE_SHIM_PAIR_(arg#{n-1})" << "\n"
				}
				f1 << " , FASTFORMAT_INVOKE_SHIM_PAIR_(arg#{param-1}));" << "\n"
		end
		f1 << "}" << "\n"


		# write_helper_?()

		f1 << "" << "\n"
		f1 << "template <typename S>" << "\n"
		if 0 == param
				f1 << "inline S& write_inner_helper_#{param}(S& sink, int flags)" << "\n"
		else
				f1 << "inline S& write_inner_helper_#{param}(S& sink, int flags" << "\n"
				(1 ... param).each \
				{ |n|
						f1 << " , ff_char_t const* p#{n-1}, size_t l#{n-1}" << "\n"
				}
				f1 << " , ff_char_t const* p#{param-1}, size_t l#{param-1})" << "\n"
		end
		f1 << "{" << "\n"
		f1 << " FASTFORMAT_DECLARE_fmt_slices_();" << "\n"
		if param > 0
				f1 << " ff_string_slice_t prms[#{param}];" << "\n"
				f1 << "" << "\n"
		end
		(0 ... param).each \
		{ |n|
				f1 << " prms[#{n}].len = l#{n};" << "\n"
				f1 << " prms[#{n}].ptr = p#{n};" << "\n"
		}
		if 0 == param
				f1 << " size_t cchTotal = 0;" << "\n"
		else
				f1 << "" << "\n"
				f1 << " size_t cchTotal = l0"
		(1 ... param).each \
		{ |n|
				f1 << " + l#{n}"
		}
				f1 << ";" << "\n"
		end
		f1 << "" << "\n"
		if param > 1 and param < 5
				f1 << " // This is a function call, to facilitate customisation" << "\n"
		end
		if 0 == param
				f1 << " return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, 0, NULL);" << "\n"
		else
				f1 << " return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);" << "\n"
		end
		
		f1 << "}" << "\n"

		if param == 0
				f1 << "template <typename S>" << "\n"
		else
				f1 << "template<typename S" << "\n"
				targs = ""
				(0 ... param).each { |n| targs = targs + ", typename A#{n}" }
				f1 << targs << "\n"
				f1 << ">" << "\n"
		end
		if 0 == param
				f1 << "inline S& write_outer_helper_#{param}(S& sink, int flags)" << "\n"
		else
				f1 << "inline S& write_outer_helper_#{param}(S& sink, int flags" << "\n"
				args = ""
				(0 ... param).each { |n| args = args + ", A#{n} const& arg#{n}" }
				f1 << args << ")" << "\n"
		end
		f1 << "{" << "\n"
		if 0 == param
				f1 << " return write_inner_helper_#{param}(sink, flags);\n"
		else
				f1 << " FASTFORMAT_DECLARE_c_str_datalen_PAIR_();" << "\n"
				f1 << "\n"
				f1 << " return write_inner_helper_#{param}(sink, flags" << "\n"
				(1 ... param).each \
				{ |n|
					f1 << " , FASTFORMAT_INVOKE_SHIM_PAIR_(arg#{n-1})" << "\n"
				}
				f1 << " , FASTFORMAT_INVOKE_SHIM_PAIR_(arg#{param-1}));" << "\n"
		end
		f1 << "}" << "\n"
}

f1.close()

puts "Generating API functions:    #{path2}"

f2 = File::new(path2, "w")

f2 << "" << "\n"
f2 << "/* File:    #{path2} */" << "\n"
f2 << "/* This file is auto-generated. DO NOT EDIT!!!!! */" << "\n"
f2 << "" << "\n"
f2 << "#ifndef FASTFORMAT_INCLUDING_API_FUNCTIONS" << "\n"
f2 << "# error This file is included by fastformat/fastformat.hpp. It cannot be included directly." << "\n"
f2 << "#endif /* FASTFORMAT_INCLUDING_API_FUNCTIONS */" << "\n"
f2 << "" << "\n"
f2 << "" << "\n"
(0 .. NUM_PARAMS).each \
{ |param|

		plural = (1 == param) ? "" : "s"

		# fmt()

	if param > 0
		f2 << "/** Formats #{param} object#{plural} of arbitrary type to the given sink" << ENDL
		f2 << " * \\ingroup group__interface_functions__api_format" << ENDL
		f2 << " * \\param sink The sink to receive the formatted result" << ENDL
		f2 << " * \\param format The format string that defines the formatted result" << ENDL
		(0 ... param).each { |n| f2 << " * \\param arg#{n} parameter #{n}" << ENDL }
		f2 << " * \\note The \\c c_str_data_a() and \\c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice" << ENDL
		f2 << " */" << ENDL

		f2 << "template<typename S, typename F" << "\n"
		if param > 0
				targs = ""
				(0 ... param).each { |n| targs = targs + ", typename A#{n}" }
				f2 << targs << "\n"
		end
		f2 << ">" << "\n"
		f2 << "inline S& fmt(S& sink, F const& format" << "\n"
		args = ""
		(0 ... param).each { |n| args = args + ", A#{n} const& arg#{n}" }
		f2 << args << ")" << "\n"
		f2 << "{" << "\n"
		f2 << " FASTFORMAT_DECLARE_filter_type_();" << "\n"
		f2 << " FASTFORMAT_DECLARE_c_str_datalen_PAIR_();" << "\n"
		f2 << "" << "\n"
		f2 << " const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);" << "\n"
		f2 << "#ifdef FASTFORMAT_NO_USE_JIT_CACHE" << "\n"
		f2 << " defs::format_elements_t formatElements((1 + cchFormat) / 2);" << "\n"
		f2 << " size_t numFormatElements;" << "\n"
		f2 << " size_t numResultElements;" << "\n"
		f2 << " unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);" << "\n"
		f2 << " numFormatElements = n & 0xffff;" << "\n"
		f2 << " numResultElements = n >> 16;" << "\n"
		f2 << " ff_format_element_t *elements = &formatElements[0];" << "\n"
		f2 << "" << "\n"
		f2 << " FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), \"number of pattern elements cannot exceed available capacity\");" << "\n"
		f2 << "#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */" << "\n"
		f2 << " ff_format_element_t const *elements;" << "\n"
		f2 << " size_t numFormatElements;" << "\n"
		f2 << " size_t numResultElements;" << "\n"
		f2 << " unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);" << "\n"
		f2 << " numFormatElements = n & 0xffff;" << "\n"
		f2 << " numResultElements = n >> 16;" << "\n"
		f2 << "#endif /* FASTFORMAT_NO_USE_JIT_CACHE */" << "\n"
		f2 << "" << "\n"
		if param < 2
				f2 << " // This needs to be a function call - RVL!" << "\n"
		end
		if 0 == param
				f2 << " return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_#{param})(sink, 0, elements, numFormatElements, numResultElements);" << "\n"
		else
				f2 << " return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_#{param})(sink, 0, elements, numFormatElements, numResultElements" << "\n"
				(1 ... param).each \
				{ |n|
					f2 << " , FASTFORMAT_INVOKE_filter_type_(arg#{n-1}, &arg#{n-1}, static_cast<ff_char_t const volatile*>(0))" << "\n"
				}
				f2 << " , FASTFORMAT_INVOKE_filter_type_(arg#{param-1}, &arg#{param-1}, static_cast<ff_char_t const volatile*>(0)));" << "\n"
		end
		
		f2 << "}" << "\n"
		f2 << "" << "\n"

		# fmtln()

		f2 << "/** Formats #{param} object#{plural} of arbitrary type to the given sink, appending a newline" << ENDL
		f2 << " * \\ingroup group__interface_functions__api_format" << ENDL
		f2 << " * \\param sink The sink to receive the formatted result" << ENDL
		f2 << " * \\param format The format string that defines the formatted result" << ENDL
		(0 ... param).each { |n| f2 << " * \\param arg#{n} parameter #{n}" << ENDL }
		f2 << " * \\note The \\c c_str_data_a() and \\c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice" << ENDL
		f2 << " */" << ENDL

		f2 << "template<typename S, typename F" << "\n"
		if param > 0
				targs = ""
				(0 ... param).each { |n| targs = targs + ", typename A#{n}" }
				f2 << targs << "\n"
		end
		f2 << ">" << "\n"
		f2 << "inline S& fmtln(S& sink, F const& format" << "\n"
		args = ""
		(0 ... param).each { |n| args = args + ", A#{n} const& arg#{n}" }
		f2 << args << ")" << "\n"
		f2 << "{" << "\n"
		f2 << " FASTFORMAT_DECLARE_filter_type_();" << "\n"
		f2 << " FASTFORMAT_DECLARE_c_str_datalen_PAIR_();" << "\n"
		f2 << "" << "\n"
		f2 << " const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);" << "\n"
		f2 << "#ifdef FASTFORMAT_NO_USE_JIT_CACHE" << "\n"
		f2 << " defs::format_elements_t formatElements((1 + cchFormat) / 2);" << "\n"
		f2 << " size_t numFormatElements;" << "\n"
		f2 << " size_t numResultElements;" << "\n"
		f2 << " unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);" << "\n"
		f2 << " numFormatElements = n & 0xffff;" << "\n"
		f2 << " numResultElements = n >> 16;" << "\n"
		f2 << " ff_format_element_t *elements = &formatElements[0];" << "\n"
		f2 << "" << "\n"
		f2 << " FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), \"number of format elements cannot exceed available capacity\");" << "\n"
		f2 << "#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */" << "\n"
		f2 << " ff_format_element_t const *elements;" << "\n"
		f2 << " size_t numFormatElements;" << "\n"
		f2 << " size_t numResultElements;" << "\n"
		f2 << " unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);" << "\n"
		f2 << " numFormatElements = n & 0xffff;" << "\n"
		f2 << " numResultElements = n >> 16;" << "\n"
		f2 << "#endif /* FASTFORMAT_NO_USE_JIT_CACHE */" << "\n"
		f2 << "" << "\n"
		if param < 2
				f2 << " // This needs to be a function call - RVL!" << "\n"
		end
		if 0 == param
				f2 << " return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_#{param})(sink, flags::ff_newLine, elements, numFormatElements, numResultElements);" << "\n"
		else
				f2 << " return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_#{param})(sink, flags::ff_newLine, elements, numFormatElements, numResultElements" << "\n"
				(1 ... param).each \
				{ |n|
					f2 << " , FASTFORMAT_INVOKE_filter_type_(arg#{n-1}, &arg#{n-1}, static_cast<ff_char_t const volatile*>(0))" << "\n"
				}
				f2 << " , FASTFORMAT_INVOKE_filter_type_(arg#{param-1}, &arg#{param-1}, static_cast<ff_char_t const volatile*>(0)));" << "\n"
		end
		
		f2 << "}" << "\n"
		f2 << "" << "\n"
	end


		# write()

		f2 << "/** Writes #{param} object#{plural} of arbitrary type to the given sink" << ENDL
		f2 << " * \\ingroup group__interface_functions__api_write" << ENDL
		f2 << " * \\param sink The sink to receive the formatted result" << ENDL
		(0 ... param).each { |n| f2 << " * \\param arg#{n} parameter #{n}" << ENDL }
		f2 << " * \\note The \\c c_str_data_a() and \\c c_str_len_a() string access shims are applied to each parameter, to form a string slice" << ENDL
		f2 << " */" << ENDL

		if param == 0
				f2 << "template <typename S>" << "\n"
		else
				f2 << "template<typename S" << "\n"
		end
		if param > 0
				targs = ""
				(0 ... param).each { |n| targs = targs + ", typename A#{n}" }
				f2 << targs << "\n"
				f2 << ">" << "\n"
		end
		if 0 == param
			f2 << "inline S& write(S& sink)" << "\n"
		else
			f2 << "inline S& write(S& sink" << "\n"
			args = ""
			(0 ... param).each { |n| args = args + ", A#{n} const& arg#{n}" }
			f2 << args << ")" << "\n"
		end
		f2 << "{" << "\n"
		if param > 0
				f2 << " FASTFORMAT_DECLARE_filter_type_();" << "\n"
				f2 << "" << "\n"
		end
		if param > 1 and param < 5
				f2 << " // This needs to be a function call - RVL!" << "\n"
		end
		if 0 == param
				f2 << " return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_#{param})(sink, 0);" << "\n"
		else
				f2 << " return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_#{param})(sink, 0" << "\n"
				(1 ... param).each \
				{ |n|
					f2 << " , FASTFORMAT_INVOKE_filter_type_(arg#{n-1}, &arg#{n-1}, static_cast<ff_char_t const volatile*>(0))" << "\n"
				}
				f2 << " , FASTFORMAT_INVOKE_filter_type_(arg#{param-1}, &arg#{param-1}, static_cast<ff_char_t const volatile*>(0)));" << "\n"
		end
		
		f2 << "}" << "\n"
		f2 << "" << "\n"


		# writeln()

		f2 << "/** Writes #{param} object#{plural} of arbitrary type to the given sink, appending a newline" << ENDL
		f2 << " * \\ingroup group__interface_functions__api_write" << ENDL
		f2 << " * \\param sink The sink to receive the formatted result" << ENDL
		(0 ... param).each { |n| f2 << " * \\param arg#{n} parameter #{n}" << ENDL }
		f2 << " * \\note The \\c c_str_data_a() and \\c c_str_len_a() string access shims are applied to each parameter, to form a string slice" << ENDL
		f2 << " */" << ENDL

		if param == 0
				f2 << "template <typename S>" << "\n"
		else
				f2 << "template<typename S" << "\n"
		end
		if param > 0
				targs = ""
				(0 ... param).each { |n| targs = targs + ", typename A#{n}" }
				f2 << targs << "\n"
				f2 << ">" << "\n"
		end
		if 0 == param
			f2 << "inline S& writeln(S& sink)" << "\n"
		else
			f2 << "inline S& writeln(S& sink" << "\n"
			args = ""
			(0 ... param).each { |n| args = args + ", A#{n} const& arg#{n}" }
			f2 << args << ")" << "\n"
		end
		f2 << "{" << "\n"
		if param > 0
				f2 << " FASTFORMAT_DECLARE_filter_type_();" << "\n"
				f2 << "" << "\n"
		end
		if param > 1 and param < 5
				f2 << " // This needs to be a function call - RVL!" << "\n"
		end
		if 0 == param
				f2 << " return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_#{param})(sink, flags::ff_newLine);" << "\n"
		else
				f2 << " return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_#{param})(sink, flags::ff_newLine" << "\n"
				(1 ... param).each \
				{ |n|
					f2 << " , FASTFORMAT_INVOKE_filter_type_(arg#{n-1}, &arg#{n-1}, static_cast<ff_char_t const volatile*>(0))" << "\n"
				}
				f2 << " , FASTFORMAT_INVOKE_filter_type_(arg#{param-1}, &arg#{param-1}, static_cast<ff_char_t const volatile*>(0)));" << "\n"
		end
		
		f2 << "}" << "\n"
		f2 << "" << "\n"
}

f2.close()

exit
