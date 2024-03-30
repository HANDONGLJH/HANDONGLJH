# Manga Management System

This Manga Management System allows for creating, reading, updating, and deleting manga records. Developed in C, it utilizes a dynamic array to store manga details and supports file operations for persistent storage.

## Files

- `manga.h`: Header file containing the declarations necessary for the Manga Management System.
- `manga.c`: Source file implementing the functionalities declared in `manga.h`.

## manga.h

This header file defines the `Manga` struct, which includes fields for a manga's title, author, weekly rank, monthly rank, and genre. It also declares functions for various operations such as adding, updating, deleting, saving, loading, and finding mangas. The constants `MAX_TITLE`, `MAX_AUTHOR`, `MAX_GENRE`, and `MAX_MANGAS` are defined to cap the sizes for titles, authors, genres, and the maximum number of mangas respectively.

### Structs

- `Manga`: A struct that encompasses a manga's title, author, weekly rank, monthly rank, and genre.

### Constants

- `MAX_TITLE`: Maximum length for a manga title.
- `MAX_AUTHOR`: Maximum length for an author's name.
- `MAX_GENRE`: Maximum length for a manga's genre.
- `MAX_MANGAS`: Maximum number of manga records.

### Functions

- `printAllMangas`: Displays all manga records.
- `addManga`: Adds a new manga record.
- `updateManga`: Updates an existing manga record.
- `deleteManga`: Deletes a manga record.
- `loadMangas`: Loads manga records from a file.
- `saveMangas`: Saves manga records to a file.
- `findMangas`: Searches for manga records by keyword.

## manga.c

`manga.c` implements the functions declared in `manga.h`. It includes operations for allocating memory for the dynamic array of mangas, adding new mangas, updating existing mangas, deleting mangas, saving the manga list to a file, and loading the manga list from a file. This file also contains the `main()` function, which serves as the entry point for the Manga Management System, providing a basic user interface for interacting with the system.

### Key Functionalities

- Dynamic memory management: Uses `realloc` for adjusting the array size when adding or deleting manga records.
- File I/O: Reads from and writes to a file named `mangas.txt` for persistent storage of manga records.
- User interaction: Provides a simple CLI for users to perform CRUD operations on manga records.

## Usage

Compile the source code with a C compiler (e.g., `gcc -o mangaSystem manga.c`) and run the compiled application. The user will be prompted with a menu of options to manage manga records:

1. Print all mangas
2. Add a new manga
3. Update an existing manga
4. Delete a manga
5. Save mangas to file
6. Find manga by keyword
7. Exit

Choose an option by entering the corresponding number. Follow the prompts to interact with the system.

## License

open-sourced software licensed under HANDONGLJH