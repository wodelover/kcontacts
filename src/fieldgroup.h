/*
    This file is part of the KContacts framework.
    Copyright (c) 2016 Laurent Montel <montel@kde.org>

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

#ifndef FIELDGROUP_H
#define FIELDGROUP_H

#include "kcontacts_export.h"
#include <QtCore/QSharedDataPointer>
#include <QtCore/QString>
#include <QtCore/QMap>

/** @short Class that holds a FieldGroup for a contact.
 *  @since 5.3
 */

namespace KContacts
{
class KCONTACTS_EXPORT FieldGroup
{
    friend KCONTACTS_EXPORT QDataStream &operator<<(QDataStream &, const FieldGroup &);
    friend KCONTACTS_EXPORT QDataStream &operator>>(QDataStream &, FieldGroup &);
public:
    FieldGroup();
    FieldGroup(const FieldGroup &other);
    FieldGroup(const QString &fieldGroupName);

    ~FieldGroup();

    typedef QVector<FieldGroup> List;

    void setFieldGroupName(const QString &fieldGroup);
    QString fieldGroupName() const;

    bool isValid() const;

    void setValue(const QString &value);
    QString value() const;

    void setParameters(const QMap<QString, QStringList> &params);
    QMap<QString, QStringList> parameters() const;

    bool operator==(const FieldGroup &other) const;
    bool operator!=(const FieldGroup &other) const;

    FieldGroup &operator=(const FieldGroup &other);

    QString toString() const;
private:
    class Private;
    QSharedDataPointer<Private> d;
};
KCONTACTS_EXPORT QDataStream &operator<<(QDataStream &stream, const FieldGroup &object);

KCONTACTS_EXPORT QDataStream &operator>>(QDataStream &stream, FieldGroup &object);

}
Q_DECLARE_TYPEINFO(KContacts::FieldGroup, Q_MOVABLE_TYPE);
#endif // FIELDGROUP_H