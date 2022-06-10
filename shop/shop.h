#ifndef PROJECT_C___SHOP_H
#define PROJECT_C___SHOP_H
#include "defaultlist.h"
#include "product.h"
#include <vector>

using namespace std;

/**
 * Класс магазина
 */
class shop {
  private:
    vector<product> list; //набор продуктов в магазине
    vector<product> cart; //покупательская корзина

  public:
    void menu();
    void administrator();
    void pokupatel();
    int findproduct(int number) const;
    void insertdeflist();
    product getproductfromlist(int number) const;
    product getproductfromcart(int number) const;
    //функции администратора
    void addnewproduct();
    void addproduct(product npr);
    void deleteproduct(int number);
    void showproducts() const;
    void showproduct(int number) const;
    void editproduct(int number);
    //функции покупателя
    void showlistcart() const;
    void showinfo(int number) const;
    void addcart(int number);
    void remcart(int number);
    int countproducttocart() const;
    int calcsumm(int var);
    void buy();
};

#endif // PROJECT_C___SHOP_H
