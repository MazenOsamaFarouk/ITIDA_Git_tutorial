#ifndef QTEXTENSIONS_H
#define QTEXTENSIONS_H

#include <QtGlobal>
#include <QString>

#if QT_VERSION < QT_VERSION_CHECK(5, 14, 0)
namespace Qt
{
    static auto endl = ::endl;
    static auto SkipEmptyParts = QString::SkipEmptyParts;
}
#endif


#endif // QTEXTENSIONS_H