#include <iostream>
#include <string>
#include <limits> // Add this line to include the numeric_limits header
#include "PlaylistNode.h"
using namespace std;

// Function declarations
void PrintMenu(const string &playlistTitle);
void AddSong(PlaylistNode *&head);
void RemoveSong(PlaylistNode *&head);
void ChangePositionOfSong(PlaylistNode *&head);
void OutputSongsByArtist(const PlaylistNode *head); // Modified parameter type
void OutputTotalTime(const PlaylistNode *head);     // Modified parameter type

void OutputFullPlaylist(PlaylistNode *head, const string &playlistTitle)
{
    cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
    if (head == nullptr)
    {
        cout << "Playlist is empty" << endl;
        cout << endl;
        return;
    }

    int position = 1;
    PlaylistNode *currentNode = head;
    while (currentNode != nullptr)
    {
        cout << position << "." << endl;
        currentNode->PrintPlaylistNode();
        cout << endl; // Add an extra newline after each song
        currentNode = currentNode->GetNext();
        position++;
    }
}

//--------------------------------------------------------//
//----------------- Add Option ---------------------- //
//------------------------------------------------------//
void AddSong(PlaylistNode *&head)
{
    string uniqueID, songName, artistName;
    int songLength;

    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> uniqueID;
    cin.ignore(); // Ignore the newline character
    cout << "Enter song's name:" << endl;
    getline(cin, songName);
    cout << "Enter artist's name:" << endl;
    getline(cin, artistName);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> songLength;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the remaining input until a newline character

    // Create a new PlaylistNode with the entered information
    PlaylistNode *newNode = new PlaylistNode(uniqueID, songName, artistName, songLength);

    if (head == nullptr)
    {
        // If the playlist is empty, set the new node as the head
        head = newNode;
    }
    else
    {
        // Otherwise, find the tail of the list and add the new node after it
        PlaylistNode *currentNode = head;
        while (currentNode->GetNext() != nullptr)
        {
            currentNode = currentNode->GetNext();
        }
        currentNode->InsertAfter(newNode);
    }

    cout << "\"" << songName << "\" by " << artistName << " added to the playlist." << endl;
}

//--------------------------------------------------------//
//----------------- Delete Option ---------------------- //
//------------------------------------------------------//

