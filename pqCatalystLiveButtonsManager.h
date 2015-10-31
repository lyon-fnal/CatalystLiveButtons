// -*- c++ -*-
/*=========================================================================

  Program:   Visualization Toolkit
  Module:    pqCatalystLiveButtonsManager.h

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

#ifndef __pqCatalystLiveButtonsManager_h
#define __pqCatalystLiveButtonsManager_h

#include <QObject>

class QAction;


//#define AUTO_FIND_TEMPORAL_RANGE

/// This singleton class manages the state associated with the packaged
/// visualizations provided by the CatalystLiveButtons tools.
class pqCatalystLiveButtonsManager : public QObject
{
  Q_OBJECT;
public:
  static pqCatalystLiveButtonsManager *instance();

  ~pqCatalystLiveButtonsManager();

  /// Get the action for the respective operation.
  QAction *actionConnect();
  QAction *actionSingleStep();


public slots:
  void doConnect();
  void doSingleStep();
  

protected:
 
private:
  pqCatalystLiveButtonsManager(QObject *p);

  class pqInternal;
  pqInternal *Internal;

  pqCatalystLiveButtonsManager(const pqCatalystLiveButtonsManager &);         // Not implemented
  void operator=(const pqCatalystLiveButtonsManager &);        // Not implemented
};

#endif //__pqCatalystLiveButtonsManager_h
