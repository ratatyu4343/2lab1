#include "unittests.h"

UnitTests::UnitTests(QObject *parent)
{

}

void UnitTests::insert_node()
{
    double arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tree tree(arr, 10, 0, 1);
    tree.insert_node(-1, 0, 1);
    QCOMPARE(tree.min_node(), -1);
    tree.insert_node(10, 0, 1);
    QCOMPARE(tree.max_node(), 10);
    tree.insert_node(-10, 0, 111);
    QCOMPARE(tree.min_node(), -10);
    tree.insert_node(1100, 0, 1100);
    QCOMPARE(tree.max_node(), 1100);
}

void UnitTests::delete_node()
{
    double arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tree tree(arr, 10, 0, 1);
    tree.delete_node(0);
    QCOMPARE(tree.min_node(), 1);
    tree.delete_node(9);
    QCOMPARE(tree.max_node(), 8);
    tree.delete_node(-10);
    QCOMPARE(tree.min_node(), 1);
    tree.delete_node(1100);
    QCOMPARE(tree.max_node(), 8);
}

void UnitTests::min_node()
{
    double arr[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tree tree(arr, 11, 0, 1);
    QCOMPARE(tree.min_node(), -1);
    double arr2[] = {1, 1, 1};
    Tree tree2(arr2, 1, 0, 1);
    QCOMPARE(tree2.min_node(), 1);
    double arr3[] = {0};
    Tree tree3(arr3, 1, 0, 1);
    QCOMPARE(tree3.min_node(), 0);
}

void UnitTests::max_node()
{
    double arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 344};
    Tree tree(arr, 11, 0, 1);
    QCOMPARE(tree.max_node(), 344);
    double arr2[] = {1, 1};
    Tree tree2(arr2, 2, 0, 1);
    QCOMPARE(tree2.max_node(), 1);
    double arr3[] = {0};
    Tree tree3(arr3, 1, 0, 1);
    QCOMPARE(tree3.max_node(), 0);
}
