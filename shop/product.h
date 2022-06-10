#ifndef PROJECT_C___PRODUCT_H
#define PROJECT_C___PRODUCT_H
#include <string>

using namespace std;

/**
 * Класс продукта
 */
class product {
  private:
    static int
        idcode; //переменная для выдачи индивидуальных код-номеров продуктам
    int code;   //код-номер продукта
    int price;  //цена продукта без скидки
    int saleprice; //цена продукта со скидкой
    string name;   //название продукта
    int kolvo;     //количество продукта в магазине

  public:
    product(int pri, string nam);
    product(string insname, int insprice, int inssaleprice, int inskolvo);
    void setPrice(int value);
    void setSaleprice(int value);
    void setName(string newname);
    void setKolvo(int value);
    [[nodiscard]] int getCode() const;
    [[nodiscard]] int getPrice() const;
    [[nodiscard]] int getSaleprice() const;
    [[nodiscard]] int getKolvo() const;
    [[nodiscard]] string getName() const;
    void retidcode();
};

#endif // PROJECT_C___PRODUCT_H
