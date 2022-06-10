#include "defaultlist.cpp"
#include "defaultlist.h"
#include "product.cpp"
#include "product.h"
#include "shop.cpp"
#include "shop.h"
#include <doctest.h>

TEST_SUITE_BEGIN("file product");

TEST_CASE("Getters") {
    int pr = 87, spr = 27;
    string na = "hleb";
    int kolvo = 1897;
    auto a = product(na, pr, spr, kolvo);
    REQUIRE(a.getPrice() == pr);
    REQUIRE(a.getSaleprice() == spr);
    REQUIRE(a.getCode() == 1);
    REQUIRE(a.getName() == na);
    REQUIRE(a.getKolvo() == kolvo);
}

TEST_CASE("Constructors") {
    auto a = product("moloko", 100, 80, 15);
    REQUIRE(a.getPrice() == 100);
    REQUIRE(a.getSaleprice() == 80);
    REQUIRE(a.getCode() == 2);
    REQUIRE(a.getName() == "moloko");
    REQUIRE(a.getKolvo() == 15);
    auto b = product(159, "butter");
    REQUIRE(b.getPrice() == 159);
    REQUIRE(b.getName() == "butter");
    REQUIRE(a.getCode() == 2);
    REQUIRE(b.getCode() == 3);
}

TEST_CASE("Setters") {
    auto a = product("name", 1, 1, 1);
    REQUIRE(a.getPrice() == 1);
    REQUIRE(a.getSaleprice() == 1);
    REQUIRE(a.getCode() == 4);
    REQUIRE(a.getName() == "name");
    REQUIRE(a.getKolvo() == 1);
    int kolvo = 18978;
    a.setKolvo(kolvo);
    REQUIRE(a.getKolvo() == kolvo);
    int price = 1098;
    a.setPrice(price);
    REQUIRE(a.getPrice() == price);
    int saleprice = 1021;
    a.setSaleprice(saleprice);
    REQUIRE(a.getSaleprice() == saleprice);
    string nname = "novoe nazvanie";
    a.setName(nname);
    REQUIRE(a.getName() == nname);
    REQUIRE(a.getCode() == 4);
}

TEST_CASE("Return idcode to 1") {
    auto prod = product(170, "name");
    prod.retidcode();
    REQUIRE(product(1, "name").getCode() == 1);
    prod.retidcode();
}

TEST_SUITE_END();

TEST_SUITE_BEGIN("file defaultlist");
auto start_nabor = defaultlist();

TEST_CASE("Constructors") { REQUIRE(start_nabor.getsize() == 0); }

TEST_CASE("getsize") {
    start_nabor.loadproduct("D:/project_shop/shop/test_list.csv");
    REQUIRE(start_nabor.getsize() == 3);
}

TEST_CASE("operator ==") {
    product numberone = product("test1", 150, 149, 188);
    product numbertwo = product("test2", 187, 999, 188);
    product numberthree = product("test1", 150, 149, 188);
    REQUIRE(numberone == numberthree);
    REQUIRE(numberone != numbertwo);
    REQUIRE(numbertwo != numberthree);
}

TEST_CASE("loadprofuct and getlist") {
    auto rel_nabor = start_nabor.getlist();
    REQUIRE(rel_nabor[0] == product("hleb", 10, 5, 1));
    REQUIRE(rel_nabor[2] != product("hleb", 10, 5, 1));
    REQUIRE(rel_nabor[1] == product("milk", 100, 20, 1000));
    REQUIRE(rel_nabor[2] == product("water", 35, 45, 35));
    product(1, "name").retidcode();
}

TEST_SUITE_END();

TEST_SUITE_BEGIN("file shop");

shop magaz;

TEST_CASE("Insert default list of product and get product") {
    magaz.insertdeflist();
    for (int i = 0; i < 10; i++) {
        REQUIRE(magaz.getproductfromlist(i).getPrice() == (i + 1) * 100);
    }
}

TEST_CASE("add, get and delete product to cart and check size cart") {
    for (int i = 1; i <= 10; i++) {
        magaz.addcart(i);
    }
    REQUIRE(magaz.countproducttocart() == 10);
    for (int i = 0; i < 10; i++) {
        REQUIRE(magaz.getproductfromcart(0) == magaz.getproductfromlist(i));
        magaz.remcart(i + 1);
        REQUIRE(magaz.countproducttocart() == (9 - i));
    }
    product(1, "name").retidcode();
    magaz.insertdeflist();
}

TEST_CASE("findproduct") {
    REQUIRE(magaz.getproductfromlist(magaz.findproduct(7)).getSaleprice() ==
            170);
    REQUIRE(magaz.getproductfromlist(magaz.findproduct(7)).getKolvo() == 100);
    REQUIRE(magaz.getproductfromlist(magaz.findproduct(7)).getName() ==
            "suger");
}

TEST_CASE("add product to vector") {
    auto newproduct = product("test1", 999, 99, 9);
    magaz.addproduct(newproduct);
    REQUIRE(magaz.getproductfromlist(10) == newproduct);
}

TEST_CASE("deleteproduct") {
    magaz.deleteproduct(5);
    REQUIRE(magaz.getproductfromlist(5) == product("suger", 700, 170, 100));
    magaz.deleteproduct(7);
    REQUIRE(magaz.getproductfromlist(7) == product("apple", 1000, 78, 150));
    magaz.deleteproduct(0);
    REQUIRE(magaz.getproductfromlist(0) == product("bread", 200, 150, 20));
}

shop calcshop;

TEST_CASE("Calculate summ to cart") {
    product(1, "test").retidcode();
    int summa_price = 0;
    int summa_saleprice = 0;
    calcshop.insertdeflist();
    for (int i = 0; i < 10; i = i + 2) {
        calcshop.addcart(i + 1);
        summa_price += calcshop.getproductfromlist(i).getPrice();
        summa_saleprice += calcshop.getproductfromlist(i).getSaleprice();
    }
    REQUIRE(calcshop.calcsumm(1) == summa_price);
    REQUIRE(calcshop.calcsumm(0) == summa_saleprice);
}

TEST_CASE("Buy product from cart") {
    vector<int> kolvo;
    for (int i = 0; i < 5; i++) {
        kolvo.push_back(calcshop.getproductfromlist(i * 2).getKolvo());
    }
    calcshop.buy();
    for (int i = 0; i < 5; i++) {
        REQUIRE(kolvo[i] == calcshop.getproductfromlist(i * 2).getKolvo());
    }
    REQUIRE(calcshop.countproducttocart() == 0);
}

TEST_SUITE_END();
