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
//krazy:excludeall=contractions

#include "addresseetest.h"
#include "kcontacts/addressee.h"
#include <qtest.h>

QTEST_MAIN(AddresseeTest)

void AddresseeTest::emptyTest()
{
    KContacts::Addressee addressee;
    QVERIFY(addressee.isEmpty());

    KContacts::Addressee addresseeWithMail;
    addresseeWithMail.insertEmail(QStringLiteral("foo@bar.org"));
    QVERIFY(!addresseeWithMail.isEmpty());
}

void AddresseeTest::storeTest()
{
    KContacts::Addressee addressee;

    KContacts::Picture logo(QStringLiteral("http://scottlandyard.info/pics/logo.png"));
    KContacts::Picture photo(QStringLiteral("http://scottlandyard.info/~sinclair/photo.png"));
    KContacts::Sound sound(QStringLiteral("http://scottlandyard.info/~sinclair/sound.wav"));

    QStringList emails;
    emails << QStringLiteral("john@sinclair.com") << QStringLiteral("ghosthunter@sinclair.com");

    KContacts::Key::List keys;
    keys << KContacts::Key(QStringLiteral("SecretKey"));

    QStringList categories;
    categories << QStringLiteral("Helper") << QStringLiteral("Friend");

    QStringList customs;
    customs << QStringLiteral("X-Danger: high");

    KContacts::Gender gender(QStringLiteral("H"));
    addressee.setGender(gender);
    KContacts::Lang lang(QLatin1String("lang"));
    addressee.setLangs(KContacts::Lang::List() << lang);

    addressee.setUid(QStringLiteral("My uid"));
    addressee.setName(QStringLiteral("John Sinclair"));
    addressee.setFormattedName(QStringLiteral("Sinclair, John"));
    addressee.setFamilyName(QStringLiteral("Sinclair"));
    addressee.setGivenName(QStringLiteral("John"));
    addressee.setAdditionalName(QStringLiteral("Bob"));
    addressee.setPrefix(QStringLiteral("Sir"));
    addressee.setSuffix(QStringLiteral("II"));
    addressee.setNickName(QStringLiteral("ghosthunter"));
    addressee.setBirthday(QDateTime(QDate(1982, 7, 19)));
    addressee.setMailer(QStringLiteral("mutt"));
    addressee.setTimeZone(KContacts::TimeZone(2));
    addressee.setGeo(KContacts::Geo(42, 23));
    addressee.setTitle(QStringLiteral("Ghost Hunter"));
    addressee.setRole(QStringLiteral("Leader"));
    addressee.setOrganization(QStringLiteral("Scottland Yard"));
    addressee.setNote(QStringLiteral("Don't cross black deads way..."));
    addressee.setProductId(QStringLiteral("ProductId45"));
    addressee.setRevision(QDateTime(QDate(1982, 9, 15)));
    addressee.setSortString(QStringLiteral("Name"));
    KContacts::ResourceLocatorUrl url;
    url.setUrl(QUrl(QStringLiteral("www.scottlandyard.info")));
    addressee.setUrl(url);
    addressee.setSecrecy(KContacts::Secrecy(KContacts::Secrecy::Public));
    addressee.setLogo(logo);
    addressee.setPhoto(photo);
    addressee.setSound(sound);
    addressee.setEmails(emails);
    addressee.setKeys(keys);
    addressee.setCategories(categories);
    addressee.setCustoms(customs);
    addressee.setKind(QStringLiteral("foo"));
    addressee.setChanged(false);

    QVERIFY(addressee.langs() == (KContacts::Lang::List() << lang));
    QVERIFY(addressee.gender() == gender);
    QVERIFY(addressee.uid() == QStringLiteral("My uid"));
    QVERIFY(addressee.name() == QStringLiteral("John Sinclair"));
    QVERIFY(addressee.formattedName() == QStringLiteral("Sinclair, John"));
    QVERIFY(addressee.familyName() == QStringLiteral("Sinclair"));
    QVERIFY(addressee.givenName() == QStringLiteral("John"));
    QVERIFY(addressee.additionalName() == QStringLiteral("Bob"));
    QVERIFY(addressee.prefix() == QStringLiteral("Sir"));
    QVERIFY(addressee.suffix() == QStringLiteral("II"));
    QVERIFY(addressee.nickName() == QStringLiteral("ghosthunter"));
    QVERIFY(addressee.birthday() == QDateTime(QDate(1982, 7, 19)));
    QVERIFY(addressee.mailer() == QStringLiteral("mutt"));
    QVERIFY(addressee.timeZone() == KContacts::TimeZone(2));
    QVERIFY(addressee.geo() == KContacts::Geo(42, 23));
    QVERIFY(addressee.title() == QStringLiteral("Ghost Hunter"));
    QVERIFY(addressee.role() == QStringLiteral("Leader"));
    QVERIFY(addressee.organization() == QStringLiteral("Scottland Yard"));
    QVERIFY(addressee.note() == QStringLiteral("Don't cross black deads way..."));
    QVERIFY(addressee.productId() == QStringLiteral("ProductId45"));
    QVERIFY(addressee.revision() == QDateTime(QDate(1982, 9, 15)));
    QVERIFY(addressee.sortString() == QStringLiteral("Name"));
    QVERIFY(addressee.url() == url);
    QVERIFY(addressee.secrecy() == KContacts::Secrecy(KContacts::Secrecy::Public));
    QVERIFY(addressee.logo() == logo);
    QVERIFY(addressee.photo() == photo);
    QVERIFY(addressee.sound() == sound);
    QVERIFY(addressee.emails() == emails);
    QVERIFY(addressee.keys() == keys);
    QVERIFY(addressee.categories() == categories);
    QVERIFY(addressee.customs() == customs);
    QVERIFY(addressee.changed() == false);
    QCOMPARE(addressee.kind(), QStringLiteral("foo"));
}

