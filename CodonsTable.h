#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include<fstream>
#include<cstring>

using namespace std;
struct Codon
{
  	char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};
class CodonsTable
{
    public:
        Codon codons[64];  // array of codons


        CodonsTable(string codonsFileName);

        void LoadCodonsFromFile(string codonsFileName);  // loading data from file using filename
        Codon getAminoAcid(char * value);    // getting the AminoAcid using value (***)
        void setCodon(char * value, char AminoAcid, int index); // set codon
        virtual ~CodonsTable();

    protected:

    private:
};

#endif // CODONSTABLE_H
