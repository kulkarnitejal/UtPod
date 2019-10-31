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
    SongNode *ptr2;
    while (ptr != nullptr) {
        if (ptr->s == s) {
            ptr2 = ptr->next;
            if (ptr2 == nullptr) {
                ptr = ptr2;
            } else {
                ptr->next = ptr2->next;
            }
            delete(ptr);
            return SUCCESS;

        } else {

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
        cout << ptr->s.getArtist() << ptr->s.getTitle() << ptr->s.getSize() << endl;
        ptr = ptr->next;
    }
}

void UtPod::sortSongList(){


}

void UtPod::clearMemory() {
    SongNode *ptr = songs;
    SongNode *ptr2 = songs->next;
    while(ptr != nullptr) {

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




