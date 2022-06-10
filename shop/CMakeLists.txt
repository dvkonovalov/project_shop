cmake_minimum_required(VERSION 3.10.0)
add_executable(shop-test test.cpp)
target_link_libraries(shop-test PUBLIC doctest default)
add_test(NAME shop-test COMMAND shop-test --force-colors -d)
add_custom_target(cloud-test COMMAND shop-test --force-colors -d)

add_executable(shop shop.cpp shop.h product.cpp product.h defaultlist.cpp defaultlist.h main.cpp)
target_link_libraries(shop PUBLIC default)
