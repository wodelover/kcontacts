/*
    This file is part of the KContacts framework.
    Copyright (c) 2007 Tobias Koenig <tokoe@kde.org>

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

#include "timezonetest.h"
#include "kcontacts/timezone.h"
#include <QTest>
#include "vcardtool.h"

QTEST_MAIN(TimeZoneTest)

void TimeZoneTest::emptyTest()
{
    KContacts::TimeZone timezone;

    QVERIFY(timezone.isValid() == false);
}

void TimeZoneTest::storeTest()
{
    KContacts::TimeZone timezone;

    timezone.setOffset(2);

    QVERIFY(timezone.offset() == 2);
}

void TimeZoneTest::equalsTest()
{
    KContacts::TimeZone timezone1, timezone2;

    timezone1.setOffset(2);
    timezone2.setOffset(2);

    QVERIFY(timezone1 == timezone2);
}

void TimeZoneTest::differsTest()
{
    KContacts::TimeZone timezone1(2);
    KContacts::TimeZone timezone2(3);

    QVERIFY(timezone1 != timezone2);
    QVERIFY(timezone1 != KContacts::TimeZone());
}

void TimeZoneTest::assignmentTest()
{
    KContacts::TimeZone timezone1, timezone2;

    timezone1.setOffset(2);
    timezone1 = timezone2;

    QVERIFY(timezone1 == timezone2);
}

void TimeZoneTest::serializeTest()
{
    KContacts::TimeZone timezone1, timezone2;

    timezone1.setOffset(2);

    QByteArray data;
    QDataStream s(&data, QIODevice::WriteOnly);
    s << timezone1;

    QDataStream t(&data, QIODevice::ReadOnly);
    t >> timezone2;

    QVERIFY(timezone1 == timezone2);
}

void TimeZoneTest::shouldGenerateVCard3()
{
    KContacts::Addressee::List lst;
    KContacts::Addressee addr;
    addr.setEmails(QStringList() << QStringLiteral("foo@kde.org"));
    addr.setUid(QStringLiteral("testuid"));
    KContacts::TimeZone timezone;

    timezone.setOffset(2);
    addr.setTimeZone(timezone);

    lst << addr;
    KContacts::VCardTool vcard;
    const QByteArray ba = vcard.exportVCards(lst, KContacts::VCard::v3_0);
    QByteArray expected;
    expected = QByteArray("BEGIN:VCARD\r\n"
                          "VERSION:3.0\r\n"
                          "EMAIL:foo@kde.org\r\n"
                          "N:;;;;\r\n"
                          "TZ:+00:02\r\n"
                          "UID:testuid\r\n"
                          "END:VCARD\r\n\r\n");
    QCOMPARE(ba, expected);
}

void TimeZoneTest::shouldGenerateVCard4()
{
    //TODO fixme.
    KContacts::Addressee::List lst;
    KContacts::Addressee addr;
    addr.setEmails(QStringList() << QStringLiteral("foo@kde.org"));
    addr.setUid(QStringLiteral("testuid"));
    KContacts::TimeZone timezone;

    timezone.setOffset(2);
    addr.setTimeZone(timezone);

    lst << addr;
    KContacts::VCardTool vcard;
    const QByteArray ba = vcard.exportVCards(lst, KContacts::VCard::v4_0);
    const QByteArray expected("BEGIN:VCARD\r\n"
                              "VERSION:4.0\r\n"
                              "EMAIL:foo@kde.org\r\n"
                              "N:;;;;\r\n"
                              "TZ:+00:02\r\n"
                              "UID:testuid\r\n"
                              "END:VCARD\r\n\r\n");
    QCOMPARE(ba, expected);
}