void RemoveSong(PlaylistNode *&head)
{
    if (head == nullptr)
    {
        cout << "Playlist is empty. No songs to remove." << endl;
        return;
    }

    string uniqueID;
    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> uniqueID;

    PlaylistNode *prevNode = nullptr;
    PlaylistNode *currentNode = head;
    while (currentNode != nullptr)
    {
        if (currentNode->GetID() == uniqueID)
        {
            // Found the node with the given unique ID, remove it from the list
            if (prevNode == nullptr)
            {
                // If it's the head node
                head = currentNode->GetNext();
            }
            else
            {
                prevNode->SetNext(currentNode->GetNext());
            }

            cout << currentNode->GetSongName() << " removed." << endl; // Remove double quotes
            delete currentNode;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->GetNext();
    }

    cout << "Song with unique ID \"" << uniqueID << "\" not found in the playlist." << endl;
}

//------------------------------------------------------------------//
//----------------- Change Position of Song ---------------------- //
//----------------------------------------------------------------//

void ChangePositionOfSong(PlaylistNode *&head)
{
    if (head == nullptr)
    {
        cout << "Playlist is empty. No songs to move." << endl;
        return;
    }

    int currentPosition, newPosition;
    cout << "CHANGE POSITION OF SONG" << endl;
    cout << "Enter song's current position:" << endl;
    cin >> currentPosition;
    cout << "Enter new position for song:" << endl;
    cin >> newPosition;

    int listSize = 0;
    PlaylistNode *currentNode = head;
    PlaylistNode *prevCurrentNode = nullptr;
    PlaylistNode *nodeToMove = nullptr;

    // Traverse the list to find the node to move and its previous node
    while (currentNode != nullptr)
    {
        listSize++;
        if (listSize == currentPosition)
        {
            nodeToMove = currentNode;
            break; // Stop the loop once the node to move is found
        }
        prevCurrentNode = currentNode;
        currentNode = currentNode->GetNext();
    }

    // Check if the current position is valid
    if (nodeToMove == nullptr)
    {
        cout << "Invalid current position. Song position remains unchanged." << endl;
        return;
    }

    // Remove the node from its current position
    if (prevCurrentNode == nullptr)
    {
        // Node is the head node
        head = head->GetNext();
    }
    else
    {
        prevCurrentNode->SetNext(nodeToMove->GetNext());
    }

    // Find the new position and insert the node there
    currentNode = head;
    prevCurrentNode = nullptr;
    int newPositionCount = 1;
    while (newPositionCount != newPosition && currentNode != nullptr)
    {
        prevCurrentNode = currentNode;
        currentNode = currentNode->GetNext();
        newPositionCount++;
    }

    // Insert the node at the new position
    if (prevCurrentNode == nullptr)
    {
        // Inserting at the head
        nodeToMove->SetNext(head);
        head = nodeToMove;
    }
    else
    {
        prevCurrentNode->SetNext(nodeToMove);
        nodeToMove->SetNext(currentNode);
    }

    cout << "\"" << nodeToMove->GetSongName() << "\" moved to position " << newPosition << "." << endl;
}

//--------------------------------------------------------------------------//
//----------------- Output Songs by Specific Artist ---------------------- //
//------------------------------------------------------------------------//

void OutputSongsByArtist(const PlaylistNode *head)
{
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    if (head == nullptr)
    {
        cout << "Playlist is empty. No songs to display." << endl;
        return;
    }

    string artistName;
    cout << "Enter artist's name:" << endl;
    getline(cin, artistName);

    int position = 1;
    const PlaylistNode *currentNode = head; // Use const PlaylistNode*
    bool found = false;

    cout << endl;
    while (currentNode != nullptr)
    {
        if (currentNode->GetArtistName() == artistName)
        {
            cout << position << "." << endl;
            currentNode->PrintPlaylistNode();
            cout << endl;
            found = true;
        }
        currentNode = currentNode->GetNext();
        position++;
    }

    if (!found)
    {
        cout << "No songs by " << artistName << " found in the playlist." << endl;
    }
}

//--------------------------------------------------------------------------//
//----------------- Output Total Time of Playlist ------------------------ //
//------------------------------------------------------------------------//

void OutputTotalTime(const PlaylistNode *head)
{
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    if (head == nullptr)
    {
        cout << "Playlist is empty. No songs to calculate total time." << endl;
        return;
    }

    int totalTime = 0;
    const PlaylistNode *currentNode = head; // Use const PlaylistNode*

    while (currentNode != nullptr)
    {
        totalTime += currentNode->GetSongLength();
        currentNode = currentNode->GetNext();
    }

    cout << "Total time: " << totalTime << " seconds" << endl;
    cout << endl;
}

//--------------------------------------------------------------------------//
//-------------------------------- Main -----------------------------------//
//------------------------------------------------------------------------//

int main()
{
    string playlistTitle;
    cout << "Enter playlist's title:" << endl;
    cout << endl;
    getline(cin, playlistTitle);

    PlaylistNode *head = nullptr; // Initialize the head pointer of the linked list

    char choice;
    do
    {
        PrintMenu(playlistTitle);
        cin >> choice;
        cin.ignore(); // Ignore the newline character after reading the choice

        switch (choice)
        {
        case 'a':
            AddSong(head);
            break;
        case 'd':
            RemoveSong(head);
            OutputFullPlaylist(head, playlistTitle);
            break;
        case 'c':
            ChangePositionOfSong(head);
            OutputFullPlaylist(head, playlistTitle);
            break;
        case 's':
            OutputSongsByArtist(const_cast<const PlaylistNode *>(head));
            break;
        case 't':
            OutputTotalTime(const_cast<const PlaylistNode *>(head));
            break;
        case 'o':
            OutputFullPlaylist(head, playlistTitle);
            break;
        case 'q':
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining input until a newline character
        }
    } while (choice != 'q');

    return 0;
}

void PrintMenu(const string &playlistTitle)
{
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:";
    cout << "\n";

    cin.clear(); // Clear any errors from the input stream
}

// void OutputFullPlaylist(PlaylistNode* head, const string& playlistTitle) {
//     cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
//     if (head == nullptr) {
//        cout << "Playlist is empty" << endl;
//        return;
//     }

//     int position = 1;
//     PlaylistNode* currentNode = head;
//     while (currentNode != nullptr) {
//        cout << position << ". ";
//        currentNode->PrintPlaylistNode();
//        cout << endl;
//        currentNode = currentNode->GetNext();
//        position++;
//     }
// }
