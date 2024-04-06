#include "manga.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addManga(Manga **mangas, int count, const char *title, const char *author,
             int weeklyRank, int monthlyRank) {
  if (count >= MAX_MANGAS) {
    printf("Maximum number of mangas reached.\n");
    return count;
  }

  *mangas = realloc(*mangas, (count + 1) * sizeof(Manga));
  if (!*mangas) {
    perror("Failed to reallocate memory");
    exit(EXIT_FAILURE);
  }

  // Copying the provided data into the new manga record
  strncpy((*mangas)[count].title, title, MAX_TITLE);
  (*mangas)[count].title[MAX_TITLE - 1] = '\0'; // Ensure null-termination

  strncpy((*mangas)[count].author, author, MAX_AUTHOR);
  (*mangas)[count].author[MAX_AUTHOR - 1] = '\0'; // Ensure null-termination

  (*mangas)[count].weeklyRank = weeklyRank;
  (*mangas)[count].monthlyRank = monthlyRank;

  count++;

  return count;
}

void printAllMangas(Manga *mangas, int count) {
  printf("\nList of All Mangas:\n");
  for (int i = 0; i < count; ++i) {
    printf("%d: %s by %s, Weekly Rank: %d, Monthly Rank: %d, \n", i + 1,
           mangas[i].title, mangas[i].author, mangas[i].weeklyRank,
           mangas[i].monthlyRank);
  }
}

void updateManga(Manga *mangas, int count) {
  int index;
  printf("Enter index of manga to update: ");
  scanf("%d", &index);
  index--;

  if (index < 0 || index >= count) {
    printf("Invalid index!\n");
    return;
  }

  while (getchar() != '\n')
    ;

  printf("Enter new title: ");
  fgets(mangas[index].title, MAX_TITLE, stdin);
  size_t len = strlen(mangas[index].title);
  if (len > 0 && mangas[index].title[len - 1] == '\n') {
    mangas[index].title[len - 1] = '\0';
  }

  printf("Enter new author: ");
  fgets(mangas[index].author, MAX_AUTHOR, stdin);
  len = strlen(mangas[index].author);
  if (len > 0 && mangas[index].author[len - 1] == '\n') {
    mangas[index].author[len - 1] = '\0';
  }

  printf("Enter new weekly rank: ");
  scanf("%d", &mangas[index].weeklyRank);
  while (getchar() != '\n')
    ;

  printf("Enter new monthly rank: ");
  scanf("%d", &mangas[index].monthlyRank);
  while (getchar() != '\n')
    ;

  printf("Manga updated successfully.\n");
}

void deleteManga(Manga *mangas, int count) {
  int index;
  printf("Enter index of manga to delete: ");
  scanf("%d", &index);
  index--;

  if (index < 0 || index >= count) {
    printf("Invalid index!\n");
    return;
  }

  for (int i = index; i < count - 1; ++i) {
    mangas[i] = mangas[i + 1];
  }

  printf("Manga deleted successfully.\n");
}

int loadMangas(Manga **mangas, const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Failed to open file for reading");
    return 0;
  }

  *mangas = realloc(*mangas, MAX_MANGAS * sizeof(Manga));
  if (!*mangas) {
    perror("Failed to allocate memory");
    fclose(file);
    exit(EXIT_FAILURE);
  }

  int count = 0;
  while (fscanf(file, "%[^,],%[^,],%d,%d\n", (*mangas)[count].title,
                (*mangas)[count].author, &(*mangas)[count].weeklyRank,
                &(*mangas)[count].monthlyRank) == 5) {
    count++;
    if (count >= MAX_MANGAS)
      break;
  }

  fclose(file);
  return count;
}

void saveMangas(Manga *mangas, int count, const char *filename) {
  FILE *file = fopen(filename, "w");
  if (!file) {
    perror("Failed to open file for writing");
    return;
  }

  for (int i = 0; i < count; ++i) {
    fprintf(file, "%s,%s,%d,%d\n", mangas[i].title, mangas[i].author,
            mangas[i].weeklyRank, mangas[i].monthlyRank);
  }

  fclose(file);
}

int findMangas(Manga *mangas, int count, const char *searchKeyword) {
  printf("\nSearch results for '%s':\n", searchKeyword);
  int foundCount = 0;
  for (int i = 0; i < count; ++i) {
    if (strstr(mangas[i].title, searchKeyword) ||
        strstr(mangas[i].author, searchKeyword)) {
      printf("%d: %s by %s, Weekly Rank: %d, Monthly Rank: %d, \n", i + 1,
             mangas[i].title, mangas[i].author, mangas[i].weeklyRank,
             mangas[i].monthlyRank);
      foundCount++;
    }
  }
  return foundCount;
}

int main() {
  Manga *mangas = NULL; // Declare a pointer to dynamic array of Manga
  int count = loadMangas(&mangas, "mangas.txt"); // Load initial data from file

  int choice;
  do {
    printf("\n===== Manga Management Menu =====\n");
    printf("1. Print all Mangas\n");
    printf("2. Add Manga\n");
    printf("3. Update Manga\n");
    printf("4. Delete Manga\n");
    printf("5. Save Mangas\n");
    printf("6. Find Manga\n");
    printf("7. Exit\n");
    printf("Select an option: ");
    scanf("%d", &choice);
    // Clear input buffer after scanf to ensure it works correctly with fgets
    while (getchar() != '\n')
      ;

    switch (choice) {
    case 1:
      printAllMangas(mangas, count);
      break;
    case 2: {
      char title[MAX_TITLE], author[MAX_AUTHOR];
      int weeklyRank, monthlyRank;

      printf("Enter manga title: ");
      fgets(title, MAX_TITLE, stdin);
      size_t len = strlen(title);
      if (len > 0 && title[len - 1] == '\n') {
        title[len - 1] = '\0';
      }

      printf("Enter manga author: ");
      fgets(author, MAX_AUTHOR, stdin);
      len = strlen(author);
      if (len > 0 && author[len - 1] == '\n') {
        author[len - 1] = '\0';
      }

      printf("Enter weekly rank: ");
      scanf("%d", &weeklyRank);
      while (getchar() != '\n')
        ;

      printf("Enter monthly rank: ");
      scanf("%d", &monthlyRank);
      while (getchar() != '\n')
        ;

      count = addManga(&mangas, count, title, author, weeklyRank, monthlyRank);
      break;
    }
    case 3:
      updateManga(mangas, count);
      break;
    case 4:
      deleteManga(mangas, count);
      count--; // Update count after deletion
      break;
    case 5:
      saveMangas(mangas, count, "mangas.txt");
      break;
    case 6: {
      char keyword[100];
      printf("Enter search keyword: ");
      fgets(keyword, 100, stdin);
      size_t len = strlen(keyword);
      if (len > 0 && keyword[len - 1] == '\n') {
        keyword[len - 1] = '\0';
      }
      findMangas(mangas, count, keyword);
      break;
    }
    case 7:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid option! Please try again.\n");
    }
  } while (choice != 7);

  free(mangas); // Free the allocated memory for mangas before exiting
  return 0;
}