#include"TraderAletoire.h"
#include"Trader.h"
#include"Transaction.h"
#include"Titre.h"
#include"Bourse.h"
#include"Portefeuille.h"

using namespace std ;
TraderAleatoire::TraderAleatoire(string n ):Trader(n) {};
Transaction TraderAleatoire::PrendreDecision(Bourse& bourse,PorteFeuille& portefeuille)
{
    int sym,qt=0,decision;
    string action="" ;
    Decision choix ; //test
    string Tab[476]={"IPG","IP","IR","ISRG","IRM","INTU","IDXX","ICE","IFF","INTC","ILMN","JPM","JNPR","JWN","KEY","K","JNJ","IVZ","ITW","JBHT","JEC","JCI","HES","HD","HIG","HOLX","HOG","HCP","HAS","HAR","HBAN","HCN","HBI","HST","HSIC","HSY","IBM","HUM","HRS","HP","HON","HPQ","HRL","HRB","KIM","MAS","MAR","MAT","MCHP","MCD","MAC","LVLT","LUV","M","MAA","MA","MKC","MJN","MLM","MMM","MMC","MHK","MCO","MCK","MDLZ","MET","MDT","L","KSU","LB","LEN","LEG","KSS","KMB","KLAC","KMX","KR","KO","LNT","LNC","LOW","LUK","LRCX","LMT","LKQ","LH","LLL","LLY","LLTC","HAL","EA","DVN","EBAY","ED","ECL","DVA","DPS","DOW","DRI","DUK","DTE","EQIX","EOG","EQR","ES","EQT","ENDP","EIX","EFX","EL","EMR","EMN","DAL","D","DD","DFS","DE","CXO","CTSH","CTL","CTXS","CVX","CVS","DLR","DISCK","DLTR","DOV","DNB","DISCA","DGX","DG","DHI","DIS","DHR","ESRX","GD","FTR","GE","GILD","GGP","FTI","FOX","FMC","FOXA","FSLR","FRT","GRMN","GPS","GS","GWW","GT","GPN","GLW","GIS","GOOG","GPC","GOOGL","EXPE","EXPD","EXR","FAST","F","EXC","ETFC","ESS","ETN","EW","ETR","FL","FITB","FLIR","FLS","FLR","FISV","FDX","FCX","FE","FIS","FFIV","TROW","TMO","TRV","TSN","TSCO","TMK","TGNA","TEL","TGT","TJX","TIF","UDR","UAL","UHS","UNH","ULTA","UAA","TSS","TSO","TWX","TXT","TXN","SPLS","SPGI","SRCL","STI","SRE","SPG","SLG","SLB","SNA","SO","SNI","SYY","SYK","T","TDC","TAP","SWN","STX","STT","STZ","SWKS","SWK","UNM","WY","WU","WYN","XEC","WYNN","WMT","WFM","WFC","WHR","WMB","WM","YUM","YHOO","ZBH","AIV","ZION","XRX","XL","XEL","XLNX","XRAY","XOM","VAR","V","VFC","VLO","VIAB","UTX","UPS","UNP","URBN","USB","URI","WAT","VZ","WBA","WEC","WDC","VTR","VNO","VMC","VRSK","VRTX","VRSN","SJM","NWL","NVDA","O","OMC","OKE","NUE","NRG","NOV","NSC","NTRS","NTAP","PCG","PCAR","PCLN","PEG","PDCO","PBI","ORLY","ORCL","OXY","PBCT","PAYX","MSI","MSFT","MTB","MU","MTD","MRO","MO","MNST","MON","MRK","MOS","NFX","NFLX","NI","NOC","NKE","NEM","MYL","MUR","NBL","NEE","NDAQ","PEP","RIG","RHT","RL","ROP","ROK","RHI","RAI","R","RCL","RF","REGN","SE","SCHW","SEE","SIG","SHW","SCG","RRC","ROST","RSG","SBUX","RTN","PLD","PKI","PM","PNR","PNC","PHM","PFG","PFE","PG","PH","PGR","PWR","PVH","PX","QCOM","PXD","PSA","PPG","PNW","PPL","PRU","PRGO","CTAS","ANTM","AN","AMZN","APC","APA","AON","AMT","AME","AMAT","ALXN","AMP","AMGN","AMG","APD","AZO","AYI","AXP","BAX","BAC","BA","AWK","ATVI","ARNC","APH","AVY","AVGO","AVB","ADI","ADBE","ACN","ADS","ADP","ADM","ABT","AAL","A","SYMC","ABC","AAPL","AAP","ADSK","AKAM","AJG","AIZ","ALL","ALK","ALB","AIG","AES","AEP","AEE","AGN","AFL","AET","CMCSA","CMA","CLX","CMI","CMG","CME","CL","CHK","CHD","CF","CINF","CI","CHRW","CMS","CPB","COST","COP","CSX","CSCO","CRM","COO","COF","CNP","CNC","COL","COH","COG","BLK","BK","BIIB","BSX","BMY","BLL","BHI","BBY","BBT","BBBY","BEN","BDX","BCR","BWA","CCI","CBS","CBG","CERN","CELG","CCL","CB","C","CA","BXP","CAT","CAG","CAH"};


         decision= rand()%3;
         switch (decision){
          case 0 :
            choix = Achat ;
            break ;
          case 1 :
            choix = Vente ;
            break ;
          case 2 :
            choix=RienFaire ;
            break ;
           }
    if(choix==Achat ||choix == Vente){
    sym=rand()%477;
    action=Tab[sym];
    qt=rand()%10+1 ;
}


    Titre titre(action,qt) ;
    Transaction transaction(choix,titre);


    return transaction ;
}

