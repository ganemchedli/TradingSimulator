#include<string>
#include"portefeuille.h"
#include"Trader.h"
#include"Bourse.h"
#include"TraderAlgo.h"

using namespace std ;

TraderAlgo::TraderAlgo(string id ):Trader(id){};


Transaction TraderAlgo :: PrendreDecision(Bourse& bourse,PorteFeuille& portefeuille)
{
    Date date (4,1,2010);
    int i=0,j=0, pos=0;
    Decision choix;
    string SymboleTitre="" ;
    int q =1 ;
    int rep = 0 ;

    string Tab[476]= {"IPG","IP","IR","ISRG","IRM","INTU","IDXX","ICE","IFF","INTC","ILMN","JPM","JNPR","JWN","KEY","K","JNJ","IVZ","ITW","JBHT","JEC","JCI","HES","HD","HIG","HOLX","HOG","HCP","HAS","HAR","HBAN","HCN","HBI","HST","HSIC","HSY","IBM","HUM","HRS","HP","HON","HPQ","HRL","HRB","KIM","MAS","MAR","MAT","MCHP","MCD","MAC","LVLT","LUV","M","MAA","MA","MKC","MJN","MLM","MMM","MMC","MHK","MCO","MCK","MDLZ","MET","MDT","L","KSU","LB","LEN","LEG","KSS","KMB","KLAC","KMX","KR","KO","LNT","LNC","LOW","LUK","LRCX","LMT","LKQ","LH","LLL","LLY","LLTC","HAL","EA","DVN","EBAY","ED","ECL","DVA","DPS","DOW","DRI","DUK","DTE","EQIX","EOG","EQR","ES","EQT","ENDP","EIX","EFX","EL","EMR","EMN","DAL","D","DD","DFS","DE","CXO","CTSH","CTL","CTXS","CVX","CVS","DLR","DISCK","DLTR","DOV","DNB","DISCA","DGX","DG","DHI","DIS","DHR","ESRX","GD","FTR","GE","GILD","GGP","FTI","FOX","FMC","FOXA","FSLR","FRT","GRMN","GPS","GS","GWW","GT","GPN","GLW","GIS","GOOG","GPC","GOOGL","EXPE","EXPD","EXR","FAST","F","EXC","ETFC","ESS","ETN","EW","ETR","FL","FITB","FLIR","FLS","FLR","FISV","FDX","FCX","FE","FIS","FFIV","TROW","TMO","TRV","TSN","TSCO","TMK","TGNA","TEL","TGT","TJX","TIF","UDR","UAL","UHS","UNH","ULTA","UAA","TSS","TSO","TWX","TXT","TXN","SPLS","SPGI","SRCL","STI","SRE","SPG","SLG","SLB","SNA","SO","SNI","SYY","SYK","T","TDC","TAP","SWN","STX","STT","STZ","SWKS","SWK","UNM","WY","WU","WYN","XEC","WYNN","WMT","WFM","WFC","WHR","WMB","WM","YUM","YHOO","ZBH","AIV","ZION","XRX","XL","XEL","XLNX","XRAY","XOM","VAR","V","VFC","VLO","VIAB","UTX","UPS","UNP","URBN","USB","URI","WAT","VZ","WBA","WEC","WDC","VTR","VNO","VMC","VRSK","VRTX","VRSN","SJM","NWL","NVDA","O","OMC","OKE","NUE","NRG","NOV","NSC","NTRS","NTAP","PCG","PCAR","PCLN","PEG","PDCO","PBI","ORLY","ORCL","OXY","PBCT","PAYX","MSI","MSFT","MTB","MU","MTD","MRO","MO","MNST","MON","MRK","MOS","NFX","NFLX","NI","NOC","NKE","NEM","MYL","MUR","NBL","NEE","NDAQ","PEP","RIG","RHT","RL","ROP","ROK","RHI","RAI","R","RCL","RF","REGN","SE","SCHW","SEE","SIG","SHW","SCG","RRC","ROST","RSG","SBUX","RTN","PLD","PKI","PM","PNR","PNC","PHM","PFG","PFE","PG","PH","PGR","PWR","PVH","PX","QCOM","PXD","PSA","PPG","PNW","PPL","PRU","PRGO","CTAS","ANTM","AN","AMZN","APC","APA","AON","AMT","AME","AMAT","ALXN","AMP","AMGN","AMG","APD","AZO","AYI","AXP","BAX","BAC","BA","AWK","ATVI","ARNC","APH","AVY","AVGO","AVB","ADI","ADBE","ACN","ADS","ADP","ADM","ABT","AAL","A","SYMC","ABC","AAPL","AAP","ADSK","AKAM","AJG","AIZ","ALL","ALK","ALB","AIG","AES","AEP","AEE","AGN","AFL","AET","CMCSA","CMA","CLX","CMI","CMG","CME","CL","CHK","CHD","CF","CINF","CI","CHRW","CMS","CPB","COST","COP","CSX","CSCO","CRM","COO","COF","CNP","CNC","COL","COH","COG","BLK","BK","BIIB","BSX","BMY","BLL","BHI","BBY","BBT","BBBY","BEN","BDX","BCR","BWA","CCI","CBS","CBG","CERN","CELG","CCL","CB","C","CA","BXP","CAT","CAG","CAH"};

    do {
        pos = rand()%477 ;
        SymboleTitre = Tab[pos] ;

    } while(bourse.rechercherPrixActionAujourdhui(SymboleTitre)==NULL  ) ;
    cout << "choix de symbole\t "<< SymboleTitre << endl ;
    double PrixAujourdhui = bourse.rechercherPrixActionAujourdhui(SymboleTitre)->getPrix();
     cout << "prix de cette action\t"<<PrixAujourdhui << endl ;
    while(bourse.getDateAujourdhui() != date) {
        if (SymboleTitre == bourse.rechercherPrixActionDate(SymboleTitre,date )->getSymboleAction()) {
            if(PrixAujourdhui > bourse.rechercherPrixActionDate(SymboleTitre, date)->getPrix()) {
                i++ ;   // calculer la tendance d'augmentation de cet action dans les derniers jours
            }
            if(PrixAujourdhui < bourse.rechercherPrixActionDate(SymboleTitre, date)->getPrix()) {
                j++ ;   // claculer la tendance de diminution de cet action dans les derniers jours
            }
        }
        date=date+1 ;
    }
    cout <<"nombre de tendance d'augmentation\t" <<i<<endl;

    cout <<"nombre de tendance de dimunition\t"<< j <<endl ;

    if (i<j) { //Achat ou RienFaire
        do {
            q=rand()%10+1;
        } while(portefeuille.getSolde()<PrixAujourdhui*q) ;
            choix = Achat;
    }

    else if (i>j) { // Vente ou RienFaire
        if(portefeuille.rechercherTitre(SymboleTitre)!= NULL) { // cad le titre existe dans le portefeuille
            do {
                q=rand()%10+1 ;

                rep ++ ;
            } while(q>portefeuille.rechercherTitre(SymboleTitre)->getQuantite() || rep<10);
            choix =Vente;

    }
    }
    else {
        choix = RienFaire;
    }

    if(portefeuille.getNombreTitre()!=0){
       SymboleTitre= portefeuille.getTitre(0).getSymbole() ;
       do{
       q=rand()%10+1;
       }while(q<portefeuille.rechercherTitre(SymboleTitre)->getQuantite());
       choix=Vente ;
    }




    Titre titre(SymboleTitre,q) ;
    Transaction transaction(choix,titre) ;

    return transaction;
}
