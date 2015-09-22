
/* File:    ../include/fastformat/internal/generated/helper_functions.hpp */
/* This file is auto-generated. DO NOT EDIT!!!!! */

#ifndef FASTFORMAT_INCLUDING_HELPER_FUNCTIONS
# error This file is included by fastformat/fastformat.hpp. It cannot be included directly.
#endif /* FASTFORMAT_INCLUDING_HELPER_FUNCTIONS */


template <typename S>
inline S& fmt_inner_helper_0(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, NULL, 0, NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 // This is a function call, to facilitate customisation
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template <typename S>
inline S& fmt_outer_helper_0(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements)
{
 return fmt_inner_helper_0(sink, flags, formatElements, numFormatElements, numResultElements);
}

template <typename S>
inline S& write_inner_helper_0(S& sink, int flags)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 size_t cchTotal = 0;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, 0, NULL);
}
template <typename S>
inline S& write_outer_helper_0(S& sink, int flags)
{
 return write_inner_helper_0(sink, flags);
}

template <typename S>
inline S& fmt_inner_helper_1(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[1];

 prms[0].len = l0;
 prms[0].ptr = p0;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 // This is a function call, to facilitate customisation
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0
>
inline S& fmt_outer_helper_1(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_1(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0));
}

template <typename S>
inline S& write_inner_helper_1(S& sink, int flags
 , ff_char_t const* p0, size_t l0)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[1];

 prms[0].len = l0;
 prms[0].ptr = p0;

 size_t cchTotal = l0;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0
>
inline S& write_outer_helper_1(S& sink, int flags
, A0 const& arg0)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_1(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0));
}

template <typename S>
inline S& fmt_inner_helper_2(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[2];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1
>
inline S& fmt_outer_helper_2(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_2(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1));
}

template <typename S>
inline S& write_inner_helper_2(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[2];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;

 size_t cchTotal = l0 + l1;

 // This is a function call, to facilitate customisation
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1
>
inline S& write_outer_helper_2(S& sink, int flags
, A0 const& arg0, A1 const& arg1)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_2(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1));
}

template <typename S>
inline S& fmt_inner_helper_3(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[3];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2
>
inline S& fmt_outer_helper_3(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_3(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2));
}

template <typename S>
inline S& write_inner_helper_3(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[3];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;

 size_t cchTotal = l0 + l1 + l2;

 // This is a function call, to facilitate customisation
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2
>
inline S& write_outer_helper_3(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_3(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2));
}

template <typename S>
inline S& fmt_inner_helper_4(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[4];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3
>
inline S& fmt_outer_helper_4(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_4(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3));
}

template <typename S>
inline S& write_inner_helper_4(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[4];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;

 size_t cchTotal = l0 + l1 + l2 + l3;

 // This is a function call, to facilitate customisation
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3
>
inline S& write_outer_helper_4(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_4(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3));
}

template <typename S>
inline S& fmt_inner_helper_5(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[5];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4
>
inline S& fmt_outer_helper_5(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_5(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4));
}

template <typename S>
inline S& write_inner_helper_5(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[5];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4
>
inline S& write_outer_helper_5(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_5(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4));
}

template <typename S>
inline S& fmt_inner_helper_6(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[6];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
>
inline S& fmt_outer_helper_6(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_6(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5));
}

template <typename S>
inline S& write_inner_helper_6(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[6];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
>
inline S& write_outer_helper_6(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_6(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5));
}

template <typename S>
inline S& fmt_inner_helper_7(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[7];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
>
inline S& fmt_outer_helper_7(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_7(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6));
}

template <typename S>
inline S& write_inner_helper_7(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[7];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
>
inline S& write_outer_helper_7(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_7(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6));
}

template <typename S>
inline S& fmt_inner_helper_8(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[8];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7
>
inline S& fmt_outer_helper_8(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_8(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7));
}

template <typename S>
inline S& write_inner_helper_8(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[8];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7
>
inline S& write_outer_helper_8(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_8(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7));
}

