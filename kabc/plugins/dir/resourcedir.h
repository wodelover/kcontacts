/*
    This file is part of libkabc.
    Copyright (c) 2002 - 2003 Tobias Koenig <tokoe@kde.org>

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
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef KABC_RESOURCEDIR_H
#define KABC_RESOURCEDIR_H

#include <kconfig.h>
#include <kdirwatch.h>

#include <sys/types.h>

#include <kabc/resource.h>

class QTimer;

namespace KABC {

class FormatPlugin;

/**
  @internal
*/
class ResourceDir : public Resource
{
  Q_OBJECT

  public:
    ResourceDir( const KConfig* );
    ResourceDir( const QString &path, const QString &type = "vcard" );
    ~ResourceDir();

    virtual void writeConfig( KConfig* );

    virtual bool doOpen();
    virtual void doClose();
  
    virtual Ticket *requestSaveTicket();
    virtual void releaseSaveTicket( Ticket* );

    virtual bool load();
    virtual bool asyncLoad();
    virtual bool save( Ticket * );
    virtual bool asyncSave( Ticket * );

    /**
      Set path to be used for saving.
     */
    void setPath( const QString & );

    /**
      Return path used for loading and saving the address book.
     */
    QString path() const;

    /**
      Set the format by name.
     */
    void setFormat( const QString &format );

    /**
      Returns the format name.
     */
    QString format() const;
  
    /**
      Remove a addressee from its source.
      This method is mainly called by KABC::AddressBook.
     */
    virtual void removeAddressee( const Addressee& addr );

    /**
      This method is called by an error handler if the application
      crashed
     */
    virtual void cleanUp();

  protected slots:
    void pathChanged();

  protected:
    void init( const QString &path, const QString &format );
    bool lock( const QString &path );
    void unlock( const QString &path );

  private:
    FormatPlugin *mFormat;

    KDirWatch mDirWatch;

    QString mPath;
    QString mFormatName;
    QString mLockUniqueName;

    bool mAsynchronous;

    class ResourceDirPrivate;
    ResourceDirPrivate *d;
};

}

#endif
