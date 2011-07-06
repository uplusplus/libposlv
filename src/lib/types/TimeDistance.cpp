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

#include "types/TimeDistance.h"

#include "com/Connection.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

TimeDistance::TimeDistance() {
}

TimeDistance::TimeDistance(const TimeDistance& other) {
}

TimeDistance& TimeDistance::operator = (const TimeDistance& other) {
  return *this;
}

TimeDistance::~TimeDistance() {
}

/******************************************************************************/
/* Stream operations                                                          */
/******************************************************************************/

void TimeDistance::read(Connection& stream) {
  stream >> mTime1;
  stream >> mTime2;
  stream >> mDistanceTag;
  stream >> mTimeType;
  stream >> mDistanceType;
}

void TimeDistance::read(std::istream& stream) {
}

void TimeDistance::write(std::ostream& stream) const {
}

void TimeDistance::read(std::ifstream& stream) {
}

void TimeDistance::write(std::ofstream& stream) const {
//  stream << mf64Time1;
//  stream << " ";
//  stream << mf64Time2;
//  stream << " ";
//  stream << mf64DistanceTag;
//  stream << " ";
//  stream << hex << (uint16_t)mu8TimeType << dec;
//  stream << " ";
//  stream << hex << (uint16_t)mu8DistanceType << dec;
//  stream << " ";
}

Connection& operator >> (Connection& stream, TimeDistance& obj) {
  obj.read(stream);
  return stream;
}