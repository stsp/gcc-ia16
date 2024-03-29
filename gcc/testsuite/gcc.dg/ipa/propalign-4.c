/* { dg-do compile { target { stdint_types } } } */
/* { dg-options "-O2 -fdump-ipa-cp"  } */

#include <stdint.h>

int n;

static void
__attribute__ ((noinline))
test(void *a)
{
  __builtin_memset (a,0,n);
}

static __attribute__ ((aligned(16))) int_least32_t aa[10];

int
main()
{
  test (&aa[1]);
  test (&aa[3]);
  return 0;
}
/* { dg-final { scan-ipa-dump "Alignment 8, misalignment 4"  "cp"  } } */
