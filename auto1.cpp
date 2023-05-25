#include <iostream>

#include <string>

using namespace std;

// Définition de l'automate nombre de a pair, nombre de b impair

const int taille_alphabet = 3;

const int nombre_etats = 4;

const int nombre_etats_finaux = 1;

char alphabet[] = {'a', 'b', 'c'};

int etats[] = {0, 1, 2, 3};

int etats_finaux[] = {3};

int etat_initial = 0;

// La fonction de transition

int transitions[nombre_etats][taille_alphabet];

void initialiser_fonction_transition() {

  for (int i = 0; i < nombre_etats; i++)

    for (int j = 0; j < taille_alphabet; j++)

      transitions[i][j] = -1;
  // a = 0 , b = 1 , c=2

  transitions[0][0] = 1; // a

  transitions[0][1] = 3; // b

  transitions[1][2] = 0; // c

  transitions[1][1] = 2;

  transitions[2][0] = 3;

  transitions[2][1] = 1;

  transitions[3][2] = 2;

  transitions[3][1] = 0;
}

bool est_final(int etat) {

  for (int i = 0; i < nombre_etats_finaux; i++)

    if (etats_finaux[i] == etat)

      return true;

  return false;
}

int position_alphabet(char c) {

  for (int i = 0; i < taille_alphabet; i++)

    if (alphabet[i] == c)

      return i;

  return -1; 
}

bool valider(string ch) {

  bool fin_chaine; 
  int etat_courant = etat_initial;

 

  string::iterator c_courant = ch.begin();

  fin_chaine = c_courant == ch.end();


  while (!(fin_chaine || etat_courant == -1)) {

    int p = position_alphabet(*c_courant);


    if (p == -1)

      return false;

    etat_courant = transitions[etat_courant][p];

    c_courant++;

    fin_chaine = (c_courant == ch.end());
  }

  return (fin_chaine && est_final(etat_courant));
}

int main()

{

  initialiser_fonction_transition();

  string ch;

  do {

    cout << "Chaine:";

    cin >> ch;

    if (ch == "q")

      break;

    if (valider(ch))

      cout << ch << " est valide" << endl;

    else

      cout << ch << " n'est pas valide" << endl;

  } while (ch != "q");
}
