// parola palindrom: verificam daca un text poate fi rearanjat ca palindrom

#include <iostream>
#include <string>
#include <vector>


bool isPalindrom(const std::string& text)
{
    int dimensiune = text.size();
    int tail = dimensiune - 1;
    if (!text.empty()) //verificam sa nu fie gol sirul
    {
        for (int i = 0; i < dimensiune / 2; i++)
        {
            if (text[i] != text[tail]) return false;
            else tail--;
        }
    }
    else
    {
        std::cout << "no text error";
        return false;
    }
    return true;
}

bool canBePalindrom(const std::string& parola)
{
    std::string canBePalindrom = parola;

    //stergem spatiile
    for (int i = 0; i < canBePalindrom.size(); i++)
    {
        if (canBePalindrom[i] == ' ')
        {
            canBePalindrom.erase(i, 1);
        }
    }

    //numaram fiecare caracter
    int nrCaractere[256] = { 0 };
    for (int i = 0; canBePalindrom[i]; i++)
    {
        nrCaractere[canBePalindrom[i]]++;

        //std::cout << canBePalindrom[i] << std::endl;
        //std::cout << nrCaractere[canBePalindrom[i]] << std::endl;
        //std::cout << "count y: " << nrCaractere['y'] << std::endl;
        //std::cout << nrCaractere[i] << std::endl;
        //std::cout << " " << std::endl;
    }

    //numaram caracterele impare, pot fi max 1

    int nrCaractereImpare = 0;
    for (int i = 0; i < 256; i++) {
        if (nrCaractere[i] & 1)
            nrCaractereImpare++;

        if (nrCaractereImpare > 1)
            return false;
    }

    std::cout << "Parola fara spatii: " << canBePalindrom << std::endl;

    return true;
}

int main()
{
    //verificare palindrom ex. abba

    std::string text = "abc cba x yyy";

    //std::cout << "Introduceti un text: ";
    //std::cin >> text;
    std::cout << "Parola originala" << text << std::endl;

    std::cout << "Dimensiune text: " << text.size() << std::endl;

    if (isPalindrom(text)) std::cout << "Textul este palindrom." << std::endl;
    else std::cout << "Textul nu este palindrom." << std::endl;

    if (canBePalindrom(text)) std::cout << "Textul POATE fi rearanjat ca palindrom." << std::endl;
    else std::cout << "Textul NU POATE fi rearanjat ca palindrom." << std::endl;

    return 0;
}

