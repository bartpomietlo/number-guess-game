#include "Random.h"
#include <stdexcept>

void value_check(long long int minf, long long int maxf, short int triesf) {
    if (minf >= maxf) {
        throw std::invalid_argument("Niepoprawna wartosc! Minimalna liczba musi byc mniejsza od maksymalnej!");
    }
    else if (triesf < 1) {
        throw 1;
    }
}

Random::Random() : min_{ 0 }, max_{ 100 }, guess_{ 0 }, tries_{ 10 } {}

Random::Random(long long int max) : min_{ 0 }, max_{ max }, guess_{ 0 }, tries_{ 10 } {
    value_check(0, max, 10);
}

Random::Random(long long int min, long long int max) : min_{ min }, max_{ max }, guess_{ 0 }, tries_{ 10 } {
    value_check(min, max, 10);
}

Random::Random(long long int min, long long int max, short int tries) : min_{ min }, max_{ max }, guess_{ 0 }, tries_{ tries } {
    value_check(min, max, tries);
}

void Random::print() const {
    cout << "Zakres: [" << min_ << ", " << max_ << "], Proby: " << tries_ << endl;
}

void Random::set_guess(long long int g) {
    if (g >= min_ && g <= max_) {
        guess_ = g;
    }
    else {
        throw "Zgadywana liczba nie miesci siê w zakresie!";
    }
}

long long int Random::get_guess() const {
    return guess_;
}