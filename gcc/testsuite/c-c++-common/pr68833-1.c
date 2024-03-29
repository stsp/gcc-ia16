/* PR c/68833 */
/* { dg-do compile } */
/* { dg-options "-Werror=larger-than-8192 -Werror=format -Werror=missing-noreturn" } */

int a[16384/sizeof (int)];	/* { dg-error "size of 'a' is \[1-9]\[0-9]* bytes" } */
int b[1024];	/* { dg-bogus "size of 'b' is \[1-9]\[0-9]* bytes" } */

void
f1 (const char *fmt)
{
  __builtin_printf ("%d\n", 1.2);	/* { dg-error "expects argument of type" } */
  __builtin_printf (fmt, 1.2);		/* { dg-bogus "format not a string literal, argument types not checked" } */
}

extern void f2 (void);
void
f2 (void) /* { dg-error "candidate for attribute 'noreturn'" "detect noreturn candidate" } */
{
  __builtin_exit (0);
}

/* { dg-prune-output "treated as errors" } */
