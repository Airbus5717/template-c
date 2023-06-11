// C macro dynamic-array library.
#pragma once

#include "platform.h"

// General sequence macros
#define seq_elem_type(seq) typeof(*(seq)->elements)

#define seq_start(seq) ((seq)->elements)
#define seq_end(seq) ((seq)->elements + (seq)->count)

#define seq_len(seq) ((seq)->count)

#define make_slice(T, start, count) ((slice(T)){start, count})
#define vec_slice(vec, low, high)          \
  {                                        \
    (high) - (low), vec_start(vec) + (low) \
  }

#define for_each(seq, iter) \
  for (seq_elem_type(seq) *iter = seq_start(seq); iter < seq_end(seq); iter++)

// Slice type

#define slice(T) slice_##T

#define decl_slice(T) \
  typedef struct      \
  {                   \
    usize count;      \
    T *elements;      \
  } slice(T)

// Vector type

#define _VEC_GROWTH_RATE 2
#define vec(T) vector_##T
#define decl_vec(T) \
  typedef struct    \
  {                 \
    usize count;    \
    usize capacity; \
    T elements[];   \
  } *vec(T);        \
  decl_slice(T)

// Vector implementation

#define vec_total_size(vec) \
  (sizeof(_vector_header) + (vec)->capacity * sizeof(seq_elem_type(vec)))

typedef struct
{
  usize count;
  usize capacity;
} _vector_header;

static inline _vector_header *_new_vec(_vector_header *header,
                                       usize initial_size)
{
  header->count = 0;
  header->capacity = initial_size;
  return header;
}

#define vec_new(T, size) \
  (_new_vec(mem_alloc(sizeof(_vector_header) + size * sizeof(T)), size))
#define vec_free(vec) mem_free(vec)

#define vec_resize(vec)                \
  (vec)->capacity *= _VEC_GROWTH_RATE; \
  (vec) = mem_realloc(vec, vec_total_size(vec));

#define vec_push(vec, ...)                           \
  do                                                 \
  {                                                  \
    if ((vec)->count + 1 > (vec)->capacity)          \
    {                                                \
      (vec)->capacity *= _VEC_GROWTH_RATE;           \
      (vec) = mem_realloc(vec, vec_total_size(vec)); \
    }                                                \
    (vec)->elements[(vec)->count++] = __VA_ARGS__;   \
  } while (0);

#define vec_start(vec) seq_start(vec)
#define vec_end(vec) seq_end(vec)

#define vec_len(vec) seq_len(vec)

// end of VEC.H
