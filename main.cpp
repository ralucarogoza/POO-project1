#include <iostream>
#include <vector>
using namespace std;

class Carte{
public:
    Carte(string denumire,string nume_autor,string prenume_autor, unsigned int nr_pagini, unsigned int an, float pret, unsigned int rating);
    Carte(const Carte&);
    Carte();
    void setDenumire(string);
    void setNume_Autor(string);
    void setPrenume_Autor(string);
    void setNr_Pagini(unsigned int);
    void setAn(unsigned int);
    void setPret(float);
    void setRating(unsigned int);
    string getDenumire();
    string getNume_Autor();
    string getPrenume_Autor();
    unsigned int getNr_Pagini();
    unsigned int getAn();
    float getPret();
    unsigned int getRating();
    friend bool operator==(Carte&, Carte&);
    friend bool operator!=(Carte&, Carte&);
    friend Carte operator+=(Carte&, int );
    friend Carte operator-=(Carte&, int );
    friend Carte operator+(Carte&, int );
    friend Carte operator-(Carte&, int );
    friend istream& operator>>(istream&, Carte&);
    friend ostream& operator<<(ostream&, Carte&);
    void actualizareRating(unsigned int);
    void carteMaiBuna(Carte&);
    void carteMaiLunga(Carte&);
    int promotie(Carte&);
    void scumpire(float);
    void ieftinire(float);
    void vechime();
private:
    string denumire;
    string nume_autor;
    string prenume_autor;
    unsigned int nr_pagini;
    unsigned int an;
    float pret;
    unsigned int rating;

};
class Librarie{
public:
    Librarie(vector <Carte>, string);
    Librarie(const Librarie&);
    Librarie();
    void setDenumireLibrarie(string);
    void setCarti(vector <Carte>);
    string getDenumireLibrarie();
    vector <Carte> getCarti();
    friend istream& operator>>(istream&, Librarie&);
    friend ostream& operator<<(ostream&, Librarie&);
    void adaugaCarte(Carte&);
private:
    vector <Carte> carti;
    string denumire;
};

Carte::Carte(string denumire,string nume_autor,string prenume_autor, unsigned int nr_pagini, unsigned int an, float pret, unsigned int rating)
{
    this->denumire=denumire;
    this->nume_autor=nume_autor;
    this->prenume_autor=prenume_autor;
    this->nr_pagini=nr_pagini;
    this->an=an;
    this->pret=pret;
    this->rating=rating;
}

Carte::Carte(const Carte& c)
{
    denumire=c.denumire;
    nume_autor=c.nume_autor;
    prenume_autor=c.prenume_autor;
    nr_pagini=c.nr_pagini;
    an=c.an;
    pret=c.pret;
    rating=c.rating;
}

Carte::Carte() {}


Librarie::Librarie(vector <Carte> carti, string denumire)
{
    this->denumire=denumire;
    this->carti=carti;
}

Librarie::Librarie(const Librarie& l)
{
    denumire=l.denumire;

    for(Carte c: l.carti)
    {
        carti.push_back(c);
    }
}
Librarie::Librarie(){}

void Carte::setDenumire(string denumire)
{
    this->denumire=denumire;
}

void Carte::setNume_Autor(string nume_autor)
{
    this->nume_autor=nume_autor;
}

void Carte::setPrenume_Autor(string prenume_autor)
{
    this->prenume_autor=prenume_autor;
}

void Carte::setNr_Pagini(unsigned int nr_pagini)
{
    this->nr_pagini=nr_pagini;
}

void Carte::setAn(unsigned int an)
{
    this->an=an;
}

void Carte::setPret(float pret)
{
    this->pret=pret;
}

void Carte::setRating(unsigned int rating)
{
    this->rating=rating;
}

void Librarie::setDenumireLibrarie(string denumire)
{
    this->denumire=denumire;
}

void Librarie::setCarti(vector <Carte> carti)
{
    this->carti=carti;
}

string Carte::getDenumire()
{
    return this->denumire;
}