void AddresseeTest::equalsTest()
{
    KContacts::Addressee addressee1, addressee2;

    KContacts::Picture logo(QStringLiteral("http://scottlandyard.info/pics/logo.png"));
    KContacts::Picture photo(QStringLiteral("http://scottlandyard.info/~sinclair/photo.png"));
    KContacts::Sound sound(QStringLiteral("http://scottlandyard.info/~sinclair/sound.wav"));

    QStringList emails;
    emails << QStringLiteral("john@sinclair.com") << QStringLiteral("ghosthunter@sinclair.com");

    KContacts::Key::List keys;
    keys << KContacts::Key(QStringLiteral("SecretKey"));

    QStringList categories;
    categories << QStringLiteral("Helper") << QStringLiteral("Friend");

    QStringList customs;
    customs << QStringLiteral("X-Danger: high");

    addressee1.setUid(QStringLiteral("My uid"));
    addressee1.setName(QStringLiteral("John Sinclair"));
    addressee1.setFormattedName(QStringLiteral("Sinclair, John"));
    addressee1.setFamilyName(QStringLiteral("Sinclair"));
    addressee1.setGivenName(QStringLiteral("John"));
    addressee1.setAdditionalName(QStringLiteral("Bob"));
    addressee1.setPrefix(QStringLiteral("Sir"));
    addressee1.setSuffix(QStringLiteral("II"));
    addressee1.setNickName(QStringLiteral("ghosthunter"));
    addressee1.setBirthday(QDateTime(QDate(1982, 7, 19)));
    addressee1.setMailer(QStringLiteral("mutt"));
    addressee1.setTimeZone(KContacts::TimeZone(2));
    addressee1.setGeo(KContacts::Geo(42, 23));
    addressee1.setTitle(QStringLiteral("Ghost Hunter"));
    addressee1.setRole(QStringLiteral("Leader"));
    addressee1.setOrganization(QStringLiteral("Scottland Yard"));
    addressee1.setNote(QStringLiteral("Don't cross black deads way..."));
    addressee1.setProductId(QStringLiteral("ProductId45"));
    addressee1.setRevision(QDateTime(QDate(1982, 9, 15)));
    addressee1.setSortString(QStringLiteral("Name"));
    KContacts::ResourceLocatorUrl url;
    url.setUrl(QUrl(QStringLiteral("www.scottlandyard.info")));
    addressee1.setUrl(url);
    addressee1.setSecrecy(KContacts::Secrecy(KContacts::Secrecy::Public));
    addressee1.setLogo(logo);
    addressee1.setPhoto(photo);
    addressee1.setSound(sound);
    addressee1.setEmails(emails);
    addressee1.setKeys(keys);
    addressee1.setCategories(categories);
    addressee1.setCustoms(customs);
    addressee1.setChanged(false);

    addressee2.setUid(QStringLiteral("My uid"));
    addressee2.setName(QStringLiteral("John Sinclair"));
    addressee2.setFormattedName(QStringLiteral("Sinclair, John"));
    addressee2.setFamilyName(QStringLiteral("Sinclair"));
    addressee2.setGivenName(QStringLiteral("John"));
    addressee2.setAdditionalName(QStringLiteral("Bob"));
    addressee2.setPrefix(QStringLiteral("Sir"));
    addressee2.setSuffix(QStringLiteral("II"));
    addressee2.setNickName(QStringLiteral("ghosthunter"));
    addressee2.setBirthday(QDateTime(QDate(1982, 7, 19)));
    addressee2.setMailer(QStringLiteral("mutt"));
    addressee2.setTimeZone(KContacts::TimeZone(2));
    addressee2.setGeo(KContacts::Geo(42, 23));
    addressee2.setTitle(QStringLiteral("Ghost Hunter"));
    addressee2.setRole(QStringLiteral("Leader"));
    addressee2.setOrganization(QStringLiteral("Scottland Yard"));
    addressee2.setNote(QStringLiteral("Don't cross black deads way..."));
    addressee2.setProductId(QStringLiteral("ProductId45"));
    addressee2.setRevision(QDateTime(QDate(1982, 9, 15)));
    addressee2.setSortString(QStringLiteral("Name"));
    addressee2.setUrl(url);
    addressee2.setSecrecy(KContacts::Secrecy(KContacts::Secrecy::Public));
    addressee2.setLogo(logo);
    addressee2.setPhoto(photo);
    addressee2.setSound(sound);
    addressee2.setEmails(emails);
    addressee2.setKeys(keys);
    addressee2.setCategories(categories);
    addressee2.setCustoms(customs);
    addressee2.setChanged(false);

    QVERIFY(addressee1 == addressee2);
}

