// Example: addManga function
#include "manga.h"
#include <stdio.h>
#include <string.h>

int addManga(Manga mangas[], int count) {
  // In manga.c
  printf("Enter title: ");
  fgets(mangas[count].title, MAX_TITLE, stdin);
  // Remove newline character
  size_t len = strlen(mangas[count].title);
  if (len > 0 && mangas[count].title[len - 1] == '\n') {
    mangas[count].title[len - 1] = '\0';
  }

  // Similar for author, weeklyRank, monthlyRank, and genre
  // Increment and return new count.
  return count + 1;
}

void printAllMangas(Manga mangas[], int count) {
  printf("\nList of All Mangas:\n");
  for (int i = 0; i < count; ++i) {
    printf("%d: %s by %s, Weekly Rank: %d, Monthly Rank: %d, Genre: %s\n",
           i + 1, mangas[i].title, mangas[i].author, mangas[i].weeklyRank,
           mangas[i].monthlyRank, mangas[i].genre);
  }
}
void updateManga(Manga mangas[], int count) {
  int index;
  printf("Enter index of manga to update: ");
  scanf("%d", &index);
  index--; // Adjusting for 0-based indexing

  if (index < 0 || index >= count) {
    printf("Invalid index!\n");
    return;
  }

  printf("Enter new title: ");
  scanf("%s", mangas[index].title);
  // Repeat for author, weeklyRank, monthlyRank, and genre with appropriate
  // prompts and scanf
}
void deleteManga(Manga mangas[], int count) {
  int index;
  printf("Enter index of manga to delete: ");
  scanf("%d", &index);
  index--; // Adjust for 0-based indexing

  if (index < 0 || index >= count) {
    printf("Invalid index!\n");
    return;
  }

  for (int i = index; i < count - 1; ++i) {
    mangas[i] = mangas[i + 1];
  }

  printf("Manga deleted successfully.\n");
}

int loadMangas(Manga mangas[], const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    return 0; // File not found
  }

  int count = 0;
  while (fscanf(file, "%[^,],%[^,],%d,%d,%[^\n]\n", mangas[count].title,
                mangas[count].author, &mangas[count].weeklyRank,
                &mangas[count].monthlyRank, mangas[count].genre) == 5) {
    count++;
  }

  fclose(file);
  return count;
}

void saveMangas(Manga mangas[], int count, const char *filename) {
  // In saveMangas
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

int findMangas(Manga mangas[], int count, const char *searchKeyword) {
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
    Manga mangas[MAX_MANGAS];
    int count = loadMangas(mangas, "mangas.txt");
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
        printf("\nSelect an option: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printAllMangas(mangas, count);
                break;
            case 2:
                count = addManga(mangas, count);
                break;
            case 3:
                updateManga(mangas, count);
                break;
            case 4:
                deleteManga(mangas, count);
                count--;
                break;
            case 5:
                saveMangas(mangas, count, "mangas.txt");
                break;
            case 6: {
                char keyword[100];
                printf("Enter search keyword: ");
                scanf("%s", keyword);
                if(!findMangas(mangas, count, keyword)) {
                    printf("No records found!\n");
                }
                break;
            }
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
        // Clear input buffer
        while (getchar() != '\n');
    } while(choice != 7);
    return 0;
}