template <typename S>
inline S& fmt_inner_helper_9(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[9];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8
>
inline S& fmt_outer_helper_9(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_9(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8));
}

template <typename S>
inline S& write_inner_helper_9(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[9];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8
>
inline S& write_outer_helper_9(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_9(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8));
}

template <typename S>
inline S& fmt_inner_helper_10(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[10];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9
>
inline S& fmt_outer_helper_10(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_10(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9));
}

template <typename S>
inline S& write_inner_helper_10(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[10];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9
>
inline S& write_outer_helper_10(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_10(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9));
}

template <typename S>
inline S& fmt_inner_helper_11(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[11];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10
>
inline S& fmt_outer_helper_11(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_11(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10));
}

template <typename S>
inline S& write_inner_helper_11(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[11];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10
>
inline S& write_outer_helper_11(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_11(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10));
}

template <typename S>
inline S& fmt_inner_helper_12(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[12];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11
>
inline S& fmt_outer_helper_12(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_12(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11));
}

template <typename S>
inline S& write_inner_helper_12(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[12];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11
>
inline S& write_outer_helper_12(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_12(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11));
}

template <typename S>
inline S& fmt_inner_helper_13(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[13];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12
>
inline S& fmt_outer_helper_13(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_13(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12));
}

template <typename S>
inline S& write_inner_helper_13(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[13];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12
>
inline S& write_outer_helper_13(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_13(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12));
}

template <typename S>
inline S& fmt_inner_helper_14(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[14];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13
>
inline S& fmt_outer_helper_14(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_14(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13));
}

template <typename S>
inline S& write_inner_helper_14(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[14];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13
>
inline S& write_outer_helper_14(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_14(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13));
}

template <typename S>
inline S& fmt_inner_helper_15(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[15];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14
>
inline S& fmt_outer_helper_15(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_15(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14));
}

template <typename S>
inline S& write_inner_helper_15(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[15];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14
>
inline S& write_outer_helper_15(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_15(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14));
}

template <typename S>
inline S& fmt_inner_helper_16(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[16];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15
>
inline S& fmt_outer_helper_16(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_16(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15));
}

template <typename S>
inline S& write_inner_helper_16(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[16];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15
>
inline S& write_outer_helper_16(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_16(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15));
}

template <typename S>
inline S& fmt_inner_helper_17(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[17];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16
>
inline S& fmt_outer_helper_17(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_17(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16));
}

template <typename S>
inline S& write_inner_helper_17(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[17];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16
>
inline S& write_outer_helper_17(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_17(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16));
}

template <typename S>
inline S& fmt_inner_helper_18(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[18];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17
>
inline S& fmt_outer_helper_18(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_18(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17));
}

template <typename S>
inline S& write_inner_helper_18(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[18];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17
>
inline S& write_outer_helper_18(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_18(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17));
}

template <typename S>
inline S& fmt_inner_helper_19(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[19];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18
>
inline S& fmt_outer_helper_19(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_19(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18));
}

template <typename S>
inline S& write_inner_helper_19(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[19];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18
>
inline S& write_outer_helper_19(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_19(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18));
}

template <typename S>
inline S& fmt_inner_helper_20(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[20];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19
>
inline S& fmt_outer_helper_20(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_20(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19));
}

template <typename S>
inline S& write_inner_helper_20(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[20];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19
>
inline S& write_outer_helper_20(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_20(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19));
}

template <typename S>
inline S& fmt_inner_helper_21(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[21];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20
>
inline S& fmt_outer_helper_21(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_21(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20));
}

template <typename S>
inline S& write_inner_helper_21(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[21];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20
>
inline S& write_outer_helper_21(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_21(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20));
}

template <typename S>
inline S& fmt_inner_helper_22(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[22];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21
>
inline S& fmt_outer_helper_22(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_22(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21));
}

template <typename S>
inline S& write_inner_helper_22(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[22];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21
>
inline S& write_outer_helper_22(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_22(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21));
}

