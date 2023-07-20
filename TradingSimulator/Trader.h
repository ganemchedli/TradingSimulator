#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include"Transaction.h"
#include<string>
#include"Bourse.h"
#include"Portefeuille.h"
using namespace std ;
class Trader
{
protected:
    string Id ;
public:
    Trader();
    Trader(string n):Id(n) {};
    string getId(){return Id;}
    virtual Transaction PrendreDecision(Bourse&,PorteFeuille&)=0 ;
    virtual ~Trader(){};
};


#endif // TRADER_H_INCLUDED
