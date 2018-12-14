#ifndef DNA_H
#define DNA_H
#include <iostream>
#include "sequance.h"
#include "RNA.h"

using namespace std;

enum DNA_Type{promoter, motif, tail, noncoding};
class RNA;
class DNA: public sequance
{
    public:
        DNA_Type type;
        DNA  *complementary_strand;
        int startIndex;
        int endIndex;


        DNA();
        DNA(string sequ , DNA_Type atype);
        DNA(DNA& rhs);

        RNA ConvertToRNA();

        void BuildComplementaryStrand();
        void print();
        virtual ~DNA();

        DNA operator+ (DNA rhs);
        bool operator== (DNA rhs);
        bool operator!= (DNA rhs);

        friend ostream& operator<< (ostream& out ,const DNA& d);
        friend istream& operator>> (istream& in , DNA& d);

    protected:

    private:
};

#endif // DNA_H