void AddresseeTest::differsTest()
{
    KContacts::Addressee addressee1, addressee2;

    addressee1.setNameFromString(QStringLiteral("John Sinclair"));
    addressee2.setNameFromString(QStringLiteral("Suko"));

    QVERIFY(addressee1 != addressee2);
}

void AddresseeTest::assignmentTest()
{
    KContacts::Addressee addressee1, addressee2;

    KContacts::Picture logo(QStringLiteral("http://scottlandyard.info/pics/logo.png"));
    KContacts::Picture photo(QStringLiteral("http://scottlandyard.info/~sinclair/photo.png"));
    KContacts::Sound sound(QStringLiteral("http://scottlandyard.info/~sinclair/sound.wav"));

    QStringList emails;
    emails << QStringLiteral("john@sinclair.com") << QStringLiteral("ghosthunter@sinclair.com");

    KContacts::Key::List keys;
    keys << KContacts::Key(QStringLiteral("SecretKey"));

    QStringList categories;
    categories << QStringLiteral("Helper") << QStringLiteral("Friend");

    QStringList customs;
    customs << QStringLiteral("X-Danger: high");

    addressee1.setUid(QStringLiteral("My uid"));
    addressee1.setName(QStringLiteral("John Sinclair"));
    addressee1.setFormattedName(QStringLiteral("Sinclair, John"));
    addressee1.setFamilyName(QStringLiteral("Sinclair"));
    addressee1.setGivenName(QStringLiteral("John"));
    addressee1.setAdditionalName(QStringLiteral("Bob"));
    addressee1.setPrefix(QStringLiteral("Sir"));
    addressee1.setSuffix(QStringLiteral("II"));
    addressee1.setNickName(QStringLiteral("ghosthunter"));
    addressee1.setBirthday(QDateTime(QDate(1982, 7, 19)));
    addressee1.setMailer(QStringLiteral("mutt"));
    addressee1.setTimeZone(KContacts::TimeZone(2));
    addressee1.setGeo(KContacts::Geo(42, 23));
    addressee1.setTitle(QStringLiteral("Ghost Hunter"));
    addressee1.setRole(QStringLiteral("Leader"));
    addressee1.setOrganization(QStringLiteral("Scottland Yard"));
    addressee1.setNote(QStringLiteral("Don't cross black deads way..."));
    addressee1.setProductId(QStringLiteral("ProductId45"));
    addressee1.setRevision(QDateTime(QDate(1982, 9, 15)));
    addressee1.setSortString(QStringLiteral("Name"));
    KContacts::ResourceLocatorUrl url;
    url.setUrl(QUrl(QStringLiteral("www.scottlandyard.info")));
    addressee1.setUrl(url);
    addressee1.setSecrecy(KContacts::Secrecy(KContacts::Secrecy::Public));
    addressee1.setLogo(logo);
    addressee1.setPhoto(photo);
    addressee1.setSound(sound);
    addressee1.setEmails(emails);
    addressee1.setKeys(keys);
    addressee1.setCategories(categories);
    addressee1.setCustoms(customs);
    addressee1.setChanged(false);

    addressee2 = addressee1;

    QVERIFY(addressee1 == addressee2);
}

