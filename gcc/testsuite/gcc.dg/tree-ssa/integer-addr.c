/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized -fno-strict-aliasing" } */
/* Test with fixed address */
#if __SIZEOF_POINTER__ < 4
static int *foo =  (int *) 0x7800;
#else
static int *foo =  (int *) (unsigned long) 0x7800000;
#endif

int func(void) __attribute__ ((noinline));

extern int bar(void);

int func(void)
{
   if (*foo) {
      return 1;
   }
   return 0;

}

int foobar(void)
{

   if (func()) {
      *foo = 1;
   }
   return func();
}

/* { dg-final { scan-tree-dump-times "= func" 2 "optimized" } } */