template <typename S>
inline S& fmt_inner_helper_23(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[23];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22
>
inline S& fmt_outer_helper_23(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_23(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22));
}

template <typename S>
inline S& write_inner_helper_23(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[23];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22
>
inline S& write_outer_helper_23(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_23(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22));
}

template <typename S>
inline S& fmt_inner_helper_24(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[24];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23
>
inline S& fmt_outer_helper_24(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_24(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23));
}

template <typename S>
inline S& write_inner_helper_24(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[24];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23
>
inline S& write_outer_helper_24(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_24(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23));
}

template <typename S>
inline S& fmt_inner_helper_25(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[25];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24
>
inline S& fmt_outer_helper_25(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_25(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24));
}

template <typename S>
inline S& write_inner_helper_25(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[25];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24
>
inline S& write_outer_helper_25(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_25(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24));
}

template <typename S>
inline S& fmt_inner_helper_26(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[26];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25
>
inline S& fmt_outer_helper_26(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_26(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25));
}

template <typename S>
inline S& write_inner_helper_26(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[26];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25
>
inline S& write_outer_helper_26(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_26(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25));
}

template <typename S>
inline S& fmt_inner_helper_27(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[27];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26
>
inline S& fmt_outer_helper_27(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_27(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26));
}

template <typename S>
inline S& write_inner_helper_27(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[27];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26
>
inline S& write_outer_helper_27(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_27(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26));
}

template <typename S>
inline S& fmt_inner_helper_28(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[28];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27
>
inline S& fmt_outer_helper_28(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_28(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27));
}

template <typename S>
inline S& write_inner_helper_28(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[28];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27
>
inline S& write_outer_helper_28(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_28(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27));
}

template <typename S>
inline S& fmt_inner_helper_29(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[29];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28
>
inline S& fmt_outer_helper_29(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_29(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28));
}

template <typename S>
inline S& write_inner_helper_29(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[29];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28
>
inline S& write_outer_helper_29(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_29(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28));
}

template <typename S>
inline S& fmt_inner_helper_30(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[30];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29
>
inline S& fmt_outer_helper_30(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_30(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29));
}

template <typename S>
inline S& write_inner_helper_30(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[30];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29
>
inline S& write_outer_helper_30(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_30(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29));
}

template <typename S>
inline S& fmt_inner_helper_31(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[31];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30
>
inline S& fmt_outer_helper_31(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_31(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30));
}

template <typename S>
inline S& write_inner_helper_31(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[31];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30
>
inline S& write_outer_helper_31(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_31(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30));
}

template <typename S>
inline S& fmt_inner_helper_32(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[32];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31
>
inline S& fmt_outer_helper_32(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_32(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31));
}

template <typename S>
inline S& write_inner_helper_32(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[32];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31
>
inline S& write_outer_helper_32(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_32(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31));
}

template <typename S>
inline S& fmt_inner_helper_33(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[33];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32
>
inline S& fmt_outer_helper_33(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_33(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32));
}

template <typename S>
inline S& write_inner_helper_33(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[33];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32
>
inline S& write_outer_helper_33(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_33(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32));
}

template <typename S>
inline S& fmt_inner_helper_34(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[34];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33
>
inline S& fmt_outer_helper_34(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_34(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33));
}

template <typename S>
inline S& write_inner_helper_34(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[34];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33
>
inline S& write_outer_helper_34(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_34(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33));
}

template <typename S>
inline S& fmt_inner_helper_35(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[35];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34
>
inline S& fmt_outer_helper_35(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_35(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34));
}

template <typename S>
inline S& write_inner_helper_35(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[35];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34
>
inline S& write_outer_helper_35(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_35(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34));
}

template <typename S>
inline S& fmt_inner_helper_36(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[36];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35
>
inline S& fmt_outer_helper_36(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_36(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35));
}

template <typename S>
inline S& write_inner_helper_36(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[36];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35
>
inline S& write_outer_helper_36(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_36(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35));
}

