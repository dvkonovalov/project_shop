#include "shop.h"
#include <iostream>

using namespace std;

/**
 * Функция открытия главного меню магазина
 */
void shop::menu() {
    int choice = 0;
    cout << "................................\n";
    cout << "\t 1)Administrator\n";
    cout << "\t 2)Pokupatel\n";
    cout << "\t 3)Add default list(add for project) \n";
    cout << "\t 4)Exit\n";
    cout << "................................\n";
    cin >> choice;
    switch (choice) {
    case 1: {
        string login;
        string password;
        cout << "Input your login and password\n";
        cout << "Login:";
        cin >> login;
        cout << "Password:";
        cin >> password;
        cout << "\n";
        if (login == "admin" && password == "xxXX1234") {
            administrator();
        } else {
            cout << "!!!!!Invalid login or password!!!!!\n\n";
            menu();
        }
        break;
    }
    case 2: {
        pokupatel();
        break;
    }
    case 3: {
        insertdeflist();
        break;
    }
    case 4: {
        return;
    }
    }
    if (choice != 4)
        menu();
}

/**
 * Функция открытия меню администратора с выбором функций из функционала
 * администратора
 */
void shop::administrator() {
    int choice = 0;
    cout << "\n\n\n";
    cout << ".......................................\n";
    cout << "Command:\n";
    cout << "\t 1)Add new product\n";
    cout << "\t 2)Show all list products\n";
    cout << "\t 3)Show information about one product\n";
    cout << "\t 4)Edit information about product\n";
    cout << "\t 5)Delete product\n";
    cout << "\t 6)Exit\n";
    cout << ".......................................\n";
    cin >> choice;
    switch (choice) {
    case 1: {
        addnewproduct();
        break;
    }
    case 2: {
        showproducts();
        break;
    }
    case 3: {
        int number = 0;
        cout << "Enter code the product - ";
        cin >> number;
        cout << "\n";
        showproduct(number);
        break;
    }
    case 4: {
        int num = 0;
        cout << "What product do you want to correct? (Enter your code)";
        cin >> num;
        cout << "\n";
        editproduct(num);
        break;
    }
    case 5: {
        cout << "Enter cod product which you eant to delete - ";
        int numb = 0;
        cin >> numb;
        deleteproduct(numb);
        break;
    }
    case 6: {
        break;
    }
    }
    if (choice != 6)
        administrator();
    else
        return;
}

/**
 * Функция открытия меню покупателя с выбором функция покупательского
 * функционала
 */
void shop::pokupatel() {
    int choice = 0;
    cout << "................................\n";
    cout << "Command: \n";
    cout << "\t 1)Show product in the cart \n";
    cout << "\t 2)Show information about product \n";
    cout << "\t 3)Add product to cart \n";
    cout << "\t 4)Remove product to cart \n";
    cout << "\t 5)Calculate summa on the cart \n";
    cout << "\t 6)Buy product from the cart \n";
    cout << "\t 7)Exit \n";
    cin >> choice;
    switch (choice) {
    case 1: {
        cout << "In your cart: \n";
        showlistcart();
        break;
    }
    case 2: {
        cout << "Enter code products - ";
        int numb = 0;
        cin >> numb;
        showinfo(numb);
        break;
    }
    case 3: {
        cout << "What product you want to add (enter code) - ";
        int code = 0;
        cin >> code;
        addcart(code);
        break;
    }
    case 4: {
        cout << "Code product which need remove - ";
        int num = 0;
        cin >> num;
        remcart(num);
        break;
    }
    case 5: {
        cout << "All products - " << countproducttocart() << "\n";
        cout << "Summa to the cart is " << calcsumm(1) << "\n";
        cout << "Summa to the cars of discont is " << calcsumm(2) << "\n";
        break;
    }
    case 6: {
        buy();
        break;
    }
    case 7: {
        return;
    }
    default: {
        return;
    }
    }
    if (choice != 7)
        pokupatel();
}

/**
 * Функция поиска продукта в магазине по его коду
 * @param number код-номер продукта, который необходимо найти
 * @return порядковый номер продукта в векторе продуктов магазина
 */
int shop::findproduct(int number) const {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].getCode() == number) {
            return i;
        }
    }
    //если не нашлось такого элемента вернем первый
    return 0;
}

/**
 * Функция загрузки стандартного набора продуктов магазина
 */
void shop::insertdeflist() {
    auto insertproduct = defaultlist();
    insertproduct.loadproduct(
        "D:/project_shop/shop/prod.csv"); //указывается путь к файлу csv в
                                          //котором находится список продуктов.
                                          //При сохранение на диске D,
                                          //прописывайте путь полностью, тк
                                          //иначе файл будет не найден
    auto clist = insertproduct.getlist();
    list = vector<product>();
    for (int i = 0; i < clist.size(); i++) {
        list.push_back(clist[i]);
    }
}

/**
 * Функция добавления продукта в набор проуктов магазина
 * @param a Продукт, который необходимо добавить
 */
void shop::addproduct(product npr) { list.push_back(npr); }

/**
 * Функция удаления продукта из набора продуктов магазина
 * @param number Код-номер продукта, который необходимо удалить
 */
void shop::deleteproduct(int number) {
    int numb = findproduct(number);
    list.erase(list.cbegin() + numb);
}

/**
 * Функция для создания администратором нового продукта, который в последующем
 * будет добавлен в список продуктов магазина
 */
