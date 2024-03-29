// PR c++/48780
// { dg-do compile { target { c++11 && int32plus } } }
// { dg-options "-fabi-version=5 -Wabi" }

typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;

enum struct A : short { X };

void foo(int x, ...) {
   va_list vl;
   __builtin_va_start(vl, x);
   enum A t = __builtin_va_arg(vl, enum A); // { dg-warning "scoped|promote" }
   __builtin_va_end(vl);
}

int main() {
   foo(0, A::X);		// { dg-warning "scoped" }
}
