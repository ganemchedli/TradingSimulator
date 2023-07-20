#ifndef TRADER_ALGO_H_INCLUDED
#define TRADER_ALGO_H_INCLUDED
#include<string>
#include"Transaction.h"
#include"Trader.h"
#include"Portefeuille.h"
#include"Bourse.h"
using namespace std;
class TraderAleatoire : public Trader
{

public:
    TraderAleatoire();
    TraderAleatoire(string);
    Transaction PrendreDecision(Bourse& bourse ,PorteFeuille& PorteFeuille);
    ~TraderAleatoire(){};
};

#endif // TRADER_ALGO_H_INCLUDED
