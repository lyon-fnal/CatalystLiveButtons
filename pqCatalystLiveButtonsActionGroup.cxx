// -*- c++ -*-


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
