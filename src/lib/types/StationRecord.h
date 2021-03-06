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

/** \file StationRecord.h
    \brief This file defines the StationRecord class, which is a station record
           for the Applanix
  */

#ifndef STATIONRECORD_H
#define STATIONRECORD_H

#include <stdint.h>

#include "base/Serializable.h"

class BinaryReader;
class BinaryWriter;

/** The class StationRecord represents a Station Record for the Applanix.
    \brief Station record
  */
class StationRecord :
  public Serializable {
  /// Reads from stream
  friend BinaryReader& operator >> (BinaryReader& stream, StationRecord& obj);
  /// Write stream operator
  friend BinaryWriter& operator << (BinaryWriter& stream, const StationRecord&
    obj);
public:
  /** \name Constructors/Destructor
    @{
    */
  /// Default constructor
  StationRecord();
  /// Copy constructor
  StationRecord(const StationRecord& other);
  /// Assignement operator
  StationRecord& operator = (const StationRecord& other);
  /// Destructor
  virtual ~StationRecord();
  /** @}
    */

  /** \name Members
    @{
    */
  /// Record index and flags
  uint8_t mRecordIndexAndFlags;
  /// Station ID
  uint16_t mStationID;
  /// Station health
  uint16_t mStationHealth;
  /// Distance
  float mDistance;
  /// Range
  float mRange;
  /// USCGI index
  uint8_t mUSCGIndex;
  /// Seconds
  uint64_t mSeconds;
  /// Modulation rate
  uint8_t mModulationRate;
  /** @}
    */

protected:
  /** \name Stream methods
    @{
    */
  /// Reads from standard input
  virtual void read(std::istream& stream);
  /// Writes to standard output
  virtual void write(std::ostream& stream) const ;
  /// Reads from a file
  virtual void read(std::ifstream& stream);
  /// Writes to a file
  virtual void write(std::ofstream& stream) const;
  /// Reads from stream
  virtual void read(BinaryReader& stream);
  /// Writes to the network
  virtual void write(BinaryWriter& stream) const;
  /** @}
    */

};

#endif // STATIONRECORD_H
