// { dg-do compile }
// Origin: Markus Breuer <markus.breuer@materna.de>

// PR c++/6944
// Fail to synthesize copy constructor of multi-dimensional
// array of class.

#include <string>

class Array
{
public:
#ifdef __ia16__
   std::string m_array[5][10][15];
#else
   std::string m_array[10][20][30];
#endif
};

Array func()
{
   Array result;
   return result; // sorry, not implemented: cannot initialize multi-dimensional array with initializer
}


int main()
{
   Array arr = func();
}

