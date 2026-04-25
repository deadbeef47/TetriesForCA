#pragma once

#include <iostream>

#ifdef TETRISNATIVE_EXPORTS
#define TTRS_NATIVE_API __declspec(dllexport)
#else
#define TTRS_NATIVE_API __declspec(dllimport)
#endif

TTRS_NATIVE_API void TestFunc();
