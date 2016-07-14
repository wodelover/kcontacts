/*
    This file is part of the KContacts framework.
    Copyright (c) 2007 Tobias Koenig <tokoe@kde.org>
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

#include "keytest.h"
#include "kcontacts/key.h"
#include <qtest.h>
#include "vcardtool.h"


QTEST_MAIN(KeyTest)

void KeyTest::storeTest()
{
    KContacts::Key key;

    key.setId(QStringLiteral("My Id"));
    key.setType(KContacts::Key::Custom);
    key.setCustomTypeString(QStringLiteral("GnuPG"));
    key.setTextData(QStringLiteral("That's my super secret key"));

    QVERIFY(key.id() == QStringLiteral("My Id"));
    QVERIFY(key.type() == KContacts::Key::Custom);
    QVERIFY(key.customTypeString() == QStringLiteral("GnuPG"));
    QVERIFY(key.textData() == QStringLiteral("That's my super secret key"));
    QVERIFY(key.isBinary() == false);
}

void KeyTest::equalsTest()
{
    KContacts::Key key1, key2;

    key1.setId(QStringLiteral("My Id"));
    key1.setType(KContacts::Key::Custom);
    key1.setCustomTypeString(QStringLiteral("GnuPG"));
    key1.setTextData(QStringLiteral("That's my super secret key"));

    key2.setId(QStringLiteral("My Id"));
    key2.setType(KContacts::Key::Custom);
    key2.setCustomTypeString(QStringLiteral("GnuPG"));
    key2.setTextData(QStringLiteral("That's my super secret key"));

    QVERIFY(key1 == key2);
}

void KeyTest::differsTest()
{
    KContacts::Key key1(QStringLiteral("TextKey"), KContacts::Key::PGP);
    KContacts::Key key2(QStringLiteral("TextKey"), KContacts::Key::Custom);

    QVERIFY(key1 != key2);
}

void KeyTest::assignmentTest()
{
    KContacts::Key key1, key2;

    key1.setId(QStringLiteral("My Id"));
    key1.setType(KContacts::Key::Custom);
    key1.setCustomTypeString(QStringLiteral("GnuPG"));
    key1.setTextData(QStringLiteral("That's my super secret key"));

    key2 = key1;

    QVERIFY(key1 == key2);
}

void KeyTest::serializeTest()
{
    KContacts::Key key1, key2;

    key1.setId(QStringLiteral("My Id"));
    key1.setType(KContacts::Key::Custom);
    key1.setCustomTypeString(QStringLiteral("GnuPG"));
    key1.setTextData(QStringLiteral("That's my super secret key"));

    QByteArray data;
    QDataStream s(&data, QIODevice::WriteOnly);
    s << key1;

    QDataStream t(&data, QIODevice::ReadOnly);
    t >> key2;

    QVERIFY(key1 == key2);
}

void KeyTest::shouldExportVCard3()
{
    KContacts::AddresseeList lst;
    KContacts::Addressee addr;
    addr.setEmails(QStringList() << QStringLiteral("foo@kde.org"));
    addr.setUid(QStringLiteral("testuid"));
    KContacts::Key key1(QStringLiteral("https://foo.org/sherlock-holmes.pub.asc"), KContacts::Key::PGP);
    addr.setKeys(KContacts::Key::List{key1});
    lst << addr;
    KContacts::VCardTool vcard;
    const QByteArray ba = vcard.exportVCards(lst, KContacts::VCard::v3_0);
    QByteArray expected("BEGIN:VCARD\r\n"
                        "VERSION:3.0\r\n"
                        "EMAIL:foo@kde.org\r\n"
                        "KEY;TYPE=PGP:https://foo.org/sherlock-holmes.pub.asc\r\n"
                        "N:;;;;\r\n"
                        "UID:testuid\r\n"
                        "END:VCARD\r\n\r\n");

    QCOMPARE(ba, expected);
}

void KeyTest::shouldExportVCard4()
{
    KContacts::AddresseeList lst;
    KContacts::Addressee addr;
    addr.setEmails(QStringList() << QStringLiteral("foo@kde.org"));
    addr.setUid(QStringLiteral("testuid"));
    KContacts::Key key1(QStringLiteral("https://foo.org/sherlock-holmes.pub.asc"), KContacts::Key::PGP);
    addr.setKeys(KContacts::Key::List{key1});
    lst << addr;
    KContacts::VCardTool vcard;
    const QByteArray ba = vcard.exportVCards(lst, KContacts::VCard::v4_0);
    QByteArray expected("BEGIN:VCARD\r\n"
                        "VERSION:4.0\r\n"
                        "EMAIL:foo@kde.org\r\n"
                        "KEY;MEDIATYPE=application/pgp-keys:https://foo.org/sherlock-holmes.pub.asc\r\n"
                        "N:;;;;\r\n"
                        "UID:testuid\r\n"
                        "END:VCARD\r\n\r\n");

    QCOMPARE(ba, expected);
}

void KeyTest::shouldParseVcard3()
{

}

void KeyTest::shouldParseVcard4()
{

}
