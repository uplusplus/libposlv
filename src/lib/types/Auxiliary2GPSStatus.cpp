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

#include "types/Auxiliary2GPSStatus.h"

#include "com/POSLVGroupRead.h"

/******************************************************************************/
/* Statics                                                                    */
/******************************************************************************/

const Auxiliary2GPSStatus Auxiliary2GPSStatus::mProto;

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

Auxiliary2GPSStatus::Auxiliary2GPSStatus() :
  Group(13) {
}

Auxiliary2GPSStatus::Auxiliary2GPSStatus(const Auxiliary2GPSStatus& other) :
  Group(other) {
}

Auxiliary2GPSStatus& Auxiliary2GPSStatus::operator =
  (const Auxiliary2GPSStatus& other) {
  this->Group::operator=(other);
  return *this;
}

Auxiliary2GPSStatus::~Auxiliary2GPSStatus() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void Auxiliary2GPSStatus::read(POSLVGroupRead& stream) throw (IOException) {
  uint16_t byteCount;
  stream >> byteCount;
  stream >> mTimeDistance;
  stream >> mNavigationSolutionStatus;
  stream >> mNumberOfSVTracked;
  stream >> mChannelStatusByteCount;
  mChannelNumber = (byteCount - mByteCount) / mChannelStatusByteCount;
  for (size_t i = 0; i < mChannelNumber; i++)
    stream >> maChannelStatusData[i];
  stream >> mHDOP;
  stream >> mVDOP;
  stream >> mDGPSCorrectionLatency;
  stream >> mDGPSReferenceID;
  stream >> mGPSUTCWeekNumber;
  stream >> mGPSUTCTimeOffset;
  stream >> mGPSNavigationMessageLatency;
  stream >> mGeoidalSeparation;
  stream >> mNMEAMessageReceived;
  stream >> mAux12InUse;

  uint8_t pad;
  stream >> pad;
  if (pad != 0)
    throw IOException("Auxiliary2GPSStatus::read(): wrong pad");
}

void Auxiliary2GPSStatus::read(std::istream& stream) {
}

void Auxiliary2GPSStatus::write(std::ostream& stream) const {
}

void Auxiliary2GPSStatus::read(std::ifstream& stream) {
}

void Auxiliary2GPSStatus::write(std::ofstream& stream) const {
  stream << mTypeID;
  stream << " ";
  stream << mTimeDistance;
  stream << (int16_t)mNavigationSolutionStatus;
  stream << " ";
  stream << (uint16_t)mNumberOfSVTracked;
  stream << " ";
  stream << mChannelStatusByteCount;
  stream << " ";
  for (size_t i = 0; i < mChannelNumber; i++)
    stream << maChannelStatusData[i];
  stream << mHDOP;
  stream << " ";
  stream << mVDOP;
  stream << " ";
  stream << mDGPSCorrectionLatency;
  stream << " ";
  stream << mDGPSReferenceID;
  stream << " ";
  stream << mGPSUTCWeekNumber;
  stream << " ";
  stream << mGPSUTCTimeOffset;
  stream << " ";
  stream << mGPSNavigationMessageLatency;
  stream << " ";
  stream << mGeoidalSeparation;
  stream << " ";
  stream << mNMEAMessageReceived;
  stream << " ";
  stream << (uint16_t)mAux12InUse;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

Auxiliary2GPSStatus* Auxiliary2GPSStatus::clone() const {
  return new Auxiliary2GPSStatus(*this);
}
