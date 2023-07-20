#ifndef TRADERALGO_H_INCLUDED
#define TRADERALGO_H_INCLUDED
#include<string>
#include"Transaction.h"
#include"Trader.h"
#include"Portefeuille.h"
#include"Bourse.h"
class TraderAlgo : public Trader
{
public :
    TraderAlgo();
    TraderAlgo(string);
    Transaction PrendreDecision(Bourse& bourse,PorteFeuille& portefeuille);
    ~TraderAlgo(){} ;
};



#endif // TRADERALGO_H_INCLUDED
