#include <iostream>
#include <random>
#include "Random.h"
using namespace std;

int main() {
    int minin, maxin, number;
    short int guessin;
    random_device r1;
    bool game = true;

    cout << "Gra w zgadywanie liczby! " << endl;

    while (true) {
        Random* r = nullptr;
        while (true) {
            try {
                cout << "Wpisz odpowiednio liczbe minimalna, maksymalna i ilosc prob" << endl;
                cout << "[min] [max] [guess]" << endl;
                cin >> minin >> maxin >> guessin;
                r = new Random(minin, maxin, guessin);
                cout << endl;
                break;
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
            catch (int) {
                cout << "Liczba prob musi wynosic przynajmniej 1!" << endl;
            }
            catch (const char* e) {
                cout << e << endl;
            }
        }

        uniform_int_distribution<int> dist(minin, maxin);
        r->set_guess(dist(r1));

        cout << "Wpisz liczbe: " << endl;
        cin >> number;

        short int tries = 0;
        bool won = false;

        while (game) {
            tries++;
            if (number > r->get_guess()) {
                cout << "Liczba jest za duza!" << endl;
            }
            else if (number < r->get_guess()) {
                cout << "Liczba jest za mala!" << endl;
            }
            else if (guessin <= tries) {
                cout << "Przekroczono liczbe prob!" << endl;
                break;
            }
            else {
                cout << "Wygrales!" << endl;
                won = true;
                break;
            }
            if (game) {
                cout << "Wpisz liczbe: " << endl;
                cin >> number;
            }
        }

        delete r;

        cout << "Czy chcesz zagrać jeszcze raz? (tak/nie): ";
        string response;
        cin >> response;
        if (response != "tak") {
            break;
        }
    }

    return 0;
}
