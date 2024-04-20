
public class MyString {
  public static int whichFirst(String str1, String str2) {
    return str1.toLowerCase().compareTo(str2.toLowerCase());
  }

  public static String removeSpaces(String str) {
    return str.replaceAll("\\s+", "");
  }

  public static String findLongestWord(String str) {
    String[] words = str.split("\\s+");
    String longestWord = "";
    for (String word : words) {
      if (word.length() > longestWord.length()) {
        longestWord = word;
      }
    }
    return longestWord;
  }

}
