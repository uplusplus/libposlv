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

/** \file SecondaryDataPortControl.h
    \brief This file defines the SecondaryDataPortControl class, which
           represents the Secondary Data Port Control message from the Applanix
  */

#ifndef SECONDARYDATAPORTCONTROL_H
#define SECONDARYDATAPORTCONTROL_H

#include <vector>

#include "types/Message.h"

/** The class SecondaryDataPortControl represents the Secondary Data Port
    Control message from the Applanix.
    \brief Secondary Data Port Control message
  */
class SecondaryDataPortControl :
  public Message {
public:
  /** \name Constructors/Destructor
    @{
    */
  /// Default constructor
  SecondaryDataPortControl();
  /// Copy constructor
  SecondaryDataPortControl(const SecondaryDataPortControl& other);
  /// Assignement operator
  SecondaryDataPortControl& operator = (const SecondaryDataPortControl& other);
  /// Destructor
  virtual ~SecondaryDataPortControl();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Returns a new prototype of this group
  virtual SecondaryDataPortControl* clone() const;
  /** @}
    */

  /** \name Members
    @{
    */
  /// Nominal number of bytes in the message
  static const uint16_t mByteCount = 10;
  /// Read byte count
  uint16_t mReadByteCount;
  /// Transaction number
  uint16_t mTransactionNumber;
  /// Number of groups selected for Display Port
  uint16_t mNumGroups;
  /// Groups ID to output
  std::vector<uint16_t> mGroupsIDVector;
  /// Output rate
  uint16_t mOutputRate;
  /// Prototype for this group
  static const SecondaryDataPortControl mProto;
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
  /// Reads from the network
  virtual void read(BinaryReader& stream);
  /// Writes to the network
  virtual void write(BinaryWriter& stream) const;
  /** @}
    */

};

#endif // SECONDARYDATAPORTCONTROL_H
