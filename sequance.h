#ifndef SEQUANCE_H
#define SEQUANCE_H
#include <iostream>
using namespace std;

class sequance
{
    public:
        string seq;
        sequance();
        sequance(sequance& rhs);

        virtual void print() = 0; // virtual function (pure )
        virtual ~sequance();

       string Align( sequance * s2);
    protected:


    private:
};

#endif // SEQUANCE_H
