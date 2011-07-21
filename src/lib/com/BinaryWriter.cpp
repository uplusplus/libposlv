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

#include "com/BinaryWriter.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

BinaryWriter::BinaryWriter() {
}

BinaryWriter::BinaryWriter(const BinaryWriter& other) {
}

BinaryWriter& BinaryWriter::operator = (const BinaryWriter& other) {
  if (this != &other) {
  }
  return *this;
}

BinaryWriter::~BinaryWriter() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

BinaryWriter& BinaryWriter::operator << (int8_t value) {
  writeBuffer((uint8_t*)&value, sizeof(int8_t));
  return *this;
}

BinaryWriter& BinaryWriter::operator << (uint8_t value) {
  writeBuffer((uint8_t*)&value, sizeof(uint8_t));
  return *this;
}

BinaryWriter& BinaryWriter::operator << (int16_t value) {
  writeBuffer((uint8_t*)&value, sizeof(int16_t));
  return *this;
}

BinaryWriter& BinaryWriter::operator << (uint16_t value) {
  writeBuffer((uint8_t*)&value, sizeof(uint16_t));
  return *this;
}

BinaryWriter& BinaryWriter::operator << (int32_t value) {
  writeBuffer((uint8_t*)&value, sizeof(int32_t));
  return *this;
}

BinaryWriter& BinaryWriter::operator << (uint32_t value) {
  writeBuffer((uint8_t*)&value, sizeof(uint32_t));
  return *this;
}

BinaryWriter& BinaryWriter::operator << (int64_t value) {
  writeBuffer((uint8_t*)&value, sizeof(int64_t));
  return *this;
}

BinaryWriter& BinaryWriter::operator << (uint64_t value) {
  writeBuffer((uint8_t*)&value, sizeof(uint64_t));
  return *this;
}

BinaryWriter& BinaryWriter::operator << (float value) {
  writeBuffer((uint8_t*)&value, sizeof(float));
  return *this;
}

BinaryWriter& BinaryWriter::operator << (double value) {
  writeBuffer((uint8_t*)&value, sizeof(double));
  return *this;
}