template <typename S>
inline S& fmt_inner_helper_37(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[37];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36
>
inline S& fmt_outer_helper_37(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_37(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36));
}

template <typename S>
inline S& write_inner_helper_37(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[37];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36
>
inline S& write_outer_helper_37(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_37(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36));
}

template <typename S>
inline S& fmt_inner_helper_38(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[38];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37
>
inline S& fmt_outer_helper_38(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_38(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37));
}

template <typename S>
inline S& write_inner_helper_38(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[38];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36 + l37;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37
>
inline S& write_outer_helper_38(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_38(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37));
}

template <typename S>
inline S& fmt_inner_helper_39(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[39];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38
>
inline S& fmt_outer_helper_39(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_39(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38));
}

template <typename S>
inline S& write_inner_helper_39(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[39];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36 + l37 + l38;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38
>
inline S& write_outer_helper_39(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_39(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38));
}

template <typename S>
inline S& fmt_inner_helper_40(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[40];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39
>
inline S& fmt_outer_helper_40(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_40(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39));
}

template <typename S>
inline S& write_inner_helper_40(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[40];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36 + l37 + l38 + l39;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39
>
inline S& write_outer_helper_40(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_40(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39));
}

template <typename S>
inline S& fmt_inner_helper_41(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[41];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40
>
inline S& fmt_outer_helper_41(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_41(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40));
}

template <typename S>
inline S& write_inner_helper_41(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[41];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36 + l37 + l38 + l39 + l40;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40
>
inline S& write_outer_helper_41(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_41(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40));
}

template <typename S>
inline S& fmt_inner_helper_42(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[42];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41
>
inline S& fmt_outer_helper_42(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_42(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41));
}

template <typename S>
inline S& write_inner_helper_42(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[42];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36 + l37 + l38 + l39 + l40 + l41;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41
>
inline S& write_outer_helper_42(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_42(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41));
}

template <typename S>
inline S& fmt_inner_helper_43(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[43];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42
>
inline S& fmt_outer_helper_43(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_43(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42));
}

template <typename S>
inline S& write_inner_helper_43(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[43];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36 + l37 + l38 + l39 + l40 + l41 + l42;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42
>
inline S& write_outer_helper_43(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_43(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42));
}

template <typename S>
inline S& fmt_inner_helper_44(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42
 , ff_char_t const* p43, size_t l43)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[44];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;
 prms[43].len = l43;
 prms[43].ptr = p43;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43
>
inline S& fmt_outer_helper_44(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_44(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg43));
}

template <typename S>
inline S& write_inner_helper_44(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42
 , ff_char_t const* p43, size_t l43)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[44];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;
 prms[43].len = l43;
 prms[43].ptr = p43;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36 + l37 + l38 + l39 + l40 + l41 + l42 + l43;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43
>
inline S& write_outer_helper_44(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_44(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg43));
}

template <typename S>
inline S& fmt_inner_helper_45(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42
 , ff_char_t const* p43, size_t l43
 , ff_char_t const* p44, size_t l44)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[45];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;
 prms[43].len = l43;
 prms[43].ptr = p43;
 prms[44].len = l44;
 prms[44].ptr = p44;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44
>
inline S& fmt_outer_helper_45(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_45(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg43)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg44));
}

template <typename S>
inline S& write_inner_helper_45(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42
 , ff_char_t const* p43, size_t l43
 , ff_char_t const* p44, size_t l44)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[45];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;
 prms[43].len = l43;
 prms[43].ptr = p43;
 prms[44].len = l44;
 prms[44].ptr = p44;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36 + l37 + l38 + l39 + l40 + l41 + l42 + l43 + l44;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44
>
inline S& write_outer_helper_45(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_45(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg43)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg44));
}

template <typename S>
inline S& fmt_inner_helper_46(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42
 , ff_char_t const* p43, size_t l43
 , ff_char_t const* p44, size_t l44
 , ff_char_t const* p45, size_t l45)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[46];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;
 prms[43].len = l43;
 prms[43].ptr = p43;
 prms[44].len = l44;
 prms[44].ptr = p44;
 prms[45].len = l45;
 prms[45].ptr = p45;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45
