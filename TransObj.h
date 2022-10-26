//TransObj.h
#pragma once

#include <QObject>
 
class GuZhiRebot : public QObject
{
	Q_OBJECT
public:
    Q_INVOKABLE void getValFromQml(QString inputData);

signals:
	void valueFromCpp(int val);

private:
    bool check_input(QString data);
    void print_output(QString data);

};
