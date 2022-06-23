#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
// the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

using namespace std;
//string nom(string nombre );

char keypress() {
    system("/bin/stty raw");
    char c;
    system("/bin/stty -echo");
    c = getc(stdin);
    system("/bin/stty echo");
    system("/bin/stty cooked");
    return c;
}

class Worm {
    int size;       /* tamanio del worm */
    int apple;      /* index del apple (definido) */
    int head;       /* index del head (definido) */
    int x;          /* pos x de vista del head */
    int y;          /* pos y de vista del head */
    int xo;         /* pos x de vista del apple */
    int yo;         /* pos y de vista del apple */
    int score;      /* puntaje */
    vector<int> body;

  public:
    Worm(int _size = 1) {
        score = 0;
        size  = _size;
        // el worm inicia en (1,1)
        x     = 1;
        y     = 1;
        // posiciones random de worm y apple inciales
        xo    = rand() % 78;
        yo    = rand() % 21;
        // ubicacion de vista del worm y apple
        head  = x + 80 * (y - 1);
        apple = xo + 80 * (yo - 1);
        // incluyendo el cuerpo del worm (empty)
        body.push_back(head);
    }

    void update() {
        char c = keypress();        // tecla input
        switch (c) {
            case 'w':
                y = max(1, y - 1);  // subir worm con index limite 1
                break;
            case 's':
                y = min(22, y + 1); // bajar worm con index limite 22
                break;
            case 'a':
                x = max(1, x - 1);  // izquierda worm con index limite 1
                break;
            case 'd':
                x = min(79, x + 1); // derecha worm con index limite 79
                break;
            case 'q':
                exit(0);            // salir del juego
                break;
            default:
                break;
        }
        head = x + 80 * (y - 1); // actualiza el index visual de worm

        // si las posiciones de head y apple son iguales, el puntaje aumenta
        if (head == apple) {
            score += 1;

            // Nueva posicion random del apple
            xo    = rand() % 78 + 1;
            yo    = rand() % 21 + 1;
            apple = xo + 80 * (yo - 1);
        }
    }

    void render(string &env) {
        // state = x + 80*(y-1);
        // asigna un worm y un apple
        env[head]  = '@';
        env[apple] = 'o';

        // Colorear el worm y el apple e imprime la pantalla en vacio
        for (int k = 0; k < 1761; k++) {
            if (k == head) {
                cout << CYAN;
                cout << (k % 80 ? env[k] : char(10));
                cout << BLACK;
            } else if (k == apple) {
                cout << RED;
                cout << (k % 80 ? env[k] : char(10));
                cout << BLACK;
            } else {
                cout << (k % 80 ? env[k] : char(10));
            }
        }
    }
    // getters de la posicion del head de worm
    int get_x() { return x; }
    int get_y() { return y; }
    // getters de index visual de apple y puntaje
    int get_apple() { return apple; }
    int get_score() { return score; }
};

// empty
bool welcome(string &env) {
    bool start = false;
    while (!start) {
        // welcome(env);
        env.insert(800, "Welcome");
        start = true;
    }
    // show menu
    char c  = keypress();
    int num = 0;
    switch (c) {
    case KEY_DOWN:
        num += 1;
        break;
    case KEY_UP:
        num -= 1;
        break;
    default:
        break;
    }
    return start;
}

// empty
void gameover(string &env, Worm worm) {
    // system("cls");
    cout << " GAME OVER " << endl;
    cout << "Score: " << worm.get_score() << endl;
}


int main() {

	// env del juego vacio
    string env(1760, '.');
    // pantalla de score inicial
    string score(200, ' ');

    Worm worm;
    cout << "\x1b[2J"; // test on console cling
    cout << "\x1b[H"; // test on console cling -> cout << "\x1b[2J" << "\x1b[H";
                      // // test on cling !
    // define clear cout << "\x1b[2J" << "\x1b[H";   // on cling

    worm.render(env);
    for (;;) {
        // reasigna el score y env del juego iniciales
        score.assign(200, ' ');
        env.assign(1760, '.'); // '.'
        // actualiza los ejes de posicion despues de una tecla
        worm.update();
        cout << "\x1b[H";
        // imprime la pantalla con el worm y apple
        worm.render(env);
        string pos = to_string(worm.get_x()) + "," + to_string(worm.get_y());
        score.replace(0, pos.size(), pos);
        cout << RED;
        cout << score[0];
        for (int i = 1; i < score.size(); i++) {
            cout << ((i % 80) ? score[i] : char(10));
        }
        cout << WHITE << endl;
        cout << "┏───────────┓" << endl;
        cout << "│ life:   3 │" << endl;
        cout << "│ score: 25 │" << worm.get_score() << endl;
        cout << "└───────────┛" << endl;
        cout << BLACK << endl;
    }
    return 0;
}



       // cout << "┏─────────────────────┓" << endl;
      //  cout << "│   WECOLME UTECGAME  │" << endl;
       // cout << "│  Enter name : "<<nombre << "│"<<endl;
	     // cout << "│    Pres [ENTER] :   │" << endl;
       // cout << "└─────────────────────┛" << endl;
