
/* File:    ../include/fastformat/internal/generated/api_functions.hpp */
/* This file is auto-generated. DO NOT EDIT!!!!! */

#ifndef FASTFORMAT_INCLUDING_API_FUNCTIONS
# error This file is included by fastformat/fastformat.hpp. It cannot be included directly.
#endif /* FASTFORMAT_INCLUDING_API_FUNCTIONS */


/** Writes 0 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template <typename S>
inline S& write(S& sink)
{
 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_0)(sink, 0);
}

/** Writes 0 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template <typename S>
inline S& writeln(S& sink)
{
 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_0)(sink, flags::ff_newLine);
}

/** Formats 1 object of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 // This needs to be a function call - RVL!
 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_1)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 1 object of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 // This needs to be a function call - RVL!
 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_1)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 1 object of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0
>
inline S& write(S& sink
, A0 const& arg0)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_1)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 1 object of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0
>
inline S& writeln(S& sink
, A0 const& arg0)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_1)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 2 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_2)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 2 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_2)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 2 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1)
{
 FASTFORMAT_DECLARE_filter_type_();

 // This needs to be a function call - RVL!
 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_2)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 2 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1)
{
 FASTFORMAT_DECLARE_filter_type_();

 // This needs to be a function call - RVL!
 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_2)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 3 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_3)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 3 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_3)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 3 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2)
{
 FASTFORMAT_DECLARE_filter_type_();

 // This needs to be a function call - RVL!
 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_3)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 3 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2)
{
 FASTFORMAT_DECLARE_filter_type_();

 // This needs to be a function call - RVL!
 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_3)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 4 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_4)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 4 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_4)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 4 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3)
{
 FASTFORMAT_DECLARE_filter_type_();

 // This needs to be a function call - RVL!
 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_4)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 4 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3)
{
 FASTFORMAT_DECLARE_filter_type_();

 // This needs to be a function call - RVL!
 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_4)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 5 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_5)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 5 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_5)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 5 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_5)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 5 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_5)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 6 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_6)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 6 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_6)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 6 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_6)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 6 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_6)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 7 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_7)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 7 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_7)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 7 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_7)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 7 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_7)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 8 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_8)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 8 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_8)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 8 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_8)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 8 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_8)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 9 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_9)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 9 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_9)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 9 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_9)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 9 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_9)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 10 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_10)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 10 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_10)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 10 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_10)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 10 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_10)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 11 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_11)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 11 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_11)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 11 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_11)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 11 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_11)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 12 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_12)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 12 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_12)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 12 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_12)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 12 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_12)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 13 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_13)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 13 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_13)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 13 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_13)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 13 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_13)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 14 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_14)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 14 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_14)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 14 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_14)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 14 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_14)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 15 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_15)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 15 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_15)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 15 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_15)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 15 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_15)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 16 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_16)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 16 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_16)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 16 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_16)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 16 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_16)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 17 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_17)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 17 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_17)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 17 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_17)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 17 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_17)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 18 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_18)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 18 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_18)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 18 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_18)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 18 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_18)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 19 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_19)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 19 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_19)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 19 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_19)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 19 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_19)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 20 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_20)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 20 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_20)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 20 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_20)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 20 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_20)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 21 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_21)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 21 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_21)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 21 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_21)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 21 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_21)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 22 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_22)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 22 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_22)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 22 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_22)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 22 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_22)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 23 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_23)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 23 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_23)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 23 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_23)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 23 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_23)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 24 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_24)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 24 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_24)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 24 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_24)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 24 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_24)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 25 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_25)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 25 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_25)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 25 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_25)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 25 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_25)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 26 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_26)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 26 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_26)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 26 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_26)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 26 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_26)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 27 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_27)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 27 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_27)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 27 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_27)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 27 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_27)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 28 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_28)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 28 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_28)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 28 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_28)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 28 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_28)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 29 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_29)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 29 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_29)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 29 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_29)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 29 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_29)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 30 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_30)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 30 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_30)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 30 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_30)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 30 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_30)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 31 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_31)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 31 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_31)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 31 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_31)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 31 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_31)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 32 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_32)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 32 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_32)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 32 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_32)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 32 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_32)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 33 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_33)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 33 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_33)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 33 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_33)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 33 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_33)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 34 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_34)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 34 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_34)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 34 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_34)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 34 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_34)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 35 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_35)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 35 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_35)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 35 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_35)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 35 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_35)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 36 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_36)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 36 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_36)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 36 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_36)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 36 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_36)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 37 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_37)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 37 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_37)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 37 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_37)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 37 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_37)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 38 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_38)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 38 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_38)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 38 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_38)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 38 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_38)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 39 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_39)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 39 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_39)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 39 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_39)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 39 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_39)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 40 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_40)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 40 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_40)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 40 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_40)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 40 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_40)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 41 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_41)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 41 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_41)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 41 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_41)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 41 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_41)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 42 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_42)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 42 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_42)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 42 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_42)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 42 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_42)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 43 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_43)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 43 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_43)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 43 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_43)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 43 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_43)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 44 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_44)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 44 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_44)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 44 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_44)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 44 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_44)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 45 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_45)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 45 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_45)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 45 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_45)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 45 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_45)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 46 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_46)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 46 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_46)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 46 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_46)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 46 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_46)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 47 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \param arg46 parameter 46
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_47)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg46, &arg46, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 47 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \param arg46 parameter 46
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_47)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg46, &arg46, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 47 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \param arg46 parameter 46
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_47)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg46, &arg46, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 47 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \param arg46 parameter 46
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_47)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg46, &arg46, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 48 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \param arg46 parameter 46
 * \param arg47 parameter 47
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47
>
inline S& fmt(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46, A47 const& arg47)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of pattern elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_48)(sink, 0, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg46, &arg46, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg47, &arg47, static_cast<ff_char_t const volatile*>(0)));
}

/** Formats 48 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_format
 * \param sink The sink to receive the formatted result
 * \param format The format string that defines the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \param arg46 parameter 46
 * \param arg47 parameter 47
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to the format and to each parameter, to form a string slice
 */
