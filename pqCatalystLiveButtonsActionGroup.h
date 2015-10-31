// -*- c++ -*-
/*=========================================================================

  Program:   Visualization Toolkit
  Module:    pqCatalystLiveButtonsActionGroup.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/*-------------------------------------------------------------------------
  Copyright 2009 Sandia Corporation.
  Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
  the U.S. Government retains certain rights in this software.
-------------------------------------------------------------------------*/

#ifndef __pqCatalystLiveButtonsActionGroup_h
#define __pqCatalystLiveButtonsActionGroup_h

#include <QActionGroup>

/// Adds actions that are helpful for setting up visualization of CatalystLiveButtons
/// simulation result files.
class pqCatalystLiveButtonsActionGroup : public QActionGroup
{
  Q_OBJECT;
public:
  pqCatalystLiveButtonsActionGroup(QObject *p);

private:
  pqCatalystLiveButtonsActionGroup(const pqCatalystLiveButtonsActionGroup &);     // Not implemented
  void operator=(const pqCatalystLiveButtonsActionGroup &);        // Not implemented
};

#endif //__pqCatalystLiveButtonsActionGroup_h
