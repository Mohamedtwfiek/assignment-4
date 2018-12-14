#include "DNA.h"
#include <iostream>
#include <string.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////
DNA DNA::operator+ (DNA rhs)                                                 // operator overloading +
{
    if(type == rhs.type)
    {
        string s = seq+rhs.seq;
        DNA d;
        d.seq = s;
        return d;
    }
    else{cout <<"the type is not the same"<<endl;}
}
////////////////////////////////////////////////////////////////////////////////////
bool DNA::operator== (DNA rhs)                                              // operator overloading ==
{
    if(seq == rhs.seq && type == rhs.type)
        return 1;
    else
        return 0;
}
////////////////////////////////////////////////////////////////////////////////////
bool DNA::operator!= (DNA rhs)                                              // operator overloading !=
{
    if(seq != rhs.seq || type != rhs.type)
        return 1;
    else
        return 0;
}
////////////////////////////////////////////////////////////////////////////////////
DNA::DNA()
{
    cout << "enter the start inx"<<endl;
        cin >> startIndex;
    cout << "enter the ind inx"<<endl;
        cin >> endIndex;
}
////////////////////////////////////////////////////////////////////////////////////
DNA::DNA(string sequ , DNA_Type atype = promoter)                            // constructor with parametars
{
    seq=sequ;
    type = atype;
     cout << "enter the start inx"<<endl;
        cin >> startIndex;
    cout << "enter the ind inx"<<endl;
        cin >> endIndex;
BuildComplementaryStrand();
}
////////////////////////////////////////////////////////////////////////////////////
DNA::DNA(DNA& rhs)                                                          // copy constructor
{
    seq = rhs.seq;
    type = rhs.type;
     cout << "enter the start inx"<<endl;
        cin >> startIndex;
    cout << "enter the ind inx"<<endl;
        cin >> endIndex;
BuildComplementaryStrand();
}
////////////////////////////////////////////////////////////////////////////////////
void DNA::print()                                                          // print function
{
    BuildComplementaryStrand();
    cout << seq << endl;
    cout <<  complementary_strand->seq << endl;
    cout << startIndex << endl;
    cout << endIndex << endl;
    cout << type << endl;
}
////////////////////////////////////////////////////////////////////////////////////
void DNA::BuildComplementaryStrand()                                       // bulding the uther strind
{
    string temp = seq;
    for(int i = startIndex ; i < endIndex; i++ )
    {
        if(seq[i] == 'A')
            temp[i] = 'T';
        if(seq[i] == 'T')
            temp[i] = 'A';
        if(seq[i] == 'G')
            temp[i] = 'C';
        if(seq[i] == 'C')
            temp[i] = 'G';
    }
    int j = temp.length() - 1;
    for (int i = 0; i < j; i++,j--)
    {
        char p = temp[i];
        temp[i] = temp[j];
        temp[j] = p;
    }
    complementary_strand = new DNA;
    complementary_strand->seq = temp;

}
//////////////////////////////////////////////////////////////////////////////////////////
RNA DNA::ConvertToRNA()                                                          // converting the DNA to RNA
{
    BuildComplementaryStrand();

    string tmp;
    tmp = complementary_strand->seq;

    for(int i = startIndex ; i < endIndex; i++ )
    {
        if(tmp[i] == 'T')
            tmp[i] = 'U';
    }
    RNA rna1(tmp , mRNA);

    return rna1 ;
}
//////////////////////////////////////////////////////////////////////////////////////////
DNA::~DNA()
{
    //dtor
}

