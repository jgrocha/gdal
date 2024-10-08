/******************************************************************************
 *
 * Project:  KML Translator
 * Purpose:  Implements OGRLIBKMLDriver
 * Author:   Brian Case, rush at winkey dot org
 *
 ******************************************************************************
 * Copyright (c) 2010, Brian Case
 * Copyright (c) 2014, Even Rouault <even dot rouault at spatialys.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *****************************************************************************/

#ifndef OGRLIBKMLFIELD_H_INCLUDED
#define OGRLIBKMLFIELD_H_INCLUDED

#include "fieldconfig.h"

/******************************************************************************
 Function to output ogr fields in kml.

 args:
        poOgrFeat       pointer to the feature the field is in
        poOgrLayer      pointer to the layer the feature is in
        poKmlFactory    pointer to the libkml dom factory
        poKmlPlacemark  pointer to the placemark to add to

 returns:
        nothing

 env vars:
  LIBKML_TIMESTAMP_FIELD         default: OFTDate or OFTDateTime named timestamp
  LIBKML_TIMESPAN_BEGIN_FIELD    default: OFTDate or OFTDateTime named begin
  LIBKML_TIMESPAN_END_FIELD      default: OFTDate or OFTDateTime named end
  LIBKML_DESCRIPTION_FIELD       default: none
  LIBKML_NAME_FIELD              default: OFTString field named name

******************************************************************************/

#include "ogr_libkml.h"

void field2kml(OGRFeature *poOgrFeat, OGRLIBKMLLayer *poOgrLayer,
               kmldom::KmlFactory *poKmlFactory,
               kmldom::FeaturePtr poKmlPlacemark, int bUseSimpleField,
               const fieldconfig &oFC);

/******************************************************************************
 Function to read kml into ogr fields.
******************************************************************************/

void kml2field(OGRFeature *poOgrFeat, kmldom::FeaturePtr poKmlFeature,
               const fieldconfig &oFC);

/******************************************************************************
 Function create a simplefield from a FieldDefn.
******************************************************************************/

kmldom::SimpleFieldPtr FieldDef2kml(const OGRFieldDefn *poOgrFieldDef,
                                    kmldom::KmlFactory *poKmlFactory,
                                    bool bApproxOK, const fieldconfig &oFC);

/******************************************************************************
 Function to add the simpleFields in a schema to a featuredefn.
******************************************************************************/

void kml2FeatureDef(kmldom::SchemaPtr poKmlSchema,
                    OGRFeatureDefn *poOgrFeatureDefn);

int kmlAltitudeModeFromString(const char *pszAltitudeMode, int &isGX);

#endif /* OGRLIBKMLFIELD_H_INCLUDED */
