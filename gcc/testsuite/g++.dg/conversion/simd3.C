/* { dg-do compile { target { stdint_types } } } */

#include <stdint.h>

typedef int32_t myint;

float __attribute__((vector_size(16))) b;
int32_t __attribute__((vector_size(16))) d;
myint __attribute__((vector_size(16))) d2;
uint32_t __attribute__((vector_size(16))) e;

void foo()
{
	b + d; /* { dg-error "invalid operands to binary" } */
	d += e; /* { dg-message "use -flax-vector-conversions to permit conversions between vectors with differing element types or numbers of subparts.*cannot convert '__vector.4. \(long \)\?unsigned int' to '__vector.4. \(long \)\?int' in assignment" } */
	d2 += d;
}
