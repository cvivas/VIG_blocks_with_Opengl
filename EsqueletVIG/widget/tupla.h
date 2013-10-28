#ifndef _TUPLA_H_
#define _TUPLA_H_



using namespace std;


class Tupla
{
 public:
  Tupla(int idob=0, float py=0);

int idO;
  float y;	// coordenades del punt
};
bool operator< (Tupla a, Tupla b);
#endif