string Carte::getNume_Autor()
{
    return this->nume_autor;
}

string Carte::getPrenume_Autor()
{
    return this->prenume_autor;
}

unsigned int Carte::getNr_Pagini()
{
    return this->nr_pagini;
}

unsigned int Carte::getAn()
{
    return this->an;
}

float Carte::getPret()
{
    return this->pret;
}

unsigned int Carte::getRating()
{
    return this->rating;
}

string Librarie::getDenumireLibrarie()
{
    return this->denumire;
}

vector <Carte> Librarie::getCarti()
{
    return this->carti;
}


istream& operator>>(istream& is, Carte& c)
{
    is>>c.denumire>>c.nume_autor>>c.prenume_autor>>c.nr_pagini>>c.an>>c.pret>>c.rating;
    return is;
}

ostream& operator<<(ostream& os, Carte& c)
{
    os<<c.denumire<<' '<<c.nume_autor<<' '<<c.prenume_autor<<' '<<c.nr_pagini<<' '<<c.an<<' '<<c.pret<<' '<<c.rating;
    return os;
}

bool operator==(Carte& c1, Carte& c2)
{
    return c1.denumire==c2.denumire && c1.nume_autor==c2.nume_autor && c1.prenume_autor==c2.prenume_autor && c1.pret==c2.pret;
}

bool operator!=(Carte& c1, Carte& c2)
{
    return c1.nume_autor!=c2.nume_autor || c1.prenume_autor!=c2.prenume_autor;
}

Carte operator+=(Carte& c1,int scumpire)
{
    c1.pret+=scumpire;
    return c1;
}

Carte operator-=(Carte& c1,int ieftinire)
{
    c1.pret-=ieftinire;
    return c1;
}

Carte operator+(Carte& c1,int scumpire)
{
    c1.pret=c1.pret+scumpire;
    return c1;
}

Carte operator-(Carte& c1,int ieftinire)
{
    c1.pret=c1.pret-ieftinire;
    return c1;
}


istream& operator>>(istream& is, Librarie& l)
{
    is>>l.denumire;
    return is;
}

ostream& operator<<(ostream& os, Librarie& l)
{
    os<<l.getDenumireLibrarie()<<endl;
    for(Carte c: l.carti)
    {
        os<<"'"<<c.getDenumire()<<"' de "<<c.getNume_Autor()<< " "<<c.getPrenume_Autor()<<endl;
    }
    return os;
}

void Librarie::adaugaCarte(Carte& c)
{
    carti.push_back(c);
}

void Carte::actualizareRating(unsigned int rating_nou)
{
    this->rating=(this->rating+rating_nou)/2;
}

void Carte::carteMaiBuna(Carte &c2)
{
    if(this->rating==c2.rating) cout<<"Cartile '"<<this->denumire<<"' de "<<this->nume_autor<<" "<<this->prenume_autor<<" si '"<<c2.denumire<<"' de "<<c2.nume_autor<<" "<<c2.prenume_autor<< " sunt la fel de bune.";
    else if(this->rating>c2.rating) cout<<"Cartea '"<<this->denumire<<"' scrisa de "<<this->nume_autor<<" "<<this->prenume_autor<< " este mai buna decat cartea '"<<c2.denumire<<"' scrisa de "<<c2.nume_autor<<" "<<c2.prenume_autor<<".";
    else cout<<"Cartea '"<<c2.denumire<<"' scrisa de "<<c2.nume_autor<<" "<<c2.prenume_autor<<" este mai buna decat cartea '"<<this->denumire<<"' scrisa de "<<this->nume_autor<<" "<<this->prenume_autor<<".";
}

