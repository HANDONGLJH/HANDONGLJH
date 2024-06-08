#include "MyLLQueue.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void playGame(MyLLQueue<int> &queue1, MyLLQueue<int> &queue2, int numCards) {
  int score1 = 0, score2 = 0;
  int prevValue1 = 0, prevValue2 = 0;

  for (int i = 0; i < numCards; ++i) {
    int card1 = queue1.Front();
    int card2 = queue2.Front();
    queue1.dequeue();
    queue2.dequeue();

    int battleValue1 = (i == 0) ? card1 : (prevValue1 - prevValue2 - 1 + card1);
    int battleValue2 = (i == 0) ? card2 : card2;

    cout << "Round " << i + 1 << ": Player 1's card is " << card1
         << ", Player 2's card is " << card2 << endl;
    cout << "Player 1's battle value: " << battleValue1
         << ", Player 2's battle value: " << battleValue2 << endl;

    if (battleValue1 > battleValue2) {
      score1++;
      prevValue1 = battleValue1;
      prevValue2 = card2;
      cout << "Player 1 wins this round!" << endl;
    } else if (battleValue2 > battleValue1) {
      score2++;
      prevValue1 = card1;
      prevValue2 = battleValue2;
      cout << "Player 2 wins this round!" << endl;
    } else {
      prevValue1 = card1;
      prevValue2 = card2;
      cout << "This round is a draw!" << endl;
    }
    cout << "Score: Player 1 = " << score1 << ", Player 2 = " << score2 << endl
         << endl;
  }

  cout << "Final Score: Player 1 = " << score1 << ", Player 2 = " << score2
       << endl;
  if (score1 > score2) {
    cout << "Player 1 wins the game!" << endl;
  } else if (score2 > score1) {
    cout << "Player 2 wins the game!" << endl;
  } else {
    cout << "The game is a draw!" << endl;
  }
}

int main() {
  int numCards;
  string player1DeckStr, player2DeckStr;

  // Read the input
  cin >> numCards;
  cin.ignore();
  getline(cin, player1DeckStr);
  getline(cin, player2DeckStr);

  MyLLQueue<int> queue1, queue2;
  stringstream ss1(player1DeckStr), ss2(player2DeckStr);

  int card;
  // Populate the queues
  while (ss1 >> card) {
    queue1.enqueue(card);
  }
  while (ss2 >> card) {
    queue2.enqueue(card);
  }

  playGame(queue1, queue2, numCards);

  return 0;
}