#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include<string>
#include"Titre.h"
using namespace std ;
enum Decision {Achat, Vente, RienFaire};

class Transaction
{
private:
    Decision d ;
    Titre t ;
public:
    Transaction() ;
    Transaction(Decision,Titre) ;
    Decision getDecision() const;
    Titre& getTitre()  ;
    void setDecision(Decision);
    void setQte(int);
    void setSymbole(string);
    ~Transaction(){};
};


#endif // TRANSACTION_H_INCLUDED
