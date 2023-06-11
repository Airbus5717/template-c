#pragma once

// stdlib
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define local static

#ifndef nullptr
#define nullptr NULL
#endif

typedef float f32;
typedef double f64;
typedef long double f128; // not nesserily 128bits

typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef long long isize;
typedef unsigned long long usize;

typedef const char *str;
typedef char *cstr;

#define U8_MAX 0xff
#define U8_MIN 0
#define U16_MAX 0xffff
#define U16_MIN 0
#define U32_MAX 0xffffffff
#define U32_MIN 0
#define U64_MAX 0xffffffffffffffff
#define U64_MIN 0

#define I8_MAX 0x7f
#define I8_MIN -0x80
#define I16_MAX 0x7fff
#define I16_MIN -0x8000
#define I32_MAX 0x7fffffff
#define I32_MIN -0x80000000
#define I64_MAX 0x7fffffffffffffff
#define I64_MIN -0x8000000000000000

#define FOREACH(i, r) for (usize i = 0; i < r; ++i)

#define ASSERT(expr, msg)                                                  \
  do                                                                       \
  {                                                                        \
    if (!(expr))                                                           \
    {                                                                      \
      fprintf(stderr, "%sAssert failure: %s\n@file: %s:%d%s\n", LRED, msg, \
              __FILE__, __LINE__, RESET);                                  \
      exit(1);                                                             \
    }                                                                      \
  } while (0)

#define ASSERT_CMP(expr1, expr2, msg)                                      \
  do                                                                       \
  {                                                                        \
    if ((expr1) != (expr2))                                                \
    {                                                                      \
      fprintf(stderr, "%sAssert failure: %s\n@file: %s:%d%s\n", LRED, msg, \
              __FILE__, __LINE__, RESET);                                  \
      exit(1);                                                             \
    }                                                                      \
  } while (0)

#define ASSERT_NULL(expr, msg)                                             \
  do                                                                       \
  {                                                                        \
    if ((expr) == nullptr)                                                 \
    {                                                                      \
      fprintf(stderr, "%sAssert failure: %s\n@file: %s:%d%s\n", LRED, msg, \
              __FILE__, __LINE__, RESET);                                  \
      exit(1);                                                             \
    }                                                                      \
  } while (0)

#define STR_ASSERT(string1, string2, msg)                                  \
  do                                                                       \
  {                                                                        \
    if (strcmp(string1, string2) != 0)                                     \
    {                                                                      \
      fprintf(stderr, "%sAssert failure: %s\n@file: %s:%d%s\n", LRED, msg, \
              __FILE__, __LINE__, RESET);                                  \
      exit(1);                                                             \
    }                                                                      \
  } while (0)

#define ASSERT_RET_FAIL(expr, msg) \
  do                               \
  {                                \
    if (!(expr))                   \
    {                              \
      log_error(msg);              \
      return EXIT_FAILURE;         \
    }                              \
  } while (0)

#define expect(expr, doWhenExpected, doElse) \
  do                                         \
  {                                          \
    if (!(expr))                             \
    {                                        \
      doElse;                                \
      return EXIT_FAILURE;                   \
    }                                        \
    else                                     \
    {                                        \
      doWhenExpected;                        \
    }                                        \
  } while (0)

#ifdef DEBUG

#define dbg(str, ...)                  \
  do                                   \
  {                                    \
    fprintf(stderr, str, __VA_ARGS__); \
  } while (0)

#endif

#define TODO(str)                                                          \
  do                                                                       \
  {                                                                        \
    fprintf(stderr, "%sTODO: %s\n@file: %s:%d%s\n", YELLOW, str, __FILE__, \
            __LINE__, RESET);                                              \
    exit(1);                                                               \
  } while (0)

#define UNREACHABLE()                                                      \
  do                                                                       \
  {                                                                        \
    fprintf(stderr, "%sREACHED UNREACHABLE STATE\n@file: %s:%d%s\n", LRED, \
            __FILE__, __LINE__, RESET);                                    \
    exit(1);                                                               \
  } while (0)

#define UNUSED(x) ((void)sizeof(x))

#if defined(_WIN32)
#define OS_WIN 1
#define OS_MAC 0
#define OS_LIN 0
#elif defined(__linux__)
#define OS_WIN 0
#define OS_MAC 0
#define OS_LIN 1
#elif defined(__APPLE__)
#define OS_WIN 0
#define OS_MAC 1
#define OS_LIN 0
#else
#error Missing OS detection
#endif

// terminal colors
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define FAINT "\x1b[2m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define PINK "\x1b[35m"
#define CYAN "\x1b[36m"
#define BLACK "\x1b[30m"
#define WHITE "\x1b[37m"
#define DEFAULT "\x1b[39m"
#define LGRAY "\x1b[90m"
#define LRED "\x1b[91m"
#define LGREEN "\x1b[92m"
#define LYELLOW "\x1b[93m"
#define LBLUE "\x1b[94m"
#define LMAGENTA "\x1b[95m"
#define LCYAN "\x1b[96m"
#define LWHITE "\x1b[97m"

// END OF DEF.H