void AddresseeTest::serializeTest()
{
    KContacts::Addressee addressee1, addressee2;

    KContacts::Picture logo(QStringLiteral("http://scottlandyard.info/pics/logo.png"));
    KContacts::Picture photo(QStringLiteral("http://scottlandyard.info/~sinclair/photo.png"));
    KContacts::Sound sound(QStringLiteral("http://scottlandyard.info/~sinclair/sound.wav"));

    QStringList emails;
    emails << QStringLiteral("john@sinclair.com") << QStringLiteral("ghosthunter@sinclair.com");

    KContacts::Key::List keys;
    keys << KContacts::Key(QStringLiteral("SecretKey"));

    QStringList categories;
    categories << QStringLiteral("Helper") << QStringLiteral("Friend");

    QStringList customs;
    customs << QStringLiteral("FirstApp-FirstKey:FirstValue")
            << QStringLiteral("SecondApp-SecondKey:SecondValue")
            << QStringLiteral("ThirdApp-ThirdKey:ThirdValue");

    addressee1.setUid(QStringLiteral("My uid"));
    addressee1.setName(QStringLiteral("John Sinclair"));
    addressee1.setFormattedName(QStringLiteral("Sinclair, John"));
    addressee1.setFamilyName(QStringLiteral("Sinclair"));
    addressee1.setGivenName(QStringLiteral("John"));
    addressee1.setAdditionalName(QStringLiteral("Bob"));
    addressee1.setPrefix(QStringLiteral("Sir"));
    addressee1.setSuffix(QStringLiteral("II"));
    addressee1.setNickName(QStringLiteral("ghosthunter"));
    addressee1.setBirthday(QDateTime(QDate(1982, 7, 19)));
    addressee1.setMailer(QStringLiteral("mutt"));
    addressee1.setTimeZone(KContacts::TimeZone(2));
    addressee1.setGeo(KContacts::Geo(42, 23));
    addressee1.setTitle(QStringLiteral("Ghost Hunter"));
    addressee1.setRole(QStringLiteral("Leader"));
    addressee1.setOrganization(QStringLiteral("Scottland Yard"));
    addressee1.setNote(QStringLiteral("Don't cross black deads way..."));
    addressee1.setProductId(QStringLiteral("ProductId45"));
    addressee1.setRevision(QDateTime(QDate(1982, 9, 15)));
    addressee1.setSortString(QStringLiteral("Name"));
    KContacts::ResourceLocatorUrl url;
    url.setUrl(QUrl(QStringLiteral("www.scottlandyard.info")));

    addressee1.setUrl(url);
    addressee1.setSecrecy(KContacts::Secrecy(KContacts::Secrecy::Public));
    addressee1.setLogo(logo);
    addressee1.setPhoto(photo);
    addressee1.setSound(sound);
    addressee1.setEmails(emails);
    addressee1.setKeys(keys);
    addressee1.setCategories(categories);
    addressee1.setCustoms(customs);
    addressee1.setChanged(false);

    QByteArray data;
    QDataStream s(&data, QIODevice::WriteOnly);
    s << addressee1;

    QDataStream t(&data, QIODevice::ReadOnly);
    t >> addressee2;

    QVERIFY(addressee1 == addressee2);
}

