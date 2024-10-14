// 1. Lotto game!

#include <iostream>
#include <random>
using namespace std;

void lotto(int a, int b, int c, int d, int e, int f);

int main() {
  int a, b, c, d, e, f;
  cout << "Guess lottery numbers: ";
  cin >> a >> b >> c >> d >> e >> f;
  lotto(a, b, c, d, e, f);

  return 0;
}

void lotto(int a, int b, int c, int d, int e, int f) {
  random_device rd;
  mt19937 gen(rd());

  int A, B, C, D, E, F, bonus;
  int match = 0;

  A = gen() % 45 + 1;

  do {
    B = gen() % 45 + 1;
  } while (A == B);

  do {
    C = gen() % 45 + 1;
  } while (C == A || C == B);

  do {
    D = gen() % 45 + 1;
  } while (D == A || D == B || D == C);

  do {
    E = gen() % 45 + 1;
  } while (E == A || E == B || E == C || E == D);

  do {
    F = gen() % 45 + 1;
  } while (F == A || F == B || F == C || F == D || F == E);

  do {
    bonus = gen() % 45 + 1;
  } while (bonus == A || bonus == B || bonus == C || bonus == D || bonus == E ||
           bonus == F);

  cout << "Number: " << A << " " << B << " " << C << " " << D << " " << E << " "
       << F << " + " << bonus << endl;

  if (a == A || a == B || a == C || a == D || a == E || a == F) match++;
  if (b == A || b == B || b == C || b == D || b == E || b == F) match++;
  if (c == A || c == B || c == C || c == D || c == E || c == F) match++;
  if (d == A || d == B || d == C || d == D || d == E || d == F) match++;
  if (e == A || e == B || e == C || e == D || e == E || e == F) match++;
  if (f == A || f == B || f == C || f == D || f == E || f == F) match++;

  string rank;
  if (match == 6)
    rank = "1st";
  else if (match == 5) {
    if (bonus == A || bonus == B || bonus == C || bonus == D || bonus == E ||
        bonus == F) {
      match++;
      rank = "2nd";
    } else
      rank = "3rd";
  } else if (match == 4)
    rank = "4th";
  else if (match == 3)
    rank = "5th";
  else
    rank = "no";
  cout << "You match " << match << " numbers! You are in " << rank << " place!";
}