//
// Created by kvigg on 10/28/2019.
//
#include <string>
#include <iostream>

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

using namespace std;


class Song{

    private:
        string artist;
        string title;
        int size;

    public:
        Song();
        Song(string artist, string title, int size);

        string getArtist() const{
            return artist;
        }
        void setArtist(const string &artist){
            this->artist = artist;
        }
        string getTitle() const{
            return title;
        }
        void setTitle(const string &title){
            this->title =  title;
        }
        int getSize() const{
            return size;
        }
        void setSize(int size){
            this->size = size;
        }
        bool operator >(Song const &rhs);

        bool operator <(Song const &rhs);

        bool operator ==(Song const &rhs);

        ~Song();
};

#endif //UTPOD_SONG_H


