#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
//------------------------------------------------------------------------------'

template<typename T>
void printVec(vector<T> vec){
	for (typename vector<T>::iterator it=vec.begin(); it!=vec.end(); it++){
		cout<<*it<<endl;
	}
}


template<typename T>
void printVecReverse(vector<T> vec){
	for (typename vector<T>::reverse_iterator it=vec.rbegin(); it!=vec.rend(); it++){
		cout<<*it<<endl;
	}
}

template<typename T>
void replace(vector<T>& vec, T old, T replacement){
    typename vector<T>::iterator it=find(vec.begin(),vec.end(),old);
    while (it!=vec.end()){
        it=vec.insert(it,replacement);
        it=vec.erase(++it);

        it=find(vec.begin(),vec.end(),old);
    }
}

/*
//Versjon enkel
template<typename T>
void replace(vector<T>& vec, T old, T replacement){
    typename vector<T>::iterator it = vec.begin();
    while ( it!=vec.end()){
        if(*it==old){
            it=vec.insert(it,replacement);
            it=vec.erase(++it);
        }
        else
            it++;
    }
}*/

/*
//Versjon enkel
template<typename T>
void replace(vector<T>& vec, T old, T replacement){

    for (typename vector<T>::iterator it = vec.begin(); it!=vec.end(); it++){
        if(*it==old){
            it=vec.erase(it);
            it=vec.insert(it,replacement);
        }
    }
}
*/

template<typename T>
void printSet(set<T> s){
    for(typename set<T>::iterator it=s.begin(); it!=s.end(); it++){
        cout<<*it<<endl;
    }
}

template<typename T>
void printSetReverse(set<T> s){
    for(typename set<T>::reverse_iterator it=s.rbegin(); it!=s.rend(); it++){
        cout<<*it<<endl;
    }
}

template<typename T>
void replace(set<T>& s, T old, T replacement){
    for (typename set<T>::iterator it=s.begin(); it!=s.end(); it++){
        if(*it==old){
            it=s.erase(it);
            it=s.insert(it,replacement);
        }
    }
}


/*Ikke del av oppgaven
//Vil ikke fungere skikkelig, bare bytte ut den ene, siden elementene sorteres og iteratorene da
//hopper litt gøyalt
template<typename T>
void replace(multiset<T>& s, T old, T replacement){
    for (typename multiset<T>::iterator it=s.begin(); it!=s.end(); it++){
        if(*it==old){
            it=s.erase(it);
            it=s.insert(it,replacement);
        }
    }
}

template<typename T>
void printMultiset(multiset<T> s){
    for(typename multiset<T>::iterator it=s.begin(); it!=s.end(); it++){
        cout<<*it<<endl;
    }
}
//-----------------*/

void keep_window_open();