void Carte::carteMaiLunga(Carte &c2)
{
    if(this->nr_pagini==c2.nr_pagini) cout<<"Cartile '"<<this->denumire<<"' de "<<this->nume_autor<<" "<<this->prenume_autor<<" si '"<<c2.denumire<<"' de "<<c2.nume_autor<<" "<<c2.prenume_autor<< " sunt la fel de lungi.";
    else if(this->nr_pagini>c2.nr_pagini) cout<<"Cartea '"<<this->denumire<<"' scrisa de "<<this->nume_autor<<" "<<this->prenume_autor<< " este mai lunga decat cartea '"<<c2.denumire<<"' scrisa de "<<c2.nume_autor<<" "<<c2.prenume_autor<<".";
    else cout<<"Cartea '"<<c2.denumire<<"' scrisa de "<<c2.nume_autor<<" "<<c2.prenume_autor<<" este mai lunga decat cartea '"<<this->denumire<<"' scrisa de "<<this->nume_autor<<" "<<this->prenume_autor<<".";
}

void Carte::scumpire(float p)
{
    this->pret=this->pret+(float)this->pret*p/100;
}

void Carte::ieftinire(float p)
{
    this->pret=this->pret-(float)this->pret*p/100;
}

void Carte::vechime()
{
    cout<<"Cartea '"<<this->denumire<<"' scrisa de "<<this->nume_autor<<" "<<this->prenume_autor<<" are o vechime de "<<2022-this->an<<" ani."<<endl;
}

int Carte::promotie(Carte& c2)
{
    if(this->nume_autor==c2.nume_autor && this->prenume_autor==c2.prenume_autor)
        if(this->pret>c2.pret) return this->pret;
        else return c2.pret;
    else return 0;
}


