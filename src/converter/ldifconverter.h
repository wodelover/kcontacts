/*
    This file is part of the KContacts framework.
    Copyright (c) 2003 Helge Deller <deller@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License version 2 only as published by the Free Software Foundation.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef KCONTACTS_LDIFCONVERTER_H
#define KCONTACTS_LDIFCONVERTER_H

#include "addressee.h"
#include "addresseelist.h"

#include <QtCore/QDateTime>
#include <QtCore/QString>

namespace KContacts
{

/**
  A set of functions to convert a string with LDIF information to addressees
  and vice versa. It is useful for addressbook import- and exportfilters
  and might be used to read and write Mozilla and Netscape addresssbooks.
*/

namespace LDIFConverter
{

/**
  Converts a LDIF string to a list of addressees.

  @param str         The vcard string.
  @param addrList    The addresseelist.
  @param dt          The date & time value of the last modification (e.g. file modification time).
*/
KCONTACTS_EXPORT bool LDIFToAddressee(const QString &str, AddresseeList &addrList,
                                      const QDateTime &dt = QDateTime::currentDateTime());

/**
  Converts a list of addressees to a LDIF string.

  @param addrList    The addresseelist.
  @param str         The LDIF string.
*/
KCONTACTS_EXPORT bool addresseeToLDIF(const AddresseeList &addrList, QString &str);

/**
  Converts an addressee to a LDIF string.

  @param addr    The addressee.
  @param str     The LDIF string.
*/
KCONTACTS_EXPORT bool addresseeToLDIF(const Addressee &addr, QString &str);

}

}
#endif