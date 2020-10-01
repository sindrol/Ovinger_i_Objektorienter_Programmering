#include <iostream>
#include <string>
#include <list>



class Person{
    std::string fornavn;
    std::string etternavn;

public:
    Person(): fornavn{}, etternavn{}{}
    Person(std::string firstName, std::string surname): fornavn{firstName}, etternavn{surname}{}

    //Kopi-konstruktører
    Person(const Person& pers): fornavn{pers.fornavn},etternavn{pers.etternavn}{}
    Person operator=(const Person& pers);

    Person(Person&& pers); //Move-konstruktør

    bool operator<(Person persR) const{return fornavn<persR.fornavn;}

    friend std::ostream& operator<<(std::ostream& os, const Person pers);

    //Andre funksjoner
    friend void insertOrdered(std::list<Person> &l, const Person& p); //Sorterer på fornavn
};