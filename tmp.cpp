#include "tmp.h"

tmp::tmp()
{

}

tmp::tmp(int a)
{
    this->x = a;
}

tmp::tmp(int x, int y)
{
    this->x = x;
    this->y = y;
}

tmp::tmp(int a, int b, int c, int d){
   this->a = a;
   this->b = b;
   this->c = c;
   this->d = d;
}
