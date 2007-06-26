/*
    This file is part of libkabc.
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

#include <qtest_kde.h>
#include "secrecytest.h"
#include "kabc/secrecy.h"

QTEST_KDEMAIN(SecrecyTest, NoGUI)

void SecrecyTest::emptyTest()
{
  KABC::Secrecy secrecy;

  QVERIFY( secrecy.type() == KABC::Secrecy::Invalid );
}

void SecrecyTest::storeTest()
{
  KABC::Secrecy secrecy;

  secrecy.setType( KABC::Secrecy::Private );

  QVERIFY( secrecy.type() == KABC::Secrecy::Private );
}

void SecrecyTest::equalsTest()
{
  KABC::Secrecy secrecy1, secrecy2;

  secrecy1.setType( KABC::Secrecy::Confidential );
  secrecy2.setType( KABC::Secrecy::Confidential );

  QVERIFY( secrecy1 == secrecy2 );
}

void SecrecyTest::differsTest()
{
  KABC::Secrecy secrecy1( KABC::Secrecy::Private );
  KABC::Secrecy secrecy2( KABC::Secrecy::Confidential );

  QVERIFY( secrecy1 != secrecy2 );
}

void SecrecyTest::assignmentTest()
{
  KABC::Secrecy secrecy1, secrecy2;

  secrecy1.setType( KABC::Secrecy::Confidential );
  secrecy1 = secrecy2;

  QVERIFY( secrecy1 == secrecy2 );
}

void SecrecyTest::serializeTest()
{
  KABC::Secrecy secrecy1, secrecy2;

  secrecy1.setType( KABC::Secrecy::Confidential );

  QByteArray data;
  QDataStream s( &data, QIODevice::WriteOnly );
  s << secrecy1;

  QDataStream t( &data, QIODevice::ReadOnly );
  t >> secrecy2;

  QVERIFY( secrecy1 == secrecy2 );
}

#include "secrecytest.moc"