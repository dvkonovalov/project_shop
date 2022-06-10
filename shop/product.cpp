#include "product.h"

#include <utility>

using namespace std;

//Задаем переменной для выдачи индивудальных код-номеров начальное значение
int product::idcode = 1;

/**
 * Функция получения кода продукта
 * @return код продукта
 */
int product::getCode() const { return code; }

/**
 * Функция получения название продукта
 * @return название продукта
 */
string product::getName() const { return name; }

/**
 * Функция получения цены продукта без скидки
 * @return цена продукта без скидки
 */
int product::getPrice() const { return price; }

/**
 * Функция получения количества продукта в магазине
 * @return количесвто продукта
 */
int product::getKolvo() const { return kolvo; }

/**
 * Функция получения цены продукта со скидкой
 * @return цена продукта со скидкой
 */
int product::getSaleprice() const { return saleprice; }

/**
 * Функция для изменения количества продукта в магазине
 * @param value новое количество продукта
 */
void product::setKolvo(int value) { kolvo = value; }

/**
 * Функция для изменения названия продукта
 * @param newname новое название
 */
void product::setName(string newname) { name = newname; }

/**
 * Функция для изменения цены продукта со скидкой
 * @param value новая цена со скидкой
 */
void product::setSaleprice(int value) { saleprice = value; }

/**
 * Функция для изменения цены продукта.
 * Если цена будет меньше цены со скидкой, то цена со скидкой изменится на
 * обычную цену
 * @param value новая цена
 */
void product::setPrice(int value) {
    if (saleprice < value)
        saleprice = value;
    price = value;
}

/**
 * Конструктор продукта с параметрами названия и цены
 * @param pri цена продукта
 * @param nam название продукта
 */
product::product(int pri, string nam)
    : code(idcode), price(pri), saleprice(pri), name(std::move(nam)), kolvo(1) {

    idcode++;
}

/**
 * Конструктор продукта со всеми заданными параметрами
 * @param insname название продукта
 * @param insprice цена продукта
 * @param inssaleprice цена продукта со скидкой
 * @param inskolvo количество продукта в магазине
 */
product::product(string insname, int insprice, int inssaleprice, int inskolvo)
    : code(idcode), price(insprice), saleprice(inssaleprice), name(insname),
      kolvo(inskolvo) {
    idcode++;
}
/**
 * Функция для возвращения переменной выдачи кодов новым продукам
 * к начальному значению(Используется только для тестирования!!!)
 */
void product::retidcode() { idcode = 1; }
