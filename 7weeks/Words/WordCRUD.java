import java.util.ArrayList;
import java.util.Scanner;

public class WordCRUD {
  ArrayList<Word> wordList;
  Scanner scanner;

  public WordCRUD(Scanner scanner) {
    this.wordList = new ArrayList<>();
    this.scanner = scanner;
  }

  public void addWord() {
    System.out.print("Enter English word: ");
    String english = scanner.next();
    System.out.print("Enter Korean meaning: ");
    String korean = scanner.next();
    System.out.print("Enter difficulty (1~3): ");
    int difficulty = scanner.nextInt();
    Word word = new Word(english, korean, difficulty);
    wordList.add(word);
    System.out.println("Word added.");
  }

  public void listWords() {
    for (Word word : wordList) {
      System.out.println(word);
    }
  }

  public void updateWord() {
    System.out.print("Enter the English word you want to update: ");
    String english = scanner.next();
    for (Word word : wordList) {
      if (word.getEnglishWord().equalsIgnoreCase(english)) {
        System.out.print("Enter new Korean meaning: ");
        String korean = scanner.next();
        System.out.print("Enter new difficulty (1~3): ");
        int difficulty = scanner.nextInt();
        word.setKoreanMeaning(korean);
        word.setDifficulty(difficulty);
        System.out.println("Word updated.");
        return;
      }
    }
    System.out.println("Word not found.");
  }

  public void deleteWord() {
    System.out.print("Enter the English word you want to delete: ");
    String english = scanner.next();
    for (Word word : wordList) {
      if (word.getEnglishWord().equalsIgnoreCase(english)) {
        wordList.remove(word);
        System.out.println("Word deleted.");
        return;
      }
    }
    System.out.println("Word not found.");
  }
}