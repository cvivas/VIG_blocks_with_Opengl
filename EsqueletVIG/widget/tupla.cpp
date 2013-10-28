#include "tupla.h"
#include <cmath>

Tupla::Tupla(int idob, float py) : idO(idob), y(py)
{}

bool operator< (Tupla a, Tupla b){


return a.y<b.y;
}