void shop::addnewproduct() {
    int addpric = 0;
    int sapr = 0;
    string addname;
    int kolv = 0;
    cout << "\nInput information:\n";
    cout << "Name: ";
    cin >> addname;
    cout << "\nPrice: ";
    cin >> addpric;
    cout << "If you don`t want to next information press 0\n";
    cout << "\nSale price: ";
    cin >> sapr;
    cout << "\nCount product: ";
    cin >> kolv;
    product newpr = product(addpric, addname);
    if (kolv != 0) {
        newpr.setKolvo(kolv);
    }
    if (sapr != 0) {
        newpr.setSaleprice(sapr);
    }
    addproduct(newpr);
}

/**
 * Функция показаза всех продуктов магазина для администратора
 */
void shop::showproducts() const {
    cout << "\ncode name price saleprice kolvo\n";
    for (auto prod : list)
        cout << prod.getCode() << " " << prod.getName() << " "
             << prod.getPrice() << " " << prod.getSaleprice() << " "
             << prod.getKolvo() << "\n";
}

/**
 * Функция показа информации о конкретном продукте для администратора
 * @param number код-номер продукта о котором хотят узнать информацию
 */
void shop::showproduct(int number) const {
    for (auto prod : list) {
        if (prod.getCode() == number) {
            cout << "Code - " << prod.getCode() << "\n";
            cout << "Name - " << prod.getName() << "\n";
            cout << "Price - " << prod.getPrice() << "\n";
            cout << "Sale price - " << prod.getSaleprice() << "\n";
            cout << "Kolvo - " << prod.getKolvo() << "\n";
            break;
        }
    }
}

/**
 * Функция изменения информации о продукте, функция доступна для администратора
 * @param number код-номер продукта для изменения
 */
void shop::editproduct(int number) {
    int numb = findproduct(number);
    int choice = 0;
    cout << "What information do you want to change?\n";
    cout << "\t 1)Name \n";
    cout << "\t 2)Sale \n";
    cout << "\t 3)Sale price \n";
    cout << "\t 4)Kolvo \n";
    cin >> choice;
    switch (choice) {
    case 1: {
        cout << "Enter name - ";
        string newname;
        cin >> newname;
        list[numb].setName(newname);
        break;
    }
    case 2: {
        cout << "Enter sale - ";
        int newsale = 0;
        cin >> newsale;
        list[numb].setPrice(newsale);
        break;
    }
    case 3: {
        cout << "Enter sale price - ";
        int newsalepr = 0;
        cin >> newsalepr;
        list[numb].setSaleprice(newsalepr);
        break;
    }
    case 4: {
        cout << "Enter kolvo - ";
        int newkolvo = 0;
        cin >> newkolvo;
        list[numb].setKolvo(newkolvo);
        break;
    }
    default: {
        return;
    }
    }
}

/**
 * Функция показа информации об определенном продукте для покупателя
 * @param number код-номер продукта
 */
void shop::showinfo(int number) const {
    for (auto prod : list) {
        if (prod.getCode() == number) {
            cout << "Name - " << prod.getName() << "\n";
            cout << "Price - " << prod.getPrice() << "\n";
            if (prod.getPrice() != prod.getSaleprice()) {
                cout << "Sale price - " << prod.getSaleprice() << "\n";
            }
            break;
        }
    }
}

/**
 * Функция добавления продукта в покупательскую корзину
 * @param number Код-номер продукта
 */
void shop::addcart(int number) {
    int numb = findproduct(number);
    cart.push_back(list[numb]);
}

/**
 * Функция удаления продукта, находящегося в покупательской корзине. У
 * даляется лишь первый из нескольких одинаковых продуктов в корзине
 * @param number Код-номер продукта
 */
void shop::remcart(int number) {
    for (int i = 0; i < cart.size(); i++) {
        if (cart[i].getCode() == number) {
            cart.erase(cart.begin() + i);
            break;
        }
    }
}

/**
 * Функция подсчета суммы продуктов в покупательской корзине
 * @param var подсчет суммы без скидки(1) или со скидкой(0)
 * @return Сумма продуктов в корзине покупателя
 */
int shop::calcsumm(int var) {
    int summ = 0;
    if (var == 0) {
        for (auto prod : cart) {
            summ += prod.getSaleprice();
        }
    } else {
        for (auto prod : cart) {
            summ += prod.getPrice();
        }
    }
    return summ;
}

/**
 * Функция покупки продуктов из корзины покупателя
 */
void shop::buy() {
    cout << "Your buing: \n";
    for (auto prod : cart) {
        cout << prod.getName() << " " << prod.getPrice() << " "
             << prod.getSaleprice() << "\n";
        prod.setKolvo(prod.getKolvo() - 1);
    }
    cout << "Summa to the cart is " << calcsumm(1) << "\n";
    cout << "Summa to the cars of discont is " << calcsumm(0) << "\n";
    cart = vector<product>();
}

/**
 * Функция просмотра продуктов, которые лежат в корзине у покупателя
 */
void shop::showlistcart() const {
    for (auto prod : cart) {
        cout << prod.getCode() << " " << prod.getName() << "\n";
    }
}

/**
 * Функция для получения продукта из вектора продуктов магазина по
 * номеру продукта в векторе
 * @param number Номер продукта в векторе
 * @return Продукт, номер которого задали
 */
product shop::getproductfromlist(int number) const { return list[number]; }

/**
 *Функция для получения продукта из вектора продуктов покупательской
 * корзины по номеру продукта в векторе
 * @param number Номер продукта в векторе корзины
 * @return Продукт из корзины с заданным номером
 */
product shop::getproductfromcart(int number) const { return cart[number]; }

/**
 * Функция для получения размера вектора покупательской корзины
 * @return Значение длины вектора
 */
int shop::countproducttocart() const { return cart.size(); }
