#ifndef CASE_H
#define CASE_H

#include <QObject>

class Case : public QObject
{
    Q_OBJECT
public:
    explicit Case(QObject *parent = 0);
    Q_PROPERTY(QString caseQML READ readCase NOTIFY caseChanged)
    QString readCase();

signals:
    void caseChanged();

public slots:

private:
   int valeur;

};


#endif // CASE_H


