#include <iostream>
#include "CodonsTable.h"
#include "RNA.h"
#include "Protein.h"
#include "DNA.h"
using namespace std;
ostream& operator<< (ostream& out ,const DNA& d)  // cout << operator overloading for DNA
{

    out << d.seq  << endl;
    out << d.complementary_strand->seq << endl;
    if(d.type == promoter)
        out << "the type is promoter"<<endl;
    if(d.type == motif)
        out << "the type is motif"<<endl;
    if(d.type == tail)
        out << "the type is tail"<<endl;
    if(d.type == noncoding)
        out << "the type is noncoding"<<endl;
    return out;
}
/////////////////////////////////////////////////////////////////////////////////
ostream& operator<< (ostream& out ,const Protein& d)// cout << operator overloading for protein
{
    out << d.seq  << endl;
    if(d.type == Hormon)
        out << "the type is Hormon"<<endl;
    if(d.type == Enzyme)
        out << "the type is Enzyme"<<endl;
    if(d.type == TF)
        out << "the type is TF"<<endl;
    if(d.type == Cellular_Function)
        out << "the type is Cellular_Function"<<endl;
    return out;
}
/////////////////////////////////////////////////////////////////////////////////
ostream& operator<< (ostream& out ,const RNA& d)// cout << operator overloading for RNA
{
    out << d.seq  << endl;
    if(d.type == mRNA)
        out << "the type is mRNA"<<endl;
    if(d.type == pre_mRNA)
        out << "the type is pre_mRNA"<<endl;
    if(d.type == mRNA_exon1)
        out << "the type is mRNA_exon1"<<endl;
    if(d.type == mRNA_exon2)
        out << "the type is mRNA_exon2"<<endl;
    return out;
}
/////////////////////////////////////////////////////////////////////////////////
istream& operator>> (istream& in , RNA& d)// cin >> operator overloading for RNA
{
    cout << "Enter seq:";
    in >> d.seq;
    cout << "Enter type:";
    int x;
    cin >> x;
    if(x == 0)
        d.type = mRNA;
    if(x == 1)
        d.type = pre_mRNA;
    if(x == 2)
        d.type = mRNA_exon1;
    if(x == 3)
        d.type = mRNA_exon2;
    return in;
}
/////////////////////////////////////////////////////////////////////////////////
istream& operator>> (istream& in , DNA& d) // cin >> operator overloading for DNA
{
    cout << "Enter seq:";
    in >> d.seq;
    cout << "Enter type:";
    int x;
    cin >> x;
    if(x == 0)
        d.type = promoter;
    if(x == 1)
        d.type = motif;
    if(x == 2)
        d.type = tail;
    if(x == 3)
        d.type = noncoding;
    return in;
}
/////////////////////////////////////////////////////////////////////////////////
istream& operator>> (istream& in , Protein& d)// cin >> operator overloading for protein
{
    cout << "Enter seq:";
    in >> d.seq;
    cout << "Enter type:";
    int x;
    cin >> x;
    if(x == 0)
        d.type = Hormon;
    if(x == 1)
        d.type = Enzyme;
    if(x == 2)
        d.type = TF;
    if(x == 3)
        d.type = Cellular_Function;
    return in;
}
/////////////////////////////////////////////////////////////////////////////////
int main()
{
//    DNA d1;                                                              // for alignment
//    d1.seq = "TAGTCACG";
//    DNA d3;
//    d3.seq = "AGACTGTC";
//
//    sequance * p = &d1;
//    sequance * pp = &d3;
//    cout << p->Align(pp);

    cout << "1- DNA"<<endl;
    cout << "2- RNA"<<endl;
    cout << "3- Protein"<<endl;
    int x;
    cin >> x;
    if(x == 1)
    {
        DNA d;
        cin >> d;
        cout << d.ConvertToRNA();


    }
    else if(x == 2)
    {
        CodonsTable table("table.txt");
        RNA R;
        cin >> R;
        cout<< "the converting to DNA: "<< R.ConvertToDNA()<<endl;
        cout<< "the converting to Protein: "<< R.ConvertToProtein(table)<<endl;
    }
    else if(x == 3)
    {
        Protein p;
        cin >> p;
        cout<< p;
    }
    else{cout << "Error!" << endl;}
    main();
    return 0;
}


