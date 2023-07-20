#include<string>
#include"Transaction.h"
#include"Titre.h"
using namespace std ;
Transaction :: Transaction (Decision D, Titre T ):d(D),t(T) {};

void Transaction::setDecision(Decision a)
{
    d=a ;
}
void Transaction :: setQte(int q )
{
    this->t.setQuantite(q);
}
void Transaction::setSymbole(string sym)
{
    this->t.setSymbole(sym) ;
}
Decision Transaction :: getDecision()const
{
    return d ;
}
Titre& Transaction :: getTitre()
{
    return this->t ;
}
