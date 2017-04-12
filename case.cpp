#include "case.h"


Case::Case(QObject *parent) : QObject(parent)
{
    valeur = 0;
    caseChanged();
}

QString Case::readCase()
{
    return QString::number(valeur);
}
