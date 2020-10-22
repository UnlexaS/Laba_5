// Laba_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

class Mebel {

protected:
    int price;
    string material;

public:

    virtual void priceindollars() = 0;

    virtual void print() = 0;


    Mebel() {
        this->price = 0;
        this->material = ' ';
    }

    Mebel(int price1, string material1) : price(price1), material(material1) {

    }

    void setprice(int price1) {
        price = price1;
    }

    void setmaterial(string material1) {
        material = material1;
    }

    virtual ~Mebel() {
        cout << "Destructor" << endl;
    }
};

class streetmebel : public Mebel {

protected:

    string tipystanovki;
    string color;

public:

    streetmebel() : Mebel() {
        this->tipystanovki = ' ';
        this->color = ' ';
    }

    streetmebel(string tipystanovki1, string color1, int price1, string material1) : Mebel(price, material), tipystanovki(tipystanovki1), color(color1) {

    }

    ~streetmebel() {}

    void priceindollars() override {
        int price2 = price * 2.55;
        cout << "Цена в $ = " << price2;
    }

    void settipystanovki(string tipystanovki1) {
        tipystanovki = tipystanovki1;
    }
        
    void setcolor(string color1) {
        color = color1;
    }

    void print() override {
        cout << endl;
        cout << "Тип установки: " << this->tipystanovki << endl;
        cout << "Цвет: " << this->color << endl;
        cout << "Цена :" << price << endl;
        cout << "Материал :" << material << endl;
    }
};

class roommebel : public Mebel {

protected:

    int dlina;
    int shirina;

public:

    roommebel() : Mebel() {
        this->dlina = 0;
        this->shirina = 0;
    }

    roommebel(double dlina1, double shirina1, int price, string material) : Mebel(price, material), dlina(dlina1), shirina(shirina1) {

    }

    ~roommebel() {}

    void priceindollars() override {
        int price2 = price * 2.55;
        cout << "Цена в $ = "<< price2;
    }

    void setdlina(int dlina1) {
        dlina = dlina1;
    }

    void setshirina(int shirina1) {
        shirina = shirina1;
    }

    void print() override {
        cout << endl;
        cout << "Длина: " << dlina << endl;
        cout << "Ширина: " << shirina << endl;
        cout << "Цена :" << price << endl;
        cout << "Материал :" << material << endl;
    }

};


class bed : public roommebel {

protected:

    int spalnmesta;
    string obshivka;

public:

    bed() : roommebel() {
        this->spalnmesta = 0;
        this->obshivka = ' ';
    }

    bed(int spalnmesta1, string obshivka1, int price, string material, int dlina, int shirina) : roommebel(dlina, shirina, price, material), spalnmesta(spalnmesta1), obshivka(obshivka1) {

    }

    ~bed() {}

    void priceindollars() override {
        int price2 = price * 2.55;
        cout << "Цена в $ = " << price2;
    }

    void setspalnmesta(int spalnmesta1) {
        spalnmesta = spalnmesta1;
    }

    void setobshivka(string obshivka1) {
        obshivka = obshivka1;
    }

    void print() override {
        cout << endl;
        cout << "кол-во спальных мест:" << spalnmesta << endl;
        cout << "Обшивка :" << obshivka << endl;
        cout << "Цена :" << price << endl;
        cout << "Материал :" << material << endl;
        cout << "Длина: " << dlina << endl;
        cout << "Ширина: " << shirina << endl;
    }
};

int check_int()
{
    while (true)
    {
        int a;
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Повторите попытку: ";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return a;
        }
    }
}

string check_string(string s)
{
    int i = 0;
    string str;
    while (s[i])
    {
        if ((s[i] >= 97) && (s[i] <= 122))
            str = str + s[i];
        else
        {
            cout << "Повторите попытку : ";
            cin >> s;
            return check_string(s);
        }
        i++;
    }
    return str;
}

void setmebel(Mebel& mebel1) {
    int price1;
    cout << "Цена : ";
    price1 = check_int();
    mebel1.setprice(price1);
    string material1;
    cout << "Материал : ";
    cin >> material1;
    check_string(material1);
    mebel1.setmaterial(material1);
}

void setstreetmebel(streetmebel& streetmebel1) {
    setmebel(streetmebel1);
    string tipystanovki1;
    cout << "Тип установки : ";
    cin >> tipystanovki1;
    check_string(tipystanovki1);
    streetmebel1.settipystanovki(tipystanovki1);
    string color1;
    cout << "Цвет : ";
    cin >> color1;
    check_string(color1);
    streetmebel1.setcolor(color1);
}

void setroommebel(roommebel& roommebel1) {
    setmebel(roommebel1);
    int dlina1;
    cout << "Длина : ";
    dlina1 = check_int();
    roommebel1.setdlina(dlina1);
    int shirina1;
    cout << "Ширина : ";
    shirina1 = check_int();
    roommebel1.setshirina(shirina1);
}

void setbed(bed& bed1) {
    setroommebel(bed1);
    int spalnmesta1;
    cout << "Спальные места : ";
    spalnmesta1 = check_int();
    bed1.setspalnmesta(spalnmesta1);
    string obshivka1;
    cout << "Обшивка : ";
    cin >> obshivka1;
    check_string(obshivka1);
    bed1.setobshivka(obshivka1);
}

int main()
{
    setlocale(LC_ALL, "Russian");


    string tipystanovki1; int ves1 = 0; int dlina1 = 0; int shirina1 = 0; int spalnmesta;
    string obshivka; string tipystanovki;
    string color;

    streetmebel* ptrstreetmebel = new streetmebel[2];
    roommebel* ptrroommebel = new roommebel[2];
    bed* ptrbed = new bed[2];
    Mebel* mebel;

    for (int i = 0; i < 2; i++)
    {
        cout << endl << "-----" << endl;
        setroommebel(ptrroommebel[i]);
        mebel = &ptrroommebel[i];
        mebel->print();
        mebel->priceindollars();
    }
    cout << endl << "----------------------" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << endl << "-----" << endl;
        setstreetmebel(ptrstreetmebel[i]);
        mebel = &ptrstreetmebel[i];
        mebel->print();
        mebel->priceindollars();
    }
    cout << endl << "----------------------" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << endl << "-----" << endl;
        setbed(ptrbed[i]);
        mebel = &ptrbed[i];
        mebel->print();
        mebel->priceindollars();
    }
    cout << endl << "----------------------" << endl;
    cout << endl;

    system("pause");



}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
