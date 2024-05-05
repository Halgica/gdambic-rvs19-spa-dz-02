#include "Game_of_life.h"

game_of_life::game_of_life(sf::RenderWindow* window)
{
    this->window = window;
}

//bool game_of_life::slucajna_vrijednost()
//{
//    int random = 1 + rand() % (100 - 1 + 1);
//    if (random <= 25)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

bool game_of_life::celija_zauzeta(int i, int j)
{
    if (_generacija[i][j])
    {
        return true;
    }
    else
    {
        return false;
    }
}


void game_of_life::sljedeca_generacija()
{
    for (size_t i = 0; i < REDAKA; i++)
    {
        for (size_t j = 0; j < STUPACA; j++)
        {
            //provjera celija okolo celije i,j
            provjera_okolo(i, j);
        }
    }

    for (size_t i = 0; i < REDAKA; i++)
    {
        for (size_t j = 0; j < STUPACA; j++)
        {
            //nova generacija -> generacija
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
}

void game_of_life::provjera_okolo(int i, int j)
{
    int brojacZivih = 0;
    int provjeraI = i;
    int provjeraJ = j;
    //brojac zivih oko celije
    for (size_t k = provjeraI - 1; k <= provjeraI + 1; k++)
    {
        for (size_t l = provjeraJ - 1; l <= provjeraJ + 1; l++)
        {
            if (l == j && k == i)
            {
                l++;
            }
            if (_generacija[k][l])
            {
                brojacZivih++;
            }
        }
    }
    //pravila
    pravila(brojacZivih, i, j);
}

void game_of_life::pravila(int brojacZivih, int i, int j)
{
    if (brojacZivih < 2 || brojacZivih > 3)
    {
        _sljedeca_generacija[i][j] = false;
    }
    else if (brojacZivih == 3)
    {
        _sljedeca_generacija[i][j] = true;
    }
}

void game_of_life::iscrtaj()
{
    //crtanje
    float red = 0;
    float stupac = 0;
    for (size_t i = 0; i < REDAKA; i++)
    {
        for (size_t j = 0; j < STUPACA; j++)
        {
            sf::RectangleShape celija(sf::Vector2f(10.f, 10.f));
            if (_generacija[i][j])
            {
                celija.setFillColor(sf::Color(0, 255, 0));
            }
            else
            {
                celija.setFillColor(sf::Color(255, 0, 0));
            }
            celija.setPosition(stupac, red);
            window->draw(celija);
            stupac += 15;
        }
        stupac = 0;
        red += 15;
    }
}

void game_of_life::inicijalizacija()
{
    srand(time(0));
    for (size_t i = 0; i < REDAKA; i++)
    {
        for (size_t j = 0; j < STUPACA; j++)
        {
            int random = 1 + rand() % (100 - 1 + 1);
            if (random <= 25)
            {
                _generacija[i][j] = true;
            }
            else
            {
                _generacija[i][j] = false;
            }
        }
    }
}

//void game_of_life::test()
//{
//    sf::RectangleShape test(sf::Vector2f(40.f,40.f));
//    test.setFillColor(sf::Color(0,0,255));
//    window->draw(test);
//}

