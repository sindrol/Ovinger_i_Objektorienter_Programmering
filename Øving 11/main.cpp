#include "Oppgave1.h"
#include "Person.h"
#include "LinkedList.h"
#include "TemplateFunksjoner.h"


//------------------------------------------------------------------------------'
void menyPrint();
void meny();
/*--------------------------------------------------------------------------------
Teorispørsmål:
3a) Vi kan kun ha én unique_ptr til hver minnelokasjon. Siden next er unique_ptr, må da prev være
	vanlig peker.

3b) Det vil være raskere å bruke en lenket liste når vi skal inserte og remove mange elementer på midten av lista.
	Dette går veldig raskt i en lenket liste siden det kun er elementet foran og bak som endres av sletting/inserting,
	i motsetning til i vektorer vil alle elementene vil få sin posisjon endret.
	
	For å implementere en stack ville jeg brukt lenket liste, men gjort at inserting bare var lov på første element
	"toppen" gjennom push, remove-ing også bare lov via første element eller "toppen" gjennom pop og lesing også
	bare i første element gjennom top.

	For å implementere queue vill jeg gjort det samme som med stack, men i stedet for å bare tillate remove-ing
	fra starten, ville jeg bare tillatt remove-ing fra slutten, og i stedet for å kunne lese fra starten så ville
	jeg latt lese fra både starten og slutten gjennom back og front.

4a) I maximum-funksjonen bruker jeg operatoren <, altså må denne være definert for typen hvis maximum skal fungere
	på denne typen.

5b) Datatypen som brukes må ha definert operatorene << og ==, samt ha defaultkontruktør, vanlig konstruktør
	, kopi-konstruktør og move-konstruktør.
//------------------------------------------------------------------------------*/

void testLinkedList();

// C++ programs start by executing the function main
int main()
{
	setlocale(LC_ALL, "nb_NO.UTF-8");
	srand(time(nullptr));
	

	meny();


	keep_window_open();

	return 0;
}

//------------------------------------------------------------------------------
void menyPrint(){
	cout<<"\n\n"
	<<"1) Iteratoruskrift av vector\n"
	<<"2) Som 1 men reversert\n"
	<<"3) Bytter ut alle 'Heisann' med 'Hva skjer'\n"
	<<"4-6) Samme som 1-3) men med set i stedet\n"
	<<"7) Oppgave 2b\n"
	<<"8) LinkedList-testing\n"
	<<"9) maximum\n"
	<<"10) 4b) vector-shuffle\n"
	<<endl;
}

void meny(){
	int svar;
	menyPrint();
	cin>>svar;

	//----------------------------------
	//Til bruk i diverse oppgaver
	vector<string> testVec{"Heisann","Hva skjeeeeer bro","Helene er søt","Waddup mydude","Heisann"};
	set<string> testSet{"Heisann","Hva skjeeeeer bro","Helene er søt","Waddup mydude","Heisann"};
	//
	Person sindre;
	Person helene{"Helene","Sunde"};
	sindre=helene;
	Person sindre2=Person{"Sindre","Olderkjær"};
	Person ole{"Ole","Dole"};
	list<Person> personListe;
	//multiset<string> testMultiset{"Heisann","Hva skjeeeeer bro","Helene er søt","Waddup mydude","Heisann"};
	
	//Oppgave 4
	int a=7;
	int b=4;
	vector<int> vecOppg4int{11,12,13,5,111,-122,32,51};
	vector<string> vecOppg4string{"hei","halloen","hva skjer","kamel","iste","unique_ptr er noe slit"};
	//-----------------------------------

	while(svar!=0){
		switch (svar)
		{
		case 1:
			printVec(testVec);
			break;
		case 2:
			printVecReverse(testVec);
			break;
		case 3:
			replace(testVec,string("Heisann"),string("Hva skjer"));
			printVec(testVec);
			break;
		case 4:
			printSet(testSet);
			break;
		case 5:
			printSetReverse(testSet);
			break;
		case 6:
			replace(testSet, string("Heisann"),string("Hva skjer"));
			printSet(testSet);
			break;
		case 7:
			insertOrdered(personListe,sindre);
			insertOrdered(personListe, sindre2);
			insertOrdered(personListe,helene);
			insertOrdered(personListe,ole);

			for (auto pers:personListe){
				cout<<pers<<endl;
			}
			break;
		case 8:
			testLinkedList();
			break;
		case 9:
			cout<<"Av 7 og 4 er "<<maximum(a,b)<<" størst"<<endl;
			break;
		case 10:
			shuffle(vecOppg4int);
			shuffle(vecOppg4string);
			cout<<"[";
			for (auto el : vecOppg4int){
				cout<<el<<",";
			}
			cout<<"]"<<endl;
			cout<<"[";
			for (auto el : vecOppg4string){
				cout<<el<<",";
			}
			cout<<"]"<<endl;
			break;
		/*Kun brukt for testing
		case 7:
			replace(testMultiset, string("Heisann"),string("Hva skjer"));
			printMultiset(testMultiset);
			break;*/
		default:
			cout<<"Ugyldig input"<<endl;
			break;
		}

		menyPrint();
		cin>>svar;
	}
	
}

void testLinkedList(){

	//Initialiserer, litt insert, litt remove
	LinkedList::LinkedList<string> test002{};
	LinkedList::Node<string>* ptr = test002.insert(test002.end(),"Heisann");
	LinkedList::Node<string>* ptr2=test002.insert(ptr,"På");
	ptr=test002.remove(ptr);
	ptr=test002.insert(ptr,"Degsann");
	ptr=test002.insert(test002.begin(),"Eyooo");
	
	//Skriver ut
	cout<<test002<<endl;

	//Find og remove(value)
	cout<<"Skal skrive ut Degsann: " << *test002.find("Degsann")<<std::endl;
	test002.remove("Eyooo");
	cout<<"Skal slette 'Eyooo':"<<std::endl;

	//Skriver ut
	cout<<test002<<endl;

	//Tester med int
	LinkedList::LinkedList<int> test003{};
	LinkedList::Node<int>* ptr3= test003.insert(test003.end(),5);
	ptr3=test003.insert(ptr3->getNext(),9);
	ptr3=test003.insert(ptr3->getNext(),2);
	ptr3=test003.insert(ptr3->getNext(), -5);
	cout<<test003<<endl;
	
	test003.remove(2);
	cout<<"Har slettet 2"<<endl;
	cout<<test003<<endl;
	

}

/*
LinkedList::LinkedList test001{};

    LinkedList::Node* nodePtr = test001.insert(test001.end(),"Heisann");
    //nodePtr=test001.insert(,"På Degsann");
    //nodePtr = test001.insert(test001.end()->getPrev(), "På Degsann");
    
    for (LinkedList::Node* ptr=test001.begin(); ptr!=test001.end(); ptr=ptr->getNext()){
        std::cout<<*ptr<<std::endl;
    }
*/