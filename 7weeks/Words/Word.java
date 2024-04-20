public class Word {
  private String englishWord;
  private String koreanMeaning;
  private int difficulty;

  // Constructor
  public Word(String englishWord, String koreanMeaning, int difficulty) {
    this.englishWord = englishWord;
    this.koreanMeaning = koreanMeaning;
    this.difficulty = difficulty;
  }

  // Getters and Setters
  public String getEnglishWord() {
    return englishWord;
  }

  public void setEnglishWord(String englishWord) {
    this.englishWord = englishWord;
  }

  public String getKoreanMeaning() {
    return koreanMeaning;
  }

  public void setKoreanMeaning(String koreanMeaning) {
    this.koreanMeaning = koreanMeaning;
  }

  public int getDifficulty() {
    return difficulty;
  }

  public void setDifficulty(int difficulty) {
    this.difficulty = difficulty;
  }

  // toString override
  @Override
  public String toString() {
    return "Word{" +
        "englishWord='" + englishWord + '\'' +
        ", koreanMeaning='" + koreanMeaning + '\'' +
        ", difficulty=" + difficulty +
        '}';
  }
}