#ifndef TRADER_HUMAIN_H_INCLUDED
#define TRADER_HUMAIN_H_INCLUDED
#include<string>
#include"Transaction.h"
#include"Trader.h"
#include"Portefeuille.h"
#include"Bourse.h"
using namespace std ;

class TraderHumain: public Trader
{
public :
    TraderHumain();
    TraderHumain(string);
    Transaction PrendreDecision(Bourse& bourse,PorteFeuille& portefeuille);
    ~TraderHumain(){};
};

#endif // TRADER_HUMAIN_H_INCLUDED
