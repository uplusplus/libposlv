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

/** \file GeneralInstallationControl.h
    \brief This file defines the GeneralInstallationControl class, which
           represents the General Installation Control message from the Applanix
  */

#ifndef GENERALINSTALLATIONCONTROL_H
#define GENERALINSTALLATIONCONTROL_H

#include "types/Message.h"
#include "exceptions/IOException.h"

/** The class GeneralInstallationControl represents the General Installation
    Control message from the Applanix.
    \brief General Installation Control message
  */
class GeneralInstallationControl :
  public Message {
public:
  /** \name Constructors/Destructor
    @{
    */
  /// Default constructor
  GeneralInstallationControl();
  /// Copy constructor
  GeneralInstallationControl(const GeneralInstallationControl& other);
  /// Assignement operator
  GeneralInstallationControl& operator =
    (const GeneralInstallationControl& other);
  /// Destructor
  virtual ~GeneralInstallationControl();
  /** @}
    */

  /** \name Methods
    @{
    */
  /// Returns a new prototype of this group
  virtual GeneralInstallationControl* clone() const;
  /** @}
    */

  /** \name Members
    @{
    */
  /// Nominal number of bytes in the message
  static const uint16_t mByteCount = 84;
  /// Transaction number
  uint16_t mTransactionNumber;
  /// Time types
  uint8_t mTimeTypes;
  /// Distance type
  uint8_t mDistanceType;
  /// Select/deselect AutoStart
  uint8_t mAutoStart;
  /// Reference to IMU X lever arm
  float mRefIMUX;
  /// Reference to IMU Y lever arm
  float mRefIMUY;
  /// Reference to IMU Z lever arm
  float mRefIMUZ;
  /// Reference to Primary GPS X lever arm
  float mRefPrimGPSX;
  /// Reference to Primary GPS Y lever arm
  float mRefPrimGPSY;
  /// Reference to Primary GPS Z lever arm
  float mRefPrimGPSZ;
  /// Reference to Auxiliary 1 GPS X lever arm
  float mRefAux1GPSX;
  /// Reference to Auxiliary 1 GPS Y lever arm
  float mRefAux1GPSY;
  /// Reference to Auxiliary 1 GPS Z lever arm
  float mRefAux1GPSZ;
  /// Reference to Auxiliary 2 GPS X lever arm
  float mRefAux2GPSX;
  /// Reference to Auxiliary 2 GPS Y lever arm
  float mRefAux2GPSY;
  /// Reference to Auxiliary 2 GPS Z lever arm
  float mRefAux2GPSZ;
  /// X IMU wrt Reference frame mounting angle
  float mXIMURefMountingAngle;
  /// Y IMU wrt Reference frame mounting angle
  float mYIMURefMountingAngle;
  /// Z IMU wrt Reference frame mounting angle
  float mZIMURefMountingAngle;
  /// X Reference frame wrt Vehicle frame mounting angle
  float mXRefVehicleMountingAngle;
  /// Y Reference frame wrt Vehicle frame mounting angle
  float mYRefVehicleMountingAngle;
  /// Z Reference frame wrt Vehicle frame mounting angle
  float mZRefVehicleMountingAngle;
  /// Multipath environment
  uint8_t mMultipathEnvironment;
  /// Prototype for this group
  static const GeneralInstallationControl mProto;
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
  virtual void read(POSLVMessageRead& stream) throw (IOException);
  /// Writes to the network
  virtual void write(POSLVMessageWrite& stream) const;
  /** @}
    */

};

#endif // GENERALINSTALLATIONCONTROL_H