#ifndef PROTEIN_H
#define PROTEIN_H
#include "sequance.h"

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function}; // protein types
class Protein:public sequance
{
    public:
        Protein_Type type;
        Protein();
        Protein(string p, Protein_Type atype);
        Protein(Protein& rhs );

        void print();  // print functions

        //DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
        virtual ~Protein();

        Protein operator+ (Protein rhs);
        bool operator== (Protein rhs);
        bool operator!= (Protein rhs);

        friend ostream& operator<< (ostream& out ,const Protein& d);
        friend istream& operator>> (istream& in , Protein& d);

    protected:

    private:
};

#endif // PROTEIN_H
