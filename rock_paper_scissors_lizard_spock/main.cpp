#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
  srand( time(NULL));

  int number_cpu, user_points, cpu_points;
  user_points = 0;
  cpu_points = 0;
  std::string cpu_choice, user_choice;

  std::cout << "Playing Rock, Paper, Scissors, Lizard, Spock\nBest of 3:\n\n";

  while (user_points < 3 && cpu_points < 3) {
    std::cout << "Select rock, paper, scissors, lizard, or spock: (lower case) ";
    std::cin >> user_choice;

    number_cpu = rand() % 5;
    switch(number_cpu) {
      case 0 :
        cpu_choice = "rock";
        break;
      case 1 :
        cpu_choice = "paper";
        break;
      case 2 :
        cpu_choice = "scissors";
        break;
      case 3 :
        cpu_choice = "lizard";
        break;
      case 4 :
        cpu_choice = "spock";
        break;
    }
    if (user_choice == "rock") {
      if (cpu_choice == "lizard") {
        user_points ++;
        std::cout << "\nRock crushes Lizard\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "paper") {
        cpu_points ++;
        std::cout << "\nPaper covers Rock\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "scissors") {
        user_points ++;
        std::cout << "\nRock crushes Scissors\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "spock") {
        cpu_points ++;
        std::cout << "\nSpock vaporizes Rock\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else {
        std::cout << "\nRock ties with Rock\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      }
    } else if (user_choice == "paper") {
      if (cpu_choice == "scissors") {
        cpu_points ++;
        std::cout << "\nScissors cuts Paper\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "rock") {
        user_points ++;
        std::cout << "\nPaper covers Rock\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "lizard") {
        cpu_points ++;
        std::cout << "\nLizard eats Paper\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "spock") {
        user_points ++;
        std::cout << "\nPaper disproves Spock\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else {
        std::cout << "\nPaper ties with Paper\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      }
    } else if (user_choice == "scissors") {
      if (cpu_choice == "paper") {
        user_points ++;
        std::cout << "\nScissors cuts paper\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "rock") {
        cpu_points ++;
        std::cout << "\nRock crushes Scissors\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "spock") {
        cpu_points ++;
        std::cout << "\nSpock smashes Scissors\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "lizard") {
        user_points ++;
        std::cout << "\nScissors decapitate Lizard\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else {
        std::cout << "\nScissors ties with Scissors\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      }
    } else if (user_choice == "lizard") {
      if (cpu_choice == "paper") {
        user_points ++;
        std::cout << "\nLizard eats Paper\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "rock") {
        cpu_points ++;
        std::cout << "\nRock crushes lizard\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "scissors") {
        user_points ++;
        std::cout << "\nScissors decapitate Lizard\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else if (cpu_choice == "spock") {
        cpu_points ++;
        std::cout << "\nLizard poisons Spock\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      } else {
        std::cout << "\nLizard ties with Lizard\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
      }
    } else if (user_choice == "spock") {
        if (cpu_choice == "paper") {
          cpu_points ++;
          std::cout << "\nPaper disproves Spock\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
        } else if (cpu_choice == "rock") {
          user_points ++;
          std::cout << "\nSpock vaporizes Rock\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
        } else if (cpu_choice == "scissors") {
          user_points ++;
          std::cout << "\nSpock smashes scissors\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
        } else if (cpu_choice == "lizard") {
          cpu_points ++;
          std::cout << "\nLizard poisons Spock\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
        } else {
          std::cout << "\nSpock ties with Spock\nYou: " << user_points << "\nCPU: " << cpu_points << "\n";
        }
      }
    else {
      std::cout << "\nTry that again. Lowercase only.\n";
    }
  }
  if (user_points == 3) {
  std::cout << "Game Over\nYou Won!\n";
} else {
  std::cout << "Game Over\nCPU Won..\n";
}
return 0;
}
