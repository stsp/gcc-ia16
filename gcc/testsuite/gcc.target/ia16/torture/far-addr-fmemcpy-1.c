/* { dg-do assemble } */

/* FAIL: Compiling a memcpy (...) routine that works over far pointers may
   cause a compiler crash at some optimization levels.  Reported by Bart
   Oldeman --- https://github.com/tkchia/gcc-ia16/issues/16 .  */

void
_fmemcpy (void __far *s1, const void __far *s2, unsigned length)
{
  char __far *p;
  const char __far *q;

  if (length)
    {
      p = s1;
      q = s2;
      do
	*p++ = *q++;
      while (--length);
    }
}
