// -*- c++ -*-
/*=========================================================================
 CatalystLiveButtons - Adam L. Lyon, October 2015
 Fermitools License https://cdcvs.fnal.gov/redmine/projects/fermitools/wiki
 
 Derived from SLACTools and ParaView code.
 See Copyright & License notices therein.
 
 =========================================================================*/


#include "pqCatalystLiveButtonsActionGroup.h"

#include "pqCatalystLiveButtonsManager.h"

//=============================================================================
pqCatalystLiveButtonsActionGroup::pqCatalystLiveButtonsActionGroup(QObject *p) : QActionGroup(p)
{
  pqCatalystLiveButtonsManager *manager = pqCatalystLiveButtonsManager::instance();
  if (!manager)
    {
    qFatal("Cannot get CatalystLiveButtons manager.");
    return;
    }

  this->addAction(manager->actionConnect());
  this->addAction(manager->actionSingleStep());

  // Action groups are usually used to establish radio-button like
  // functionality.  We don't really want that, so turn it off.
  this->setExclusive(false);
}
