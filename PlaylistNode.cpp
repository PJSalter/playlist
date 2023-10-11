#include "PlaylistNode.h"
#include <iostream>
using namespace std;

PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}

PlaylistNode::PlaylistNode(std::string uniqueID, std::string songName, std::string artistName, int songLength)
    : uniqueID(uniqueID), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nullptr) {}

std::string PlaylistNode::GetID() const
{
    return uniqueID;
}

std::string PlaylistNode::GetSongName() const
{
    return songName;
}

std::string PlaylistNode::GetArtistName() const
{
    return artistName;
}

int PlaylistNode::GetSongLength() const
{
    return songLength;
}

PlaylistNode *PlaylistNode::GetNext() const
{
    return nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode *nodePtr)
{
    PlaylistNode *tempNext = nextNodePtr;
    nextNodePtr = nodePtr;
    nodePtr->nextNodePtr = tempNext;
}

void PlaylistNode::SetNext(PlaylistNode *nodePtr)
{
    nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode() const
{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}
