/* { dg-skip-if "Program too big" { "ia16-*-*" } { "*" } { "" } } */

/* Test structures passed by value, including to a function with a
   variable-length argument lists.  All struct members are float
   scalars.  */

extern void struct_by_value_5b_x (void);
extern void exit (int);
int fails;

int
main ()
{
  struct_by_value_5b_x ();
  exit (0);
}
