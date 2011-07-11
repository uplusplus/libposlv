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

#include "types/BaseGPS1DataStream.h"

#include "com/POSLVGroupRead.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const BaseGPS1DataStream BaseGPS1DataStream::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

BaseGPS1DataStream::BaseGPS1DataStream() :
  Group(10011),
  mau8GPSReceiverRawData(0) {
}

BaseGPS1DataStream::BaseGPS1DataStream(const BaseGPS1DataStream& other) :
  Group(other),
  mau8GPSReceiverRawData(other.mau8GPSReceiverRawData) {
}

BaseGPS1DataStream& BaseGPS1DataStream::operator =
  (const BaseGPS1DataStream& other) {
  this->Group::operator=(other);
  mau8GPSReceiverRawData = other.mau8GPSReceiverRawData;
  return *this;
}

BaseGPS1DataStream::~BaseGPS1DataStream() {
  if (mau8GPSReceiverRawData)
    delete []mau8GPSReceiverRawData;
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void BaseGPS1DataStream::read(POSLVGroupRead& stream) throw (IOException) {
  uint16_t byteCount;
  stream >> byteCount;
  stream >> mTimeDistance;
  for (size_t i = 0; i < 6; i++)
    stream >> mau8Reserved[i];
  stream >> mVariableMsgByteCount;
  mau8GPSReceiverRawData = new uint8_t[mVariableMsgByteCount];
  for (size_t i = 0; i < mVariableMsgByteCount; i++)
    stream >> mau8GPSReceiverRawData[i];
  size_t padSize = byteCount - mVariableMsgByteCount - 38;

  uint8_t pad;
  for (size_t i = 0; i < padSize; i++) {
    stream >> pad;
    if (pad != 0)
      throw IOException("BaseGPS1DataStream::read(): wrong pad");
  }
}

void BaseGPS1DataStream::read(std::istream& stream) {
}

void BaseGPS1DataStream::write(std::ostream& stream) const {
}

void BaseGPS1DataStream::read(std::ifstream& stream) {
}

void BaseGPS1DataStream::write(std::ofstream& stream) const {
  stream << mTypeID;
  stream << " ";
  stream << mTimeDistance;
  for (size_t i = 0; i < 6; i++) {
    stream << std::hex << (uint16_t)mau8Reserved[i] << std::dec;
    stream << " ";
  }
  stream << mVariableMsgByteCount;
  stream << " ";
  for (size_t i = 0; i < mVariableMsgByteCount; i++) {
    stream << std::hex << (uint16_t)mau8GPSReceiverRawData[i] << std::dec;
    stream << " ";
  }
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/


BaseGPS1DataStream* BaseGPS1DataStream::clone() const {
  return new BaseGPS1DataStream(*this);
}
