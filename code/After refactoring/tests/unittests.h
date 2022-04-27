#ifndef UNITTESTS_H
#define UNITTESTS_H

#include <QObject>
#include <QTest>
#include <tree.h>

class UnitTests : public QObject
{
    Q_OBJECT
public:
    UnitTests(QObject *parent = 0);
private slots:
    void insert_node();
    void delete_node();
    void min_node();
    void max_node();
};

#endif // UNITTESTS_H
