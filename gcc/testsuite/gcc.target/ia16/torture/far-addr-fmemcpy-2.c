/* { dg-options "-std=gnu11 --save-temps" } */
/* { dg-do assemble } */

/* FAIL: Can we copy a moderately big, constant-size structure from one far
   address to another?  See https://github.com/tkchia/gcc-ia16/issues/12 .  */

typedef struct { char f[64]; } T;

void f (T __far *p, T __far *q)
{
  *p = *q;
}
