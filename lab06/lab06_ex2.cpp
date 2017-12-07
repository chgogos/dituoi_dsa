#include <iostream>
#include <queue>
#include <random>
#include <string>
#define N 10
#define TOP 3

using namespace std;
struct player {
  string name;
  int score;
  bool operator<(const player &other) const { return score < other.score; }
};

int main() {
  mt19937 mt(1821);
  uniform_int_distribution<int> dist(0, 50000);
  priority_queue<player> pq;
  int best_score = -1;
  for (int i = 0; i < N; i++) {
    player p;
    p.name = "player" + to_string(i + 1);
    p.score = dist(mt);
    pq.push(p);
    player top_player = pq.top();
    if (top_player.score != best_score)
      best_score = top_player.score;
    cout << "New player: " << p.name << " with score " << p.score << " best["
         << top_player.name << " score " << top_player.score << "]" << endl;
  }
  cout << "Top " << TOP << " players:" << endl;
  for (int i = 0; i < TOP; i++) {
    player p = pq.top();
    cout << i + 1 << " " << p.name << " " << p.score << endl;
    pq.pop();
  }
}