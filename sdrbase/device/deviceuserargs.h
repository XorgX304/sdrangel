///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef SDRBASE_DEVICE_DEVICEUSERARGS_H_
#define SDRBASE_DEVICE_DEVICEUSERARGS_H_

#include <QMap>
#include <QString>
#include <QByteArray>

#include "export.h"

struct DEVICES_API DeviceUserArgs
{
public:
	QByteArray serialize() const;
	bool deserialize(const QByteArray& data);

    static void splitDeviceKey(const QString& key, QString& id, int& sequence);
    static void composeDeviceKey(const QString& id, int sequence, QString& key);

    QMap<QString, QString> m_argsByDevice; //!< "id-sequence" to arg map. Id is hardwareId when referencing hardware device but not limited to it
};


#endif // SDRBASE_DEVICE_DEVICEUSERARGS_H_