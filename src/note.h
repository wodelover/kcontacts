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

#ifndef NOTE_H
#define NOTE_H

#include "kcontacts_export.h"
#include <QSharedDataPointer>
#include <QString>
#include <QMap>

namespace KContacts {
/** @short Class that holds a Note for a contact.
 *  @since 5.3
 */
class KCONTACTS_EXPORT Note
{
    friend KCONTACTS_EXPORT QDataStream &operator<<(QDataStream &, const Note &);
    friend KCONTACTS_EXPORT QDataStream &operator>>(QDataStream &, Note &);
public:
    Note();
    Note(const Note &other);
    Note(const QString &note);

    ~Note();

    typedef QVector<Note> List;

    void setNote(const QString &note);
    Q_REQUIRED_RESULT QString note() const;

    Q_REQUIRED_RESULT bool isValid() const;

    void setParameters(const QMap<QString, QStringList> &params);
    Q_REQUIRED_RESULT QMap<QString, QStringList> parameters() const;

    Q_REQUIRED_RESULT bool operator==(const Note &other) const;
    Q_REQUIRED_RESULT bool operator!=(const Note &other) const;

    Note &operator=(const Note &other);

    Q_REQUIRED_RESULT QString toString() const;
private:
    class Private;
    QSharedDataPointer<Private> d;
};
KCONTACTS_EXPORT QDataStream &operator<<(QDataStream &stream, const Note &object);

KCONTACTS_EXPORT QDataStream &operator>>(QDataStream &stream, Note &object);
}
Q_DECLARE_TYPEINFO(KContacts::Note, Q_MOVABLE_TYPE);
#endif // NOTE_H
