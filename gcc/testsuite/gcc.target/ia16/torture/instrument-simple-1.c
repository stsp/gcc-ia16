/* { dg-options "-finstrument-functions-simple -std=gnu11 -fno-inline --save-temps" } */
/* { dg-do run } */

/* Test that -finstrument-functions-simple work. */

void abort (void);

static int entries = 0, exits = 0;

__attribute__ ((no_instrument_function)) void
__cyg_profile_func_enter_simple (void)
{
  ++entries;
}

__attribute__ ((no_instrument_function)) void
__cyg_profile_func_exit_simple (void)
{
  ++exits;
}

static int
foo (void)
{
  return 6534;
}

static int
bar (void)
{
  return 21517;
}

int
main (void)
{
  int baz = foo () + bar ();

  if (baz != 28051)
    abort ();

  if (entries != 3)
    abort ();

  if (exits != 2)
    abort ();

  return 0;
}