template<typename S, typename F
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47
>
inline S& fmtln(S& sink, F const& format
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46, A47 const& arg47)
{
 FASTFORMAT_DECLARE_filter_type_();
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 const size_t cchFormat = FASTFORMAT_INVOKE_c_str_len_(format);
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
 defs::format_elements_t formatElements((1 + cchFormat) / 2);
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_parseFormat(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &formatElements[0], formatElements.size(), NULL, NULL);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
 ff_format_element_t *elements = &formatElements[0];

 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(numFormatElements <= formatElements.size(), "number of format elements cannot exceed available capacity");
#else /* ? FASTFORMAT_NO_USE_JIT_CACHE */
 ff_format_element_t const *elements;
 size_t numFormatElements;
 size_t numResultElements;
 unsigned n = fastformat_lookupPattern(FASTFORMAT_INVOKE_c_str_data_(format), cchFormat, &elements);
 numFormatElements = n & 0xffff;
 numResultElements = n >> 16;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */

 return FASTFORMAT_QUALIFY_HELPER_(fmt_outer_helper_48)(sink, flags::ff_newLine, elements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg46, &arg46, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg47, &arg47, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 48 objects of arbitrary type to the given sink
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \param arg46 parameter 46
 * \param arg47 parameter 47
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47
>
inline S& write(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46, A47 const& arg47)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_48)(sink, 0
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg46, &arg46, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg47, &arg47, static_cast<ff_char_t const volatile*>(0)));
}

/** Writes 48 objects of arbitrary type to the given sink, appending a newline
 * \ingroup group__interface_functions__api_write
 * \param sink The sink to receive the formatted result
 * \param arg0 parameter 0
 * \param arg1 parameter 1
 * \param arg2 parameter 2
 * \param arg3 parameter 3
 * \param arg4 parameter 4
 * \param arg5 parameter 5
 * \param arg6 parameter 6
 * \param arg7 parameter 7
 * \param arg8 parameter 8
 * \param arg9 parameter 9
 * \param arg10 parameter 10
 * \param arg11 parameter 11
 * \param arg12 parameter 12
 * \param arg13 parameter 13
 * \param arg14 parameter 14
 * \param arg15 parameter 15
 * \param arg16 parameter 16
 * \param arg17 parameter 17
 * \param arg18 parameter 18
 * \param arg19 parameter 19
 * \param arg20 parameter 20
 * \param arg21 parameter 21
 * \param arg22 parameter 22
 * \param arg23 parameter 23
 * \param arg24 parameter 24
 * \param arg25 parameter 25
 * \param arg26 parameter 26
 * \param arg27 parameter 27
 * \param arg28 parameter 28
 * \param arg29 parameter 29
 * \param arg30 parameter 30
 * \param arg31 parameter 31
 * \param arg32 parameter 32
 * \param arg33 parameter 33
 * \param arg34 parameter 34
 * \param arg35 parameter 35
 * \param arg36 parameter 36
 * \param arg37 parameter 37
 * \param arg38 parameter 38
 * \param arg39 parameter 39
 * \param arg40 parameter 40
 * \param arg41 parameter 41
 * \param arg42 parameter 42
 * \param arg43 parameter 43
 * \param arg44 parameter 44
 * \param arg45 parameter 45
 * \param arg46 parameter 46
 * \param arg47 parameter 47
 * \note The \c c_str_data_a() and \c c_str_len_a() string access shims are applied to each parameter, to form a string slice
 */
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47
>
inline S& writeln(S& sink
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46, A47 const& arg47)
{
 FASTFORMAT_DECLARE_filter_type_();

 return FASTFORMAT_QUALIFY_HELPER_(write_outer_helper_48)(sink, flags::ff_newLine
 , FASTFORMAT_INVOKE_filter_type_(arg0, &arg0, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg1, &arg1, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg2, &arg2, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg3, &arg3, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg4, &arg4, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg5, &arg5, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg6, &arg6, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg7, &arg7, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg8, &arg8, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg9, &arg9, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg10, &arg10, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg11, &arg11, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg12, &arg12, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg13, &arg13, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg14, &arg14, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg15, &arg15, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg16, &arg16, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg17, &arg17, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg18, &arg18, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg19, &arg19, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg20, &arg20, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg21, &arg21, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg22, &arg22, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg23, &arg23, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg24, &arg24, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg25, &arg25, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg26, &arg26, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg27, &arg27, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg28, &arg28, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg29, &arg29, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg30, &arg30, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg31, &arg31, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg32, &arg32, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg33, &arg33, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg34, &arg34, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg35, &arg35, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg36, &arg36, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg37, &arg37, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg38, &arg38, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg39, &arg39, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg40, &arg40, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg41, &arg41, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg42, &arg42, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg43, &arg43, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg44, &arg44, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg45, &arg45, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg46, &arg46, static_cast<ff_char_t const volatile*>(0))
 , FASTFORMAT_INVOKE_filter_type_(arg47, &arg47, static_cast<ff_char_t const volatile*>(0)));
}

