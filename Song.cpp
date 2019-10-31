//
// Created by kvigg on 10/28/2019.
//
#include "Song.h"
using namespace std;

Song::Song(){
    artist = "";
    title = "";
    size = 0;
};

Song::Song(string artist, string title, int size){
    this->artist = artist;
    this->title = title;
    this->size = size;

}

bool Song::operator >(Song const &rhs){
    return(artist > rhs.artist || title > rhs.title || size > rhs.size);

}

bool Song::operator <(Song const &rhs){
    return(artist < rhs.artist || title < rhs.title || size < rhs.size);

}

bool Song::operator ==(Song const &rhs){
    return(artist == rhs.artist || title == rhs.title || size == rhs.size);

}

Song::~Song(){
    cout << "debug - in destructor for " << artist << title << endl;
}