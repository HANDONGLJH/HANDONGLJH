// manga.h
#ifndef _MANGA_H
#define _MANGA_H

#define MAX_TITLE 100
#define MAX_AUTHOR 50
#define MAX_GENRE 30
#define MAX_MANGAS 100

typedef struct {
  char title[MAX_TITLE];
  char author[MAX_AUTHOR];
  int weeklyRank;
  int monthlyRank;
  
} Manga;

void printAllMangas(Manga *mangas, int count);
int addManga(Manga **mangas, int count, const char *title, const char *author,
             int weeklyRank, int monthlyRank);
void updateManga(Manga *mangas, int count);
void deleteManga(Manga *mangas, int count);
int loadMangas(Manga **mangas, const char *filename);
void saveMangas(Manga *mangas, int count, const char *filename);
int findMangas(Manga *mangas, int count, const char *searchKeyword);

#endif