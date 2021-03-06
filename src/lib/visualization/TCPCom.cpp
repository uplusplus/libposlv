/******************************************************************************
 * Copyright (C) 2011 by Jerome Maye                                          *
 * jerome.maye@gmail.com                                                      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include "visualization/TCPCom.h"

#include "sensor/POSLVComTCP.h"
#include "com/TCPConnectionClient.h"
#include "types/Packet.h"
#include "exceptions/IOException.h"
#include "exceptions/SystemException.h"
#include "exceptions/TypeCreationException.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

TCPCom::TCPCom(POSLVComTCP& device, double pollingTime) :
    mDevice(device) {
}

TCPCom::~TCPCom() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void TCPCom::connect(bool connect) {
  try {
    if (connect) {
      mDevice.getConnection().open();
      emit deviceConnected(true);
    }
    else {
      mDevice.getConnection().close();
      emit deviceConnected(false);
    }
  }
  catch (SystemException& e) {
    emit comException(e.what());
  }
}

void TCPCom::writePacket(std::shared_ptr<Packet> packet) {
  try {
    mDevice.writePacket(packet);
  }
  catch (IOException& e) {
    emit comException(e.what());
    emit deviceConnected(false);
  }
  catch (SystemException& e) {
    emit comException(e.what());
    emit deviceConnected(false);
  }
  try {
    emit readPacket(mDevice.readPacket());
  }
  catch (IOException& e) {
  }
  catch (SystemException& e) {
    emit comException(e.what());
    emit deviceConnected(false);
  }
}