void AddresseeTest::fullEmailTest()
{
    KContacts::Addressee a;
    QStringList emails;
    emails << QStringLiteral("foo@bar.com");
    a.setEmails(emails);
    a.setFormattedName(QStringLiteral("firstname \"nickname\" lastname"));
    QCOMPARE(a.fullEmail(),
             QStringLiteral("\"firstname \\\"nickname\\\" lastname\" <foo@bar.com>"));
}

void AddresseeTest::nameFromStringTest()
{
    KContacts::Addressee a;
    a.setNameFromString(QStringLiteral("Firstname Lastname"));
    QCOMPARE(a.givenName(), QStringLiteral("Firstname"));
    QCOMPARE(a.familyName(), QStringLiteral("Lastname"));
    QCOMPARE(a.formattedName(), QStringLiteral("Firstname Lastname"));
}

void AddresseeTest::customFieldsTest()
{
    KContacts::Addressee a;

    // test for empty
    QVERIFY(a.customs().isEmpty());

    // test insert
    a.insertCustom(QStringLiteral("MyApp"), QStringLiteral("MyKey"), QStringLiteral("MyValue"));
    QCOMPARE(a.customs().count(), 1);
    QCOMPARE(a.custom(QStringLiteral("MyApp"), QStringLiteral("MyKey")), QStringLiteral("MyValue"));

    a.insertCustom(QStringLiteral("MyApp"), QStringLiteral("MyKey"), QStringLiteral("YourValue"));
    QCOMPARE(a.customs().count(), 1);   // still one, we overwrite...
    QCOMPARE(a.custom(QStringLiteral("MyApp"), QStringLiteral("MyKey")), QStringLiteral("YourValue"));

    // test query non-existing app/key
    QCOMPARE(a.custom(QStringLiteral("MyApp"), QStringLiteral("UnknownKey")), QString());
    QCOMPARE(a.custom(QStringLiteral("UnknownApp"), QStringLiteral("MyKey")), QString());

    // test insert with different key
    a.insertCustom(QStringLiteral("MyApp"), QStringLiteral("AnotherKey"), QStringLiteral("OtherValue"));
    QCOMPARE(a.customs().count(), 2);
    QCOMPARE(a.custom(QStringLiteral("MyApp"), QStringLiteral("AnotherKey")), QStringLiteral("OtherValue"));
    QCOMPARE(a.custom(QStringLiteral("MyApp"), QStringLiteral("MyKey")), QStringLiteral("YourValue"));

    // test insert with different app
    a.insertCustom(QStringLiteral("OtherApp"), QStringLiteral("OtherKey"), QStringLiteral("OurValue"));
    QCOMPARE(a.customs().count(), 3);
    QCOMPARE(a.custom(QStringLiteral("OtherApp"), QStringLiteral("OtherKey")), QStringLiteral("OurValue"));
    QCOMPARE(a.custom(QStringLiteral("MyApp"), QStringLiteral("AnotherKey")), QStringLiteral("OtherValue"));
    QCOMPARE(a.custom(QStringLiteral("MyApp"), QStringLiteral("MyKey")), QStringLiteral("YourValue"));

#if 0 //Order is not defined now as we use a QHash
    // test customs
    QCOMPARE(a.customs().at(0), QStringLiteral("MyApp-MyKey:YourValue"));
    QCOMPARE(a.customs().at(1), QStringLiteral("MyApp-AnotherKey:OtherValue"));
    QCOMPARE(a.customs().at(2), QStringLiteral("OtherApp-OtherKey:OurValue"));
#endif
    // test equal operator
    KContacts::Addressee b;
    b.setUid(a.uid());
    b.insertCustom(QStringLiteral("OtherApp"), QStringLiteral("OtherKey"), QStringLiteral("OurValue"));
    b.insertCustom(QStringLiteral("MyApp"), QStringLiteral("MyKey"), QStringLiteral("YourValue"));
    b.insertCustom(QStringLiteral("MyApp"), QStringLiteral("AnotherKey"), QStringLiteral("OtherValue"));

    QCOMPARE(a, b);

    b.insertCustom(QStringLiteral("MyApp"), QStringLiteral("AnotherKey"), QStringLiteral("WrongValue"));
    QVERIFY(a != b);

    // test setCustoms
    KContacts::Addressee c;
    c.insertCustom(QStringLiteral("ThisApp"), QStringLiteral("ShouldNotBe"), QStringLiteral("There"));
    QCOMPARE(c.customs().count(), 1);

    const QStringList testData = QStringList() << QStringLiteral("FirstApp-FirstKey:FirstValue")
                                 << QStringLiteral("SecondApp-SecondKey:SecondValue")
                                 << QStringLiteral("ThirdApp-ThirdKey:ThirdValue");

    c.setCustoms(testData);
    QCOMPARE(c.customs().count(), 3);

    QCOMPARE(c.custom(QStringLiteral("FirstApp"), QStringLiteral("FirstKey")), QStringLiteral("FirstValue"));
    QCOMPARE(c.custom(QStringLiteral("SecondApp"), QStringLiteral("SecondKey")), QStringLiteral("SecondValue"));
    QCOMPARE(c.custom(QStringLiteral("ThirdApp"), QStringLiteral("ThirdKey")), QStringLiteral("ThirdValue"));

    // test remove
    QCOMPARE(c.customs().count(), 3);
    c.removeCustom(QStringLiteral("UnknownApp"), QStringLiteral("FirstKey"));
    QCOMPARE(c.customs().count(), 3);
    c.removeCustom(QStringLiteral("FirstApp"), QStringLiteral("UnknownKey"));
    QCOMPARE(c.customs().count(), 3);
    c.removeCustom(QStringLiteral("FirstApp"), QStringLiteral("FirstKey"));
    QCOMPARE(c.customs().count(), 2);
}

void AddresseeTest::parseEmailAddress_data()
{
    QTest::addColumn<QString>("inputEmail");
    QTest::addColumn<QString>("email");
    QTest::addColumn<QString>("name");
    QTest::newRow("simpleemail") << QStringLiteral("foo@kde.org") << QStringLiteral("foo@kde.org") << QString();
    QTest::newRow("email") << QStringLiteral("foo <foo@kde.org>") << QStringLiteral("foo@kde.org") << QStringLiteral("foo");
    QTest::newRow("namewithdoublequote") << QStringLiteral("\"foo\" <foo@kde.org>") << QStringLiteral("foo@kde.org") << QStringLiteral("foo");
}

void AddresseeTest::parseEmailAddress()
{
    QFETCH(QString, inputEmail);
    QFETCH(QString, email);
    QFETCH(QString, name);

    QString parsedName;
    QString parsedEmail;
    KContacts::Addressee::parseEmailAddress(inputEmail, parsedName, parsedEmail);
    QCOMPARE(parsedEmail, email);
    QCOMPARE(parsedName, name);
}
