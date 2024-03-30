#include "manga.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addManga(Manga **mangas, int count) {
  if (count >= MAX_MANGAS) {
    printf("Maximum number of mangas reached.\n");
    return count;
  }

  *mangas = realloc(*mangas, (count + 1) * sizeof(Manga));
  if (!*mangas) {
    perror("Failed to reallocate memory");
    exit(EXIT_FAILURE);
  }

  printf("Enter title: ");
  fgets((*mangas)[count].title, MAX_TITLE, stdin);
  size_t len = strlen((*mangas)[count].title);
  if (len > 0 && (*mangas)[count].title[len - 1] == '\n') {
    (*mangas)[count].title[len - 1] = '\0';
  }
  // Handle inputs for author, weeklyRank, monthlyRank, and genre similarly

  saveMangas(*mangas, count + 1, "mangas.txt");
  return count + 1;
}

void printAllMangas(Manga *mangas, int count) {
  printf("\nList of All Mangas:\n");
  for (int i = 0; i < count; ++i) {
    printf("%d: %s by %s, Weekly Rank: %d, Monthly Rank: %d, Genre: %s\n",
           i + 1, mangas[i].title, mangas[i].author, mangas[i].weeklyRank,
           mangas[i].monthlyRank, mangas[i].genre);
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
  // Repeat for other attributes

  saveMangas(mangas, count, "mangas.txt");
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
  saveMangas(mangas, count - 1, "mangas.txt");
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
  while (fscanf(file, "%[^,],%[^,],%d,%d,%[^\n]\n", (*mangas)[count].title,
                (*mangas)[count].author, &(*mangas)[count].weeklyRank,
                &(*mangas)[count].monthlyRank, (*mangas)[count].genre) == 5) {
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
    fprintf(file, "%s,%s,%d,%d,%s\n", mangas[i].title, mangas[i].author,
            mangas[i].weeklyRank, mangas[i].monthlyRank, mangas[i].genre);
  }

  fclose(file);
}

int findMangas(Manga *mangas, int count, const char *searchKeyword) {
  printf("\nSearch results for '%s':\n", searchKeyword);
  int foundCount = 0;
  for (int i = 0; i < count; ++i) {
    if (strstr(mangas[i].title, searchKeyword) ||
        strstr(mangas[i].author, searchKeyword) ||
        strstr(mangas[i].genre, searchKeyword)) {
      printf("%d: %s by %s, Weekly Rank: %d, Monthly Rank: %d, Genre: %s\n",
             i + 1, mangas[i].title, mangas[i].author, mangas[i].weeklyRank,
             mangas[i].monthlyRank, mangas[i].genre);
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
    case 2:
      mangas = realloc(mangas,
                       (count + 1) * sizeof(Manga)); // Reallocate for new manga
      count = addManga(&mangas, count);
      break;
    case 3:
      updateManga(mangas, count);
      break;
    case 4:
      deleteManga(mangas, count);
      count--; // Update count after deletion
      mangas = realloc(
          mangas,
          count *
              sizeof(Manga)); // Reallocate to shrink the array after deletion
      break;
    case 5:
      saveMangas(mangas, count, "mangas.txt");
      break;
    case 6: {
      char keyword[100];
      printf("Enter search keyword: ");
      fgets(keyword, 100, stdin);
      // Remove newline character from fgets
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

  free(mangas); // Free the dynamic array before exiting
  return 0;
}