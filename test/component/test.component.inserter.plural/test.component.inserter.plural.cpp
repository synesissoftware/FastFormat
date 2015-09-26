/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.inserter.plural.cpp
 *
 * Purpose:     Implementation file for the test.component.inserter.plural project.
 *
 * Created:     15th November 2014
 * Updated:     26th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2014-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <fastformat/inserters/plural.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* FastFormat header files */
#include <fastformat/ff.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_1_0(void);
	static void test_item_1(void);
	static void test_1_2(void);
	static void test_1_3(void);
	static void test_1_4(void);
	static void test_1_5(void);
	static void test_1_6(void);
	static void test_1_7(void);
	static void test_1_8(void);
	static void test_1_9(void);
	static void test_1_10(void);
	static void test_1_11(void);
	static void test_1_12(void);
	static void test_1_13(void);
	static void test_1_14(void);
	static void test_1_15(void);
	static void test_1_16(void);
	static void test_1_17(void);
	static void test_1_18(void);
	static void test_1_19(void);

	static int setup(void* param);
	static int teardown(void* param);
	static void* setupParam = NULL;

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER_WITH_SETUP_FNS("test.component.inserter.plural", verbosity, setup, teardown, setupParam))
	{
		XTESTS_RUN_CASE(test_1_0);
		XTESTS_RUN_CASE(test_item_1);
		XTESTS_RUN_CASE(test_1_2);
		XTESTS_RUN_CASE(test_1_3);
		XTESTS_RUN_CASE(test_1_4);
		XTESTS_RUN_CASE(test_1_5);
		XTESTS_RUN_CASE(test_1_6);
		XTESTS_RUN_CASE(test_1_7);
		XTESTS_RUN_CASE(test_1_8);
		XTESTS_RUN_CASE(test_1_9);
		XTESTS_RUN_CASE(test_1_10);
		XTESTS_RUN_CASE(test_1_11);
		XTESTS_RUN_CASE(test_1_12);
		XTESTS_RUN_CASE(test_1_13);
		XTESTS_RUN_CASE(test_1_14);
		XTESTS_RUN_CASE(test_1_15);
		XTESTS_RUN_CASE(test_1_16);
		XTESTS_RUN_CASE(test_1_17);
		XTESTS_RUN_CASE(test_1_18);
		XTESTS_RUN_CASE(test_1_19);

		XTESTS_PRINT_RESULTS();

		XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
	}

	return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

static int setup(void* param)
{
	((void)param); /* TODO: Use the parameter, if you need to */

	return 0; /* Change to !0 to fail initialisation */
}

static int teardown(void* param)
{
	((void)param); /* TODO: Use the parameter, if you need to */

	return 0; /* Currently ignored by xTests */
}

static void test_1_0()
{
#if 0
	fastformat::plural instance;

	STLSOFT_SUPPRESS_UNUSED(instance);

	XTESTS_TEST_PASSED();–
#endif /* 0 */
}

static void test_item_1()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0 items", ff::plural(0, "item"));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1 item",  ff::plural(1, "item"));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("2 items", ff::plural(2, "item"));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("3 items", ff::plural(3, "item"));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("4 items", ff::plural(4, "item"));
}

static void test_1_2()
{
}

static void test_1_3()
{
}

static void test_1_4()
{
}

static void test_1_5()
{
}

static void test_1_6()
{
}

static void test_1_7()
{
}

static void test_1_8()
{
}

static void test_1_9()
{
}

static void test_1_10()
{
}

static void test_1_11()
{
}

static void test_1_12()
{
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_16()
{
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}


} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Test component implementation file include(s)
 */

#include <../src/inserters/plural.cpp>

/* ///////////////////////////// end of file //////////////////////////// */
