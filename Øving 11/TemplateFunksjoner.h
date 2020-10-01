#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;

template<typename T>
int maximum(T a, T b){
    if(a<b)
        return b;
    return a;
}

template<typename T>
void shuffle(vector<T>& vec){
    int random;
    int lengde =static_cast<int>(vec.size());
    vector<int> controlVec(lengde,0); //vektor for å holde styr på hvilke elementer fra newVec2 som er brukt
    vector<T> valueVec=vec;
    

    for (int i = 0; i<lengde; i++){
        //Finner tilfeldig indeks 
        random=rand()%lengde;
        while(controlVec[random]==1){ //1 signaliserer at elementet er brukt
            random=rand()%lengde;
        }

        vec[i] = valueVec[random];
        controlVec[random]=1;
    }
    
}