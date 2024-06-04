#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

enum ASCII {
  zero = 48,
  two = 50,
};

enum EXITCODES { success = 0, terminate = 1, invalid = 2 };

int handleInput(int *input) {
  fflush(stdin);
  char in = getchar();
  if (in == 'q') {
    return terminate;
  }
  if (in < zero || in > two) {
    return invalid;
  }
  *input = strtol(&in, NULL, 10);
  return success;
}

void evaluateGame(int user, int comp) {
  int winMatrix[3][3] = {{0, -1, 1}, {1, 0, -1}, {-1, 1, 0}};
  int endState = winMatrix[comp][user];
  if (endState == -1) {
    printf("Human won!");
  } else if (endState == 0) {
    printf("Tie!");
  } else {
    printf("Computer won!");
  }
}

int main() {
  bool end = false;
  srand(time(NULL));

  printf("Welcome to Rock-Paper-Scissors! Enter 'q' at any time to exit.\n\n");

  while (!end) {
    printf(
        "Please enter one of the below:\n0: Rock\n1: Paper\n2: Scissors\n\n");

    int input;
    int inputState = handleInput(&input);
    if (inputState == terminate) {
      printf("Terminating now.\n");
      end = true;
      continue;
    } else if (inputState == invalid) {
      printf("Invalid input.\n");
      continue;
    };

    int answer = round(rand() % 3);

    printf("Human played %i and Computer played %i.\n\n", input, answer);

    evaluateGame(input, answer);

    printf("\n\nEnter anything except 'q' to continue, enter 'q' to exit\n\n");

    if (handleInput(&input) == terminate) {
      end = true;
      printf("Terminating now.\n");
    };
  }
}
