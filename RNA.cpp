#include "RNA.h"
#include <iostream>
#include <string.h>
using namespace std;
RNA::RNA()
{
}
////////////////////////////////////////////////////////////////////////////////////
RNA::RNA(string sequ , RNA_Type atype = mRNA) // constructor with paramitars
{
    seq=sequ;
    type = atype;
}
////////////////////////////////////////////////////////////////////////////////////
RNA::RNA(RNA& rhs)                            //copy constructor
{
    seq = rhs.seq;
    type = rhs.type;
}
////////////////////////////////////////////////////////////////////////////////////
void RNA::print()
{

    cout << seq << endl;
    cout << type << endl;
}
////////////////////////////////////////////////////////////////////////////////////
DNA RNA::ConvertToDNA()                                     //converting the RNA to DNA
{
    string tmp;
    tmp = seq;
    int len = tmp.length();
    for(int i = 0 ; i < len; i++ )
    {
        if(tmp[i] == 'U')
            tmp[i] = 'T';
    }
    DNA dna1(tmp , promoter);

    return dna1;
}
////////////////////////////////////////////////////////////////////////////////////
Protein RNA::ConvertToProtein(const CodonsTable & table)//converting the RNA to protein
{
    string willbeprotien = ""; // that string will be the seq of the protein

    for(int j = 0 ;j< seq.length(); j+=3)
    {
        string tmp = "";
        tmp+= seq[j];
        tmp+= seq[j+1];
        tmp+= seq[j+2];
        for(int i = 0;i< 64;i++)
        {
            if (tmp == table.codons[i].value)  // check the value in the table
                {
                    willbeprotien = willbeprotien + table.codons[i].AminoAcid; // add the aminoacid to the string (seq)
                }
        }
    }

    Protein pro(willbeprotien,Hormon); //using the constructor to create the protein
    return pro;
}
////////////////////////////////////////////////////////////////////////////////////
RNA RNA::operator+ (RNA rhs)   //operator over loading for +
{
    if(type == rhs.type)
    {
        string s = seq+rhs.seq;
        RNA d;
        d.seq = s;
        return d;
    }
    else{cout <<"the type is not the same"<<endl;}
}
////////////////////////////////////////////////////////////////////////////////////
bool RNA::operator== (RNA rhs)      //operator over loading for ==
{
    if(seq == rhs.seq && type == rhs.type)
        return 1;
    else
        return 0;
}
////////////////////////////////////////////////////////////////////////////////////
bool RNA::operator!= (RNA rhs)      //operator over loading for !=
{
    if(seq != rhs.seq || type != rhs.type)
        return 1;
    else
        return 0;
}
////////////////////////////////////////////////////////////////////////////////////
RNA::~RNA()
{
    //dtor
}
