#ifndef PROJECT_C___DEFAULTLIST_H
#define PROJECT_C___DEFAULTLIST_H
#include "product.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Класс стандартного набора продуктов магазина
 */
class defaultlist {
  private:
    vector<product> deflist; //вектор продуктов
    int kolvo = 0;

  public:
    defaultlist();
    [[nodiscard]] vector<product> getlist() const;
    friend bool operator==(product x, product y);
    friend bool operator!=(product x, product y);
    void loadproduct(const string &pathfile);
    int getsize() const;
    ~defaultlist() { std::cout << "Default list reload to list shop \n\n\n"; };
};
#endif
