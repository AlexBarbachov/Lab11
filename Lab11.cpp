#include <iostream>
#include <string>

using namespace std;


// Will store the name, artists in the playlist, and some song names
// Dynamic array will be the list of songs.
struct Playlist
{
    string name;
    string *songs;

    // size of the array
    int numSongs;

    // max mem for array
    int maxSongs;   
};

int main()
{

}


/* 
will add a song to the playlist and allocate more memory if needed
Done through deleting array and creating a new one with more size
*/
void addSong(Playlist &playlist, string newSong)
{
    // allocate more memory if playlist array is full
    if (playlist.numSongs == playlist.maxSongs)
    {
        if (playlist.maxSongs == 0)
        {
            playlist.maxSongs == 1;
        }
        else
        {
            playlist.maxSongs *= 2;
        }

            // initialize new dynamic array
    string *songs = new string[playlist.maxSongs];

        // copy over old songs into new array
        for (int i = 0; i < playlist.numSongs; i++)
        {
            songs[i] = playlist.songs[i];
        }

        // free up memory
        delete [] playlist.songs;

        // update object playlist with new value
        playlist.songs = songs;
    }


    // add the song after we're done growing the array if needed
    playlist.songs[playlist.numSongs] = newSong;

    // update new size + 1.
    playlist.numSongs++;
    

}



