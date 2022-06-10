#include "defaultlist.h"
#include "product.h"
#include <fstream>

using namespace std;

/**
 * Функция для загрузки в дефолтный лист списка стандартных продуктов из csv
 * файла
 * @param pathfile Путь к csv файлу
 */
void defaultlist::loadproduct(const string &pathfile) {
    ifstream rfile(pathfile);
    if (!rfile.is_open())
        cout << "ERROR of open file csv \n";
    string name;
    string ssalepr;
    string spr;
    string rkolvo;
    getline(rfile, name, '\n');
    getline(rfile, name, ';');
    getline(rfile, spr, ';');
    getline(rfile, ssalepr, ';');
    getline(rfile, rkolvo, '\n');
    int trprice = 0;
    int trsalepr = 0;
    int trkolvo = 0;
    while (rfile.good()) {
        trkolvo = stoi(rkolvo);
        trprice = stoi(spr);
        trsalepr = stoi(ssalepr);
        deflist.emplace_back(name, trprice, trsalepr, trkolvo);
        kolvo++;
        getline(rfile, name, ';');
        getline(rfile, spr, ';');
        getline(rfile, ssalepr, ';');
        getline(rfile, rkolvo, '\n');
    }
}

/**
 * Конструктор для создания дефолтного листа под продукты
 */
defaultlist::defaultlist() { deflist = vector<product>(); }

/**
 * Функция для получения вектора с стандартным набором продуктов для магазина
 * @return Вектор с продуктами
 */
vector<product> defaultlist::getlist() const { return deflist; }
/**
 * Оператор для сравнения двух продуктов(не сравниваются коды)
 * @param x Первый продукт
 * @param y Второй продукт
 * @return Истинна если продукты одинаковые, ложе если разные
 */
bool operator==(product x, product y) {
    bool answer = true;
    if (x.getKolvo() != y.getKolvo()) {
        answer = false;
    }
    if (x.getPrice() != y.getPrice()) {
        answer = false;
    }
    if (x.getSaleprice() != y.getSaleprice()) {
        answer = false;
    }
    if (x.getName() != y.getName()) {
        answer = false;
    }
    return answer;
}

/**
 * Получить размер стандартного вектора с продуктами
 * @return Значения длины вектора
 */
int defaultlist::getsize() const { return kolvo; }
/**
 * Функция проверки неравенства двух продуктов
 * @param x Первый продукт
 * @param y Второй продукт
 * @return Истинна если продукты разные, ложе если продукты одиннаковые
 */
bool operator!=(product x, product y) { return !(x == y); }
