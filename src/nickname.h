/*
    This file is part of the KContacts framework.
    Copyright (C) 2016-2019 Laurent Montel <montel@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef NICKNAME_H
#define NICKNAME_H

#include "kcontacts_export.h"
#include <QSharedDataPointer>
#include <QString>
#include <QMap>

/** @short Class that holds a NickName for a contact.
 *  @since 5.3
 */
namespace KContacts {
class KCONTACTS_EXPORT NickName
{
    friend KCONTACTS_EXPORT QDataStream &operator<<(QDataStream &, const NickName &);
    friend KCONTACTS_EXPORT QDataStream &operator>>(QDataStream &, NickName &);
public:
    NickName();
    NickName(const NickName &other);
    NickName(const QString &nickname);

    ~NickName();

    typedef QVector<NickName> List;

    void setNickName(const QString &nickname);
    Q_REQUIRED_RESULT QString nickname() const;

    Q_REQUIRED_RESULT bool isValid() const;

    void setParameters(const QMap<QString, QStringList> &params);
    Q_REQUIRED_RESULT QMap<QString, QStringList> parameters() const;

    Q_REQUIRED_RESULT bool operator==(const NickName &other) const;
    Q_REQUIRED_RESULT bool operator!=(const NickName &other) const;

    Q_REQUIRED_RESULT NickName &operator=(const NickName &other);

    Q_REQUIRED_RESULT QString toString() const;
private:
    class Private;
    QSharedDataPointer<Private> d;
};
KCONTACTS_EXPORT QDataStream &operator<<(QDataStream &stream, const NickName &object);

KCONTACTS_EXPORT QDataStream &operator>>(QDataStream &stream, NickName &object);
}
Q_DECLARE_TYPEINFO(KContacts::NickName, Q_MOVABLE_TYPE);
#endif // NICKNAME_H
