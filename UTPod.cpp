#include <iostream>
#include "UTPod.h"
using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = nullptr;

}

UtPod::UtPod(int size){

    if(size >= MAX_MEMORY || size <= 0){
        memSize = MAX_MEMORY;
    }
    memSize = size;
    songs = nullptr;

}

int UtPod::addSong(const Song &s) {

    if (s.getSize() <= getRemainingMemory()) {
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = songs;                     //this->songs
        songs = temp;
        return SUCCESS;
    }
    else{
        return NO_MEMORY;
    }
}


int UtPod::removeSong(Song const &s){

    if(songs == nullptr){
        return NOT_FOUND;
    }

    SongNode *ptr = songs;
    SongNode *ptr2 = nullptr;
    while (ptr != nullptr) {
        if (ptr->s == s) {

            ptr2->next = ptr->next;
            delete(ptr);

            return SUCCESS;

        } else {
            ptr2 = ptr;
            ptr = ptr->next;
        }
    }
    return NOT_FOUND;
}

void UtPod::shuffle(){

}

void UtPod::showSongList() {

    SongNode *ptr = songs;
    while(ptr != nullptr){
        cout << ptr->s.getArtist() << " " << ptr->s.getTitle() << " " << ptr->s.getSize() << endl;
        ptr = ptr->next;
    }
}

void UtPod::sortSongList(){

    SongNode *smallest;

    for(smallest = songs; smallest != nullptr; smallest = smallest->next ) {
        for (SongNode *p1 = smallest->next; p1 != nullptr; p1 = p1->next) {
            if (p1->s < smallest->s) {
                Song temp = p1->s;
                p1->s = smallest->s;
                smallest->s = temp;
            }
        }
    }
}

void UtPod::clearMemory() {
    SongNode *ptr = songs;
    while(ptr != nullptr) {
        songs = ptr->next;
        delete(ptr);
        ptr = songs;
    }
}

int UtPod::getRemainingMemory() {
    int totMem = 0;
    SongNode *ptr = songs;
    while(ptr != nullptr){
        totMem = totMem + ptr->s.getSize();
        ptr = ptr->next;
    }
    int mem = memSize - totMem;
    return mem;

}


UtPod::~UtPod() {
    cout << "In the destructor for something" << endl;
    clearMemory();
}




