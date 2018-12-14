#ifndef RNA_H
#define RNA_H
#include "sequance.h"
#include "DNA.h"
#include "Protein.h"
#include "CodonsTable.h"

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon1, mRNA_exon2}; //RNA types
class DNA;
class RNA:public sequance                                      //inheritance from seq
{
    public:
        RNA_Type type;
        RNA();
        RNA(string seq, RNA_Type atype);    //parametar constructor
        RNA(RNA & rhs);                     //copy constructor

        void print();                       //print function
        virtual ~RNA();
        Protein ConvertToProtein(const CodonsTable & table);// converting the RNA to protein
        DNA ConvertToDNA(); // converting RNA to DNA

        RNA operator+ (RNA rhs); // operator over loading for +
        bool operator== (RNA rhs); // operator over loading for ==
        bool operator!= (RNA rhs); // operator over loading for !=

        friend ostream& operator<< (ostream& out ,const RNA& d); // operator over loading for <<
        friend istream& operator>> (istream& in , RNA& d);// operator over loading for >>
    protected:

    private:
};

#endif // RNA_H