int main()
{
    //flux 1
    Carte c1=Carte("Un baiat numit Craciun","Haig","Matt",200,2019,34,4),c2=Carte("Biblioteca de la miezul noptii","Haig","Matt",234,2006,43,4),c3=Carte("Hotul","Zusak","Markus",600,2010,23,3);
    Librarie l=Librarie();
    l.setDenumireLibrarie("Carturesti");
    l.adaugaCarte(c1);
    l.adaugaCarte(c2);
    l.adaugaCarte(c3);
    cout<<l;

    if(c1==c2) cout<<"Carti identice"<<endl;
    else cout<<"Carti diferite"<<endl;
    if(c1!=c2) cout<<"Autori diferiti"<<endl;
    else cout<<"Acelasi autor"<<endl;

    int p=2;
    c1+=p;
    cout<<"Pretul cartii '"<<c1.getDenumire()<<"' dupa scumpirea cu "<<p<<" lei este: "<<c1.getPret()<<" lei."<<endl;
    c1-=p;
    cout<<"Pretul cartii '"<<c1.getDenumire()<<"' dupa ieftinirea cu "<<p<<" lei este: "<<c1.getPret()<<" lei."<<endl;

    int scumpire=5, ieftinire=3;
    c3+scumpire;
    cout<<"Pretul cartii '"<<c3.getDenumire()<<"' dupa scumpirea cu "<<scumpire<<" lei este: "<<c3.getPret()<<" lei."<<endl;
    c3-ieftinire;
    cout<<"Pretul cartii '"<<c3.getDenumire()<<"' dupa ieftinirea cu "<<ieftinire<<" lei este: "<<c3.getPret()<<" lei."<<endl;

    int rating=3;
    cout<<"Rating-ul initial al cartii '"<<c1.getDenumire()<<"' este "<<c1.getRating()<<". Rating-ul nou este "<<rating<<". Rating-ul final este ";
    c1.actualizareRating(rating);
    cout<<c1.getRating()<<"."<<endl;

    c2.carteMaiBuna(c3);
    cout<<endl;

    c1.carteMaiLunga(c2);
    cout<<endl;

    int scumpire2=10,ieftinire2=40;
    cout<<"Pretul cartii '"<<c2.getDenumire()<<"' inainte de scumpirea de "<<scumpire2<<"% este "<<c2.getPret()<<" lei.";
    c2.scumpire(scumpire2);
    cout<<" Pretul dupa scumpire este "<<c2.getPret()<<" lei."<<endl;

    cout<<"Pretul cartii '"<<c2.getDenumire()<<"' inainte de ieftinirea de "<<ieftinire2<<"% este "<<c2.getPret()<<" lei.";
    c2.ieftinire(ieftinire2);
    cout<<" Pretul dupa ieftinire este "<<c2.getPret()<<" lei."<<endl;

    c1.vechime();

    int x=c1.promotie(c2);
    if(x==0) cout<<"Nu se aplica promotia.";
    else cout<<"Promotie! Cumperi 2 carti de acelasi autor la pret de una! Ai de platit doar "<<x<<" lei!";
    cout<<endl<<endl<<endl<<endl;





    //flux 2
    Carte c4=Carte("Ion","Rebreanu","Liviu",300,1881,15,2), c5=Carte("Enigma Otiliei","Calinescu","George",234,1934,23,4), c6=Carte("Rascoala","Rebreanu","Liviu",510,1931,23,3), c7=Carte("Baltagul","Sadoveanu","Mihail",192,1921,24,4);
    Carte c8(c4);
    c8.setPret(19);
    Librarie l2=Librarie();
    l2.setDenumireLibrarie("Humanitas");
    l2.adaugaCarte(c4);
    l2.adaugaCarte(c5);
    l2.adaugaCarte(c6);
    l2.adaugaCarte(c7);
    cout<<l2;

    if(c4==c8) cout<<"Carti identice"<<endl;
    else cout<<"Carti diferite"<<endl;
    if(c4!=c5) cout<<"Autori diferiti"<<endl;
    else cout<<"Acelasi autor"<<endl;

    int p2=2;
    cout<<"Pretul cartii '"<<c5.getDenumire()<<"' inainte de scumpirea cu "<<p2<<" lei este de "<<c5.getPret()<<" lei, iar dupa scumpire este de ";
    c5+=p2;
    cout<<c5.getPret()<<" lei."<<endl;
    cout<<"Pretul cartii '"<<c6.getDenumire()<<"' inainte de ieftinirea cu "<<p2<<" lei este de "<<c6.getPret()<<" lei, iar dupa ieftinire este de ";
    c6-=p2;
    cout<<c6.getPret()<<" lei."<<endl;

    int scumpire3=5, ieftinire3=3;
    c7+scumpire3;
    cout<<"Pretul cartii '"<<c7.getDenumire()<<"' dupa scumpirea cu "<<scumpire3<<" lei este: "<<c7.getPret()<<" lei."<<endl;
    c8-ieftinire3;
    cout<<"Pretul cartii '"<<c8.getDenumire()<<"' dupa ieftinirea cu "<<ieftinire3<<" lei este: "<<c8.getPret()<<" lei."<<endl;

    int rating2=5;
    cout<<"Rating-ul initial al cartii '"<<c4.getDenumire()<<"' este "<<c4.getRating()<<". Rating-ul nou este "<<rating2<<". Rating-ul final este ";
    c4.actualizareRating(rating2);
    cout<<c4.getRating()<<"."<<endl;

    c5.carteMaiBuna(c7);
    cout<<endl;

    c4.carteMaiLunga(c6);
    cout<<endl;

    int scumpire4=10,ieftinire4=40;
    cout<<"Pretul cartii '"<<c7.getDenumire()<<"' inainte de scumpirea de "<<scumpire4<<"% este "<<c7.getPret()<<" lei.";
    c7.scumpire(scumpire4);
    cout<<" Pretul dupa scumpire este "<<c7.getPret()<<" lei."<<endl;

    cout<<"Pretul cartii '"<<c5.getDenumire()<<"' inainte de ieftinirea de "<<ieftinire4<<"% este "<<c5.getPret()<<" lei.";
    c5.ieftinire(ieftinire4);
    cout<<" Pretul dupa ieftinire este "<<c5.getPret()<<" lei."<<endl;

    c7.vechime();
    int y=c5.promotie(c7);
    if(y==0) cout<<"Nu se aplica promotia.";
    else cout<<"Promotie! Cumperi 2 carti de acelasi autor la pret de una! Ai de platit doar "<<x<<" lei!";
    return 0;
}
