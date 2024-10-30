// Playlist Manager using Doubly Linked list
#include <iostream>
#include <string.h>
using namespace std;
class Song
{
    string title;
    string artist;
    Song *next;
    Song *prev;

public:
    Song(string title, string artist)
    {
        this->title = title;
        this->artist = artist;
        this->next = NULL;
        this->prev = NULL;
    }
    // function to set the data of the node
    void setData(string t, string a)
    {
        title = t;
        artist = a;
    }
    // function to get the data of the node
    string getData()
    {
        return title  +  "by"  +  artist;
    }
    string getTitle()
    {
        return title;
    }
    string getArtist()
    {
        return artist;
    }
    // function to set the next pointer of the node
    void setNext(Song *n)
    {
        next = n;
    }
    // function to get the next pointer of the node
    Song *getNext()
    {
        return next;
    }
    // function to set the previous pointer of the node
    void setPrev(Song *p)
    {
        prev = p;
    }
    // function to get the previous pointer of the node
    Song *getPrev()
    {
        return prev;
    }
};
class Playlist
{
    Song *head;
    Song *tail;

public:
    Playlist()
    {
        head = NULL;
        tail = NULL;
    }
    // function to set the head node
    void setHead(Song *h)
    {
        head = h;
    }
    // function to get the head node
    Song *gethead()
    {
        return head;
    }
    // add song to the beginning ,then to the end, and after a specific song in the playlist

    void addSongStart(string title, string artist)
    {
        Song *s = new Song(title, artist);
        if (head == NULL)
        {
            head = s;
        }
        else
        {
            s->setPrev(NULL);
            head->setPrev(s);
            s->setNext(head);
            head = s;
        }
        cout << "The song played is:" << title << "  " << "by" << "  " << artist << endl;
    }

    void addSongEnd(string title, string artist)
    {
        Song *s = new Song(title, artist);
        if (tail == NULL)
        {
            head = s;
            tail = s;
        }
        else
        {
            Song *newSong = head;
            while (newSong->getNext() != NULL)
            {
                newSong = newSong->getNext();
            }
            newSong->setNext(s);
            s->setPrev(newSong);
            tail = s;
        }
        cout << "The song played is:" << title << "  " << "by" << "  " << artist << endl;
    }
    void addSongAfterEachSong(string title, string artist, int loc)
    {
        Song *s = new Song(title, artist);
        if (loc == 0)
        {
            addSongStart(title, artist);
        }
        else
        {
            Song *current = head;

            for (int i = 0; i < loc - 1; i++)
            {
                current = current->getNext();
            }
            s->setPrev(current);
            s->setNext(current->getNext());
            if (s->getNext() != NULL)
            {
                s->getNext()->setPrev(s);
            }
            current->setNext(s);
            cout << "The song played is:" << title << "  " << "by" << "  " << artist << endl;
        }
    }
    void RemoveSong()
    {
        if (head == NULL)
        {
            cout << "No songs to remove" << endl;
        }
        else
        {
            if (head == tail)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else
            {
                Song *current = head;
                while (current->getNext() != tail)
                {
                    current = current->getNext();
                }
                delete tail;
                tail = current;
                tail->setNext(NULL);
            }
        }
    }
    void DisplaySongsFromBegToEnd()
    {
        // Current pointer traversing forwards in the loop
        Song *Current = head;
        while (Current != NULL)
        {
            cout << Current->getData() << endl;
            Current = Current->getNext();
        }
    }
    void DisplaySongsFromEndToBeg()
    {
        // Current pointer traversing backwards in the loop
        Song *Current = tail;
        while (Current != NULL)
        {

            cout << Current->getData() << endl;
            Current = Current->getPrev();
        }
    }
    void SearchSong(string key)
    {

        Song *Current = head;
        if (Current == NULL)
        {
            cout << "No songs to search" << endl;
        }
        while (Current != NULL)
        {

            if (Current->getTitle() == key)
            {

                cout << "The song played is:" << Current->getData() << endl;
                return;
            }
            Current = Current->getNext();
        }
    }
    // play the next song after the title
    void playNext(string title)
    {
        Song *current = head;
        while (current != NULL)
        {
            if (current->getTitle() == title)
            {
                if (current->getNext() != NULL)
                {
                    cout << "Next song: " << current->getNext()->getData() << endl;
                }
                else
                {
                    cout << "This is the last song, no next song." << endl;
                }
                return;
            }
            current = current->getNext();
        }
        cout << "Song not found in the playlist." << endl;
    }

    // Play the previous song before the given title
    void playPrev(string title)
    {
        Song *current = head;
        while (current != NULL)
        {
            if (current->getTitle() == title)
            {
                if (current->getPrev() != NULL)
                {
                    cout << "Previous song: " << current->getPrev()->getData() << endl;
                }
                else
                {
                    cout << "This is the first song, no previous song." << endl;
                }
                return;
            }
            current = current->getNext();
        }
        cout << "Song not found in the playlist." << endl;
    }
};
int main()
{
    // creating an object p1 which will call the above functions to create the  Song linked list using the menu function
    Playlist p1;
    int choice;
    do
    {
        cout << "\nChoose the operations on Playlist Manager:" << endl;
        cout << "1. Add Song at the start" << endl;
        cout << "2. Add Song after each Song" << endl;
        cout << "3. Add Song at the end" << endl;
        cout << "4. remove Song" << endl;
        cout << "5.Search any song " << endl;
        cout << "6. Play the next song" << endl;
        cout << "7. Play the previous song" << endl;
        cout << "8. Display the Playlist" << endl;
        cout << "9. Display the Playlist on reverse" << endl;
        cout << "10. Exiting the Playlist" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the Song title and artist:";
            string a;
            getline(cin, a);
            string b;
            getline(cin, b);
            p1.addSongStart(a, b);
            break;
        }
        case 2:
        {
            cout << "Enter the Song title and artist: ";
            string a;
            getline(cin, a);
            string b;
            getline(cin, b);
            int loc;
            cout << "At what Location:";
            cin >> loc;
            p1.addSongAfterEachSong(a, b, loc);
            break;
        }
        case 3:
        {
            cout << "Enter the Song to be played at the end:";
            string a;
            getline(cin, a);
            string b;
            getline(cin, b);
            p1.addSongEnd(a, b);
            break;
        }
        case 4:
        {
            p1.RemoveSong();
            break;
        }
        case 5:
        {
            cout << "Enter the Song to be searched: ";
            string key;
            getline(cin, key);
            p1.SearchSong(key);
            break;
        }
        case 6:
        {
            string t;
            cout << "Enter the Song title to be played next: ";
            getline(cin, t);
            cout << "The next Song is: ";
            p1.playNext(t);
            break;
        }
        case 7:
        {
            string t;
            cout << "Enter the Song title: ";
            getline(cin, t);
            cout << "I should replay the previous song in the playlist" << endl;
            p1.playPrev(t);
            break;
        }
        case 8:
        {
            cout << "My music playlist from beg to end is" << endl;
            p1.DisplaySongsFromBegToEnd();
            break;
        }
        case 9:
        {
            cout << "My music playlist from end to beg is" << endl;
            p1.DisplaySongsFromEndToBeg();
            break;
        }
        case 10:
        {
            cout << "Exiting the Playlist" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 10);
    return 0;
}
