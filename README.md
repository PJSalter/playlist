# playlist

### Description

This program is used to create a new playlist in `C++`.
This `C++ program` allows you to create and manipulate a playlist using a linked list. It provides various options to manage the playlist, including adding, removing, changing the position of songs, and more.

### Usage

To compile and run the program, use the following commands:

```
g++ main.cpp PlaylistNode.cpp -o PlaylistApp
./PlaylistApp

```

### Files to Submit

- `PlaylistNode.h`: Class declaration
- `PlaylistNode.cpp`: Class definition
- `main.cpp`: Main function

### PlaylistNode Class

The `PlaylistNode` class is designed with the following specifications:

### Public Member Functions

- Default constructor
- Parameterized constructor
- `InsertAfter()`: Mutator
- `SetNext()`: Mutator
- `GetID()`: Accessor
- `GetSongName()`: Accessor
- `GetArtistName()`: Accessor
- `GetSongLength()`: Accessor
- `GetNext()`: Accessor
- `PrintPlaylistNode()`

### Private Data Members

- `string uniqueID`: Initialized to "none" in the default constructor
- `string songName`: Initialized to "none" in the default constructor
- `string artistName`: Initialized to "none" in the default constructor
- `int songLength`: Initialized to 0 in the default constructor
- `PlaylistNode* nextNodePtr`: Initialized to `nullptr` in the default constructor

Example of `PrintPlaylistNode` output:

```
Unique ID: S123
Song Name: Peg
Artist Name: Steely Dan
Song Length (in seconds): 237

```

# Main Function

1. Prompt the user for the title of the playlist.

```
Enter playlist's title:
JAMZ

```

2.  Implement the `PrintMenu()` function:

    - Print a menu of options to manipulate the playlist.
    - Continue to execute the menu until the user enters 'q' to Quit.
    - Options include: 
- `'a' - Add song` 
- `'d' - Remove song`
- `'c' - Change position of song` 
- `'s' - Output songs by specific artist`
- `'t' - Output total time of playlist (in seconds)` 
- `'o' - Output full playlist` 
- `'q' - Quit`

Example:

           ```
      JAMZ PLAYLIST MENU

      a - Add song
      d - Remove song
      c - Change position of song
      s - Output songs by specific artist
      t - Output total time of playlist (in seconds)
      o - Output full playlist
      q - Quit

     Choose an option:

           ```

3. Implement the "Output full playlist" menu option. If the list is empty, output: "Playlist is empty."

Example:

```
JAMZ - OUTPUT FULL PLAYLIST
1.
Unique ID: SD123
Song Name: Peg
Artist Name: Steely Dan
Song Length (in seconds): 237

2.
Unique ID: JJ234
Song Name: All For You
Artist Name: Janet Jackson
Song Length (in seconds): 391

...

```

4. Implement the "Add song" menu item. New additions are added to the end of the list.

Example:

```
ADD SONG
Enter song's unique ID:
SD123
Enter song's name:
Peg
Enter artist's name:
Steely Dan
Enter song's length (in seconds):
237

```

5. Implement the "Remove song" function. Prompt the user for the unique ID of the song to be removed.

Example:

```
REMOVE SONG
Enter song's unique ID:
JJ234
"All For You" removed.

```

6. Implement the "Change position of song" menu option. Prompt the user for the current position of the song and the desired new position.

Example:

```

CHANGE POSITION OF SONG
Enter song's current position:
3
Enter new position for song:
2
"Canned Heat" moved to position 2
```

7. Implement the "Output songs by specific artist" menu option. Prompt the user for the artist's name, and output the node's information, starting with the node's current position.

Example:

```
OUTPUT SONGS BY SPECIFIC ARTIST
Enter artist's name:
Janet Jackson

2.
Unique ID: JJ234
Song Name: All For You
Artist Name: Janet Jackson
Song Length (in seconds): 391

4.
Unique ID: JJ456
Song Name: Black Eagle
Artist Name: Janet Jackson
Song Length (in seconds): 197

```

8. Implement the "Output total time of playlist" menu option. Output the sum of the time of the playlist's songs (in seconds).

Example:

```
OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)
Total time: 1461 seconds

```

✨ Happy Coding 🚀