>
inline S& fmt_outer_helper_46(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_46(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg43)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg44)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg45));
}

template <typename S>
inline S& write_inner_helper_46(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42
 , ff_char_t const* p43, size_t l43
 , ff_char_t const* p44, size_t l44
 , ff_char_t const* p45, size_t l45)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[46];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;
 prms[43].len = l43;
 prms[43].ptr = p43;
 prms[44].len = l44;
 prms[44].ptr = p44;
 prms[45].len = l45;
 prms[45].ptr = p45;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36 + l37 + l38 + l39 + l40 + l41 + l42 + l43 + l44 + l45;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45
>
inline S& write_outer_helper_46(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_46(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg43)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg44)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg45));
}

template <typename S>
inline S& fmt_inner_helper_47(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42
 , ff_char_t const* p43, size_t l43
 , ff_char_t const* p44, size_t l44
 , ff_char_t const* p45, size_t l45
 , ff_char_t const* p46, size_t l46)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[47];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;
 prms[43].len = l43;
 prms[43].ptr = p43;
 prms[44].len = l44;
 prms[44].ptr = p44;
 prms[45].len = l45;
 prms[45].ptr = p45;
 prms[46].len = l46;
 prms[46].ptr = p46;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46
>
inline S& fmt_outer_helper_47(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_47(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg43)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg44)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg45)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg46));
}

template <typename S>
inline S& write_inner_helper_47(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42
 , ff_char_t const* p43, size_t l43
 , ff_char_t const* p44, size_t l44
 , ff_char_t const* p45, size_t l45
 , ff_char_t const* p46, size_t l46)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[47];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;
 prms[43].len = l43;
 prms[43].ptr = p43;
 prms[44].len = l44;
 prms[44].ptr = p44;
 prms[45].len = l45;
 prms[45].ptr = p45;
 prms[46].len = l46;
 prms[46].ptr = p46;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36 + l37 + l38 + l39 + l40 + l41 + l42 + l43 + l44 + l45 + l46;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46
>
inline S& write_outer_helper_47(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_47(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg43)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg44)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg45)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg46));
}

template <typename S>
inline S& fmt_inner_helper_48(S& sink, int flags
 , ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42
 , ff_char_t const* p43, size_t l43
 , ff_char_t const* p44, size_t l44
 , ff_char_t const* p45, size_t l45
 , ff_char_t const* p46, size_t l46
 , ff_char_t const* p47, size_t l47)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 defs::slices_buffer_t results(numResultElements);
 size_t actualNumResultElements;
 ff_string_slice_t prms[48];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;
 prms[43].len = l43;
 prms[43].ptr = p43;
 prms[44].len = l44;
 prms[44].ptr = p44;
 prms[45].len = l45;
 prms[45].ptr = p45;
 prms[46].len = l46;
 prms[46].ptr = p46;
 prms[47].len = l47;
 prms[47].ptr = p47;

 size_t cchTotal = fastformat_fillReplacements(&results[0], formatElements, numFormatElements, &prms[0], STLSOFT_NUM_ELEMENTS(prms), NULL, NULL, &actualNumResultElements);
 FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API((actualNumResultElements <= results.size()), "actual number of result elements exceeds capacity");
 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, actualNumResultElements, &results[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47
>
inline S& fmt_outer_helper_48(S& sink, int flags, ff_format_element_t const *formatElements, size_t numFormatElements, size_t numResultElements
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46, A47 const& arg47)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return fmt_inner_helper_48(sink, flags, formatElements, numFormatElements, numResultElements
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg43)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg44)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg45)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg46)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg47));
}

