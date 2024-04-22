#include <iostream>
#include <cstdlib>
#include <ctime>

const int N=5;

using namespace std;
void losuj(bool A[][N]) // void dlatego ze nie zwraca zadnych danych a bool dlatego ze ma byc prawda albo falsz
{
    int i,j,idol; //deklaracja zmiennych
    for(i=0;i<N;i++) //petla dla i ktore bedzie mialo maksymalna wartosc mniejsza niz 5 {0,1,2,3,4}

        for(j=0;j<N;j++) A[i][j]=rand()%2; //petla dla j ktore bedzie mialo maksymalna wartosc mniejsza niz 5 {0,1,2,3,4}
        //a obok losuje sie liczby z reszta z dzielenia przez 2 czyli wyjdzie z tego 1 lub 0 dzieki tym trzem dzialaniom tworzy sie tablica dwuwymiarowa

    if (rand()%2==1) //jezeli wylosowana liczba bedzie 1 to

    {
        idol=rand()%N; // w zmiennej idol losuje liczbe z reszta z dzielenia przez N czyli 5 czyli 0,1,2,3,4
        for (i=0;i<N;i++) A[i][idol]=true; // petla dla i od 0 do mniej niz 5 i to tworzy idola lecz nie zawsze pozycja PRZYKLAD [0][0] to pierwszwa w tabeli dwuwymiarowej jako ze jest to losowane pierwszwa wspolrzedna bedzie sie zmieniac przy kazdym powtorzeniu o 1 a druga bedzie losowa {0,1,2,3,4} i tam wstawia jedynki
        for (j=0;j<N;j++) A[idol][j]=false; // petla dla j od 0 do mniej niz 5 i tutaj tak samo lecz zmienia sie pierwsza wspolrzedna a druga zostaje bez zmian i tam wstawia same zera

    }
}
void wypisz(bool A[][N]) // void dlatego ze nie zwraca zadnych danych a bool dlatego ze ma byc prawda albo falsz
{
    for(int i=0;i<N;i++) //petla dla i ktore bedzie mialo maksymalna wartosc mniejsza niz 5 {0,1,2,3,4} i zauwaz ze przy pierwszym powtorzeniu nastepna petla zostanie wykonana 5 razy {0,1,2,3,4} czyli razem to wszystko bedzie mialo 25 powtorzen
    {
        for(int j=0;j<N;j++) //petla dla j ktore bedzie mialo maksymalna wartosc mniejsza niz 5 {0,1,2,3,4}
            if (i!=j) cout<<A[i][j]<<" "; // jezeli pozycja i zalozmy ze jest to zero bedzie inna(!) niz pozycja j zalozmy ze to jest 2 wypisze nam na tych wspolrzednych JEDNA SPACJE bo liczby w tabeli dwuwyemiarowej maja byc od siebie odsuniete
        else cout<<"  "; // natomiast jezeli obie pozycje beda takie same to wypisze nam DWIE SPACJE i z tego powstanie ta przekatna w tablicy dwuwymiarowej
        cout<<endl; // po jednym przejsciu calej petli przechodzimy do nasteonej linii i znowu robimy to samo
    }
}
int szidol(bool A[][N]) // int bo funkcja nam cos zapisuje (tak ma poprostu byc) a bool dlatego ze ma byc prawda albo falsz
{
    int i, k=0; // deklaracja zmiennych zwyklej zmiennej i oraz k odpowiadajacej kandydatowi rownej zero
    bool jest_k=false; //deklaracja boolem czyli prawda albo falszem zmiennej jest_k odpowiadajacej JEST_KANDYDAT i to nam zalatwia odrazu ze to jest falszem czyli zerem (nie wiem jak to wytlumaczyc)
    while (k<N && !jest_k) // dopoki nasz kandydat jest mniejszy od 5 a ZARAZEM(&&) NIE JEST(!) zerem bo tak to zrobilismy w poprzedniej linijce to robimy:
    {
        i=0; // pod i podstawiamy 0
        A[k][k]=false; // pod wspolrzedne (k,k) czyli (0,0) w tablicy dwuwymiarowej podstawiamy falsza czyli zero i tak robimy dopoki>>
        while(i<N && !A[k][i]) i++; // dopoki i bedzie mniejsze od N czyli 5 a zarazem bedzie inne niz wspolrzedne (k,i) czyli (0,0) to zwiekszamy i 0 jeden
        if (i==N) jest_k=true; // i jezeli i bedzie takie samo jak N czyli i dojdzie do 5 to zmienna jest_k oznaczamy jako prawde czyli jeden
        else k++; // a jak nie to powtarzamy wszystko od poczatku tylko ze juz z k rownego 1 bo k++
        // dzieki tym dzialaniom szukamy kandydata na idola czyli wiersza zlozonego z samych wartosci falsz badz 0
    }
   if (!jest_k) return -1; // no i jezeli nie bedzie samych falszow w wierszu to wszystko sie konczy i program trzeba jeszcze raz odpalic no chyba ze sa to dzialamy dalej
   i=0; A[k][k]=true; // pod i podstawiamy zero i sprawdzamy teraz czy w kolumach beda same wartosci prawda czyli jeden
   while(i<N && A[i][k]) i++; // dopoki i jest mniejsze od N czyli 5 a ZARAZEM(&&) bedzie taka jak wartosc o wspolrzednych (i,k) czyli (0,1) to dodajemy jeden do zmiennej i czyli sprawdzamy czy w kolejnych pozycjach kolumny tez bedzie prawda
   if (i==N) return k; //jezeli i bedzie takie samo jak N czyli 5 to zwraca k {jak cos to nie wiem czym jest k :)))))))))))))))))}
   else return -1; // a jezeli nie to i idola nie ma
}
int main()
{
    int idol; // intujemy idola nizej zobaczysz po co
    bool A[N][N]; // no powiedzmy ze to jest takie "must be" no bez tego nie pojdzie mozesz zauwazyc ze to jest tablica dwuwymiarowa 5x5 bo N jest rowne 5
    srand(time(NULL)); // zerujesz czas do losowania aby wszystko bylo git
    losuj(A); // losujesz to co ma byc w tablicy A przez dwie linijki wczesniej wiemy ze to bedzie tablica dwuwymiarowa
    wypisz(A); // wypisujemy cala tablice
    idol=szidol(A); // zmienna idol ktora zadeklarowalismy wczesniej posluzy nam po to aby sie nie wysilac i nie kombinowac gdzie tablice wpisac i tak dalej dzieki temu jest poprostu lepiej i prosciej

    if (idol== -1) // jezeli idol czyli w funckji posuzkujacej lidola pojawila sie liczba -1 co oznaczaloby ze idola nie ma to:
        cout <<"w tablicy nie ma idola"; // wyrzucamy na ekran ze w tablicy idola niestety nie ma (︺︹︶)..........
    else // w przeciwnym wypadku
    cout<<"idol jest " <<idol; // wyrzucamy idola na ekran (w ogole fachowo to sie nazywa konsola) idol oznacza liczbe jaka nia jest

}
