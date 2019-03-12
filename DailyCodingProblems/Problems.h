#pragma once

#define DECLARE_PROBLEM(num) \
struct Problem##num \
{ \
	static void RunTest(); \
}; 

DECLARE_PROBLEM( 1 );
DECLARE_PROBLEM( 2 );
DECLARE_PROBLEM( 3 );
DECLARE_PROBLEM( 4 );
DECLARE_PROBLEM( 5 );
DECLARE_PROBLEM( 6 );
DECLARE_PROBLEM( 7 );
