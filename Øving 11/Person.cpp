#include "Person.h"


Person::Person(Person&& pers){
    fornavn=pers.fornavn;
    etternavn=pers.etternavn;

    pers.fornavn="";
    pers.etternavn="";
}

Person Person::operator=(const Person& pers){
    etternavn=pers.etternavn;
    fornavn=pers.fornavn;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Person pers){
    os<<pers.fornavn<<" "<<pers.etternavn;
    return os;
}


void insertOrdered(std::list<Person>& l, const Person& p){ 
    if(l.empty()) //Hvis lista tom
        l.insert(l.begin(),p);

    else if( l.back()<p) //Hvis p skal plasseres bakerst
        l.push_back(p);

    else{ //Sjekker om p er mindre enn hvert element og legger inn p før elementet hvis true.
        std::list<Person>::iterator it=l.begin();
        while ( it!=l.end()){
            if(p<*it){
                l.insert(it,p);
                break;
            }
            it++;
        }
    }

}
/*Sneaky måte
void insertOrdered(std::list<Person>& l, const Person& p){
    l.insert(l.begin(), p);
    l.sort();
}*/