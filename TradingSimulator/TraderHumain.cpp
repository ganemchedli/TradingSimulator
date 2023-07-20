#include<iostream>
#include"TraderHumain.h"
#include"Portefeuille.h"
#include"Trader.h"
#include"Transaction.h"
#include<cctype>

using namespace std ;

TraderHumain::TraderHumain(string a):Trader(a) {};


Transaction TraderHumain::PrendreDecision(Bourse& bourse,PorteFeuille& portefeuille)
{
    Decision choix ;
    string Sym="" ;
    int Qte=0, i=0 ;
    int quit = 0 ;

    do {
        int c = 0 ;
        cout <<"Voir toutes les prix des actions d'aujourd'hui .1"<<endl;
        cout<<"Voir le prix d'une action depuis une date donnee.2" << endl ;
        cout<<"Passer pour prendre une decision .3"<<endl ;
        cin>>c;
        switch(c) {
        case 1 : {
            bourse.AffichePrixJournaliers(bourse.getDateAujourdhui());
            break;
        }
        case 2 : {
            int j, m, a ;
            string sym ;
            cout<<"Donnee le symbole de l'action"<<endl ;
            do {
                cin >> sym ;
                if(bourse.rechercherPrixActionAujourdhui(sym) == NULL) {
                    cout<<"introuvable!"<<endl;
                }
            } while(bourse.rechercherPrixActionAujourdhui(sym)==NULL);

            cout<<"Donnee une date :"<<endl;
            do {
                cout<<"Date 1 :\t";
                cin>>j>>m>>a ;
            } while(j>=bourse.getDateAujourdhui().getJour()&&m>=bourse.getDateAujourdhui().getMois()&&a>=bourse.getDateAujourdhui().getAnnee());
            Date date(j,m,a);
            while(bourse.getDateAujourdhui()!=date) {
                if(bourse.rechercherPrixActionDate(sym,date)!=NULL) {
                    cout<<*(bourse.rechercherPrixActionDate(sym,date))<<endl;
                } else {
                    cout << "introuvable" << endl ;
                }
                date=date+1 ;
            }
            break;

            }
              case 3 :{
                break ;
              }

        }
        cout << "Rester.1 // Quitter .2"<<endl ;
        cin >> quit ;

    } while(quit==1);



    cout << "Choix de l'operation : 1.Achat , 2.Vente , 3.Rienfaire"<<endl ;

    cin >> i ;
    switch (i) {
    case 1 :
        choix = Achat ;
        break ;
    case 2 :
        choix = Vente ;
        break ;
    case 3 :
        choix=RienFaire ;
        break ;
    };
    if(choix!=RienFaire) {
        if(choix == Achat) {
            cout<< "Votre Solde disponible:\t"<<portefeuille.getSolde()<<endl ;
        } else {
            cout << endl << endl << endl << "les titres existants:"<<endl<<endl;
            cout<<portefeuille;
        };
        int i=0 ;
        do {

            cout<<"saisi Symbole de l'action" << endl ;
            cin >> Sym ;
            i++ ;
        } while(bourse.rechercherPrixActionAujourdhui(Sym)==NULL && i<=3 );
        if(bourse.rechercherPrixActionAujourdhui(Sym)==NULL) {
            cout << "INTROUVABLE ! Prend une autre decision" << endl ;
        }
        do {
            cout<<"Saisi quantité " << endl ;
            cin >> Qte ;
        } while(isdigit(Qte));

    }
    Titre titre(Sym,Qte) ;

    Transaction transaction(choix,titre) ;


    return transaction ;
}