template <typename S>
inline S& write_inner_helper_48(S& sink, int flags
 , ff_char_t const* p0, size_t l0
 , ff_char_t const* p1, size_t l1
 , ff_char_t const* p2, size_t l2
 , ff_char_t const* p3, size_t l3
 , ff_char_t const* p4, size_t l4
 , ff_char_t const* p5, size_t l5
 , ff_char_t const* p6, size_t l6
 , ff_char_t const* p7, size_t l7
 , ff_char_t const* p8, size_t l8
 , ff_char_t const* p9, size_t l9
 , ff_char_t const* p10, size_t l10
 , ff_char_t const* p11, size_t l11
 , ff_char_t const* p12, size_t l12
 , ff_char_t const* p13, size_t l13
 , ff_char_t const* p14, size_t l14
 , ff_char_t const* p15, size_t l15
 , ff_char_t const* p16, size_t l16
 , ff_char_t const* p17, size_t l17
 , ff_char_t const* p18, size_t l18
 , ff_char_t const* p19, size_t l19
 , ff_char_t const* p20, size_t l20
 , ff_char_t const* p21, size_t l21
 , ff_char_t const* p22, size_t l22
 , ff_char_t const* p23, size_t l23
 , ff_char_t const* p24, size_t l24
 , ff_char_t const* p25, size_t l25
 , ff_char_t const* p26, size_t l26
 , ff_char_t const* p27, size_t l27
 , ff_char_t const* p28, size_t l28
 , ff_char_t const* p29, size_t l29
 , ff_char_t const* p30, size_t l30
 , ff_char_t const* p31, size_t l31
 , ff_char_t const* p32, size_t l32
 , ff_char_t const* p33, size_t l33
 , ff_char_t const* p34, size_t l34
 , ff_char_t const* p35, size_t l35
 , ff_char_t const* p36, size_t l36
 , ff_char_t const* p37, size_t l37
 , ff_char_t const* p38, size_t l38
 , ff_char_t const* p39, size_t l39
 , ff_char_t const* p40, size_t l40
 , ff_char_t const* p41, size_t l41
 , ff_char_t const* p42, size_t l42
 , ff_char_t const* p43, size_t l43
 , ff_char_t const* p44, size_t l44
 , ff_char_t const* p45, size_t l45
 , ff_char_t const* p46, size_t l46
 , ff_char_t const* p47, size_t l47)
{
 FASTFORMAT_DECLARE_fmt_slices_();
 ff_string_slice_t prms[48];

 prms[0].len = l0;
 prms[0].ptr = p0;
 prms[1].len = l1;
 prms[1].ptr = p1;
 prms[2].len = l2;
 prms[2].ptr = p2;
 prms[3].len = l3;
 prms[3].ptr = p3;
 prms[4].len = l4;
 prms[4].ptr = p4;
 prms[5].len = l5;
 prms[5].ptr = p5;
 prms[6].len = l6;
 prms[6].ptr = p6;
 prms[7].len = l7;
 prms[7].ptr = p7;
 prms[8].len = l8;
 prms[8].ptr = p8;
 prms[9].len = l9;
 prms[9].ptr = p9;
 prms[10].len = l10;
 prms[10].ptr = p10;
 prms[11].len = l11;
 prms[11].ptr = p11;
 prms[12].len = l12;
 prms[12].ptr = p12;
 prms[13].len = l13;
 prms[13].ptr = p13;
 prms[14].len = l14;
 prms[14].ptr = p14;
 prms[15].len = l15;
 prms[15].ptr = p15;
 prms[16].len = l16;
 prms[16].ptr = p16;
 prms[17].len = l17;
 prms[17].ptr = p17;
 prms[18].len = l18;
 prms[18].ptr = p18;
 prms[19].len = l19;
 prms[19].ptr = p19;
 prms[20].len = l20;
 prms[20].ptr = p20;
 prms[21].len = l21;
 prms[21].ptr = p21;
 prms[22].len = l22;
 prms[22].ptr = p22;
 prms[23].len = l23;
 prms[23].ptr = p23;
 prms[24].len = l24;
 prms[24].ptr = p24;
 prms[25].len = l25;
 prms[25].ptr = p25;
 prms[26].len = l26;
 prms[26].ptr = p26;
 prms[27].len = l27;
 prms[27].ptr = p27;
 prms[28].len = l28;
 prms[28].ptr = p28;
 prms[29].len = l29;
 prms[29].ptr = p29;
 prms[30].len = l30;
 prms[30].ptr = p30;
 prms[31].len = l31;
 prms[31].ptr = p31;
 prms[32].len = l32;
 prms[32].ptr = p32;
 prms[33].len = l33;
 prms[33].ptr = p33;
 prms[34].len = l34;
 prms[34].ptr = p34;
 prms[35].len = l35;
 prms[35].ptr = p35;
 prms[36].len = l36;
 prms[36].ptr = p36;
 prms[37].len = l37;
 prms[37].ptr = p37;
 prms[38].len = l38;
 prms[38].ptr = p38;
 prms[39].len = l39;
 prms[39].ptr = p39;
 prms[40].len = l40;
 prms[40].ptr = p40;
 prms[41].len = l41;
 prms[41].ptr = p41;
 prms[42].len = l42;
 prms[42].ptr = p42;
 prms[43].len = l43;
 prms[43].ptr = p43;
 prms[44].len = l44;
 prms[44].ptr = p44;
 prms[45].len = l45;
 prms[45].ptr = p45;
 prms[46].len = l46;
 prms[46].ptr = p46;
 prms[47].len = l47;
 prms[47].ptr = p47;

 size_t cchTotal = l0 + l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l10 + l11 + l12 + l13 + l14 + l15 + l16 + l17 + l18 + l19 + l20 + l21 + l22 + l23 + l24 + l25 + l26 + l27 + l28 + l29 + l30 + l31 + l32 + l33 + l34 + l35 + l36 + l37 + l38 + l39 + l40 + l41 + l42 + l43 + l44 + l45 + l46 + l47;

 return FASTFORMAT_INVOKE_fmt_slices_(sink, flags, cchTotal, STLSOFT_NUM_ELEMENTS(prms), &prms[0]);
}
template<typename S
, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename A41, typename A42, typename A43, typename A44, typename A45, typename A46, typename A47
>
inline S& write_outer_helper_48(S& sink, int flags
, A0 const& arg0, A1 const& arg1, A2 const& arg2, A3 const& arg3, A4 const& arg4, A5 const& arg5, A6 const& arg6, A7 const& arg7, A8 const& arg8, A9 const& arg9, A10 const& arg10, A11 const& arg11, A12 const& arg12, A13 const& arg13, A14 const& arg14, A15 const& arg15, A16 const& arg16, A17 const& arg17, A18 const& arg18, A19 const& arg19, A20 const& arg20, A21 const& arg21, A22 const& arg22, A23 const& arg23, A24 const& arg24, A25 const& arg25, A26 const& arg26, A27 const& arg27, A28 const& arg28, A29 const& arg29, A30 const& arg30, A31 const& arg31, A32 const& arg32, A33 const& arg33, A34 const& arg34, A35 const& arg35, A36 const& arg36, A37 const& arg37, A38 const& arg38, A39 const& arg39, A40 const& arg40, A41 const& arg41, A42 const& arg42, A43 const& arg43, A44 const& arg44, A45 const& arg45, A46 const& arg46, A47 const& arg47)
{
 FASTFORMAT_DECLARE_c_str_datalen_PAIR_();

 return write_inner_helper_48(sink, flags
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg0)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg1)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg2)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg3)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg4)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg5)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg6)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg7)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg8)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg9)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg10)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg11)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg12)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg13)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg14)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg15)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg16)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg17)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg18)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg19)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg20)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg21)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg22)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg23)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg24)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg25)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg26)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg27)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg28)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg29)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg30)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg31)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg32)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg33)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg34)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg35)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg36)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg37)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg38)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg39)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg40)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg41)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg42)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg43)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg44)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg45)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg46)
 , FASTFORMAT_INVOKE_SHIM_PAIR_(arg47));
}
