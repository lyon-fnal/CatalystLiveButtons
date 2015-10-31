// -*- c++ -*-
/*=========================================================================
 CatalystLiveButtons - Adam L. Lyon, October 2015
 Fermitools License https://cdcvs.fnal.gov/redmine/projects/fermitools/wiki
 
 Derived from SLACTools and ParaView code. 
 See Copyright & License notices therein.
 
 =========================================================================*/
#include "pqCatalystLiveButtonsManager.h"


#include "pqActiveObjects.h"
#include "pqApplicationCore.h"

#include "pqLiveInsituManager.h"
#include "pqLiveInsituVisualizationManager.h"
#include "pqServer.h"
#include "vtkSMLiveInsituLinkProxy.h"
#include "vtkSMPropertyHelper.h"

#include <QMainWindow>
#include <QPointer>
#include <QtDebug>

#include "ui_pqCatalystLiveButtonsActionHolder.h"

//=============================================================================
class pqCatalystLiveButtonsManager::pqInternal
{
public:
  Ui::pqCatalystLiveButtonsActionHolder Actions;
  QWidget *ActionPlaceholder;
};

//=============================================================================
QPointer<pqCatalystLiveButtonsManager> pqCatalystLiveButtonsManagerInstance = NULL;

pqCatalystLiveButtonsManager *pqCatalystLiveButtonsManager::instance()
{
  if (pqCatalystLiveButtonsManagerInstance == NULL)
    {
    pqApplicationCore *core = pqApplicationCore::instance();
    if (!core)
      {
      qFatal("Cannot use the CatalystLiveButtons Tools without an application core instance.");
      return NULL;
      }

    pqCatalystLiveButtonsManagerInstance = new pqCatalystLiveButtonsManager(core);
    }

  return pqCatalystLiveButtonsManagerInstance;
}

//-----------------------------------------------------------------------------
pqCatalystLiveButtonsManager::pqCatalystLiveButtonsManager(QObject *p) : QObject(p)
{
  this->Internal = new pqCatalystLiveButtonsManager::pqInternal;

  // This widget serves no real purpose other than initializing the Actions
  // structure created with designer that holds the actions.
  this->Internal->ActionPlaceholder = new QWidget(NULL);
  this->Internal->Actions.setupUi(this->Internal->ActionPlaceholder);

  QObject::connect(this->actionConnect(), SIGNAL(triggered(bool)),
                   this, SLOT(doConnect()));
  QObject::connect(this->actionSingleStep(), SIGNAL(triggered(bool)),
                   this, SLOT(doSingleStep()));
}

pqCatalystLiveButtonsManager::~pqCatalystLiveButtonsManager()
{
  delete this->Internal->ActionPlaceholder;
  delete this->Internal;
}

//-----------------------------------------------------------------------------
QAction *pqCatalystLiveButtonsManager::actionSingleStep()
{
  return this->Internal->Actions.actionSingleStep;
}

QAction *pqCatalystLiveButtonsManager::actionConnect()
{
  return this->Internal->Actions.actionConnect;
}

void pqCatalystLiveButtonsManager::doConnect() {
  pqLiveInsituManager* insitu = pqLiveInsituManager::instance();
  pqServer* server = pqActiveObjects::instance().activeServer();
  pqLiveInsituVisualizationManager* mgr = insitu->connect(server);
  if ( mgr ) {
    // Put into paused state
    vtkSMLiveInsituLinkProxy* linkProxy = insitu->linkProxy();
    if ( linkProxy ) {
      vtkSMPropertyHelper(linkProxy, "SimulationPaused").Set(true);
      linkProxy->UpdateVTKObjects();
    }
  }
}

void pqCatalystLiveButtonsManager::doSingleStep() {
  
  // Get the live insitu manager
  pqLiveInsituManager* insitu = pqLiveInsituManager::instance();
  
  // Are we connected to Catalyst?
  if ( insitu->selectedInsituServer() ) {

    // Determine state of link (paused or running)
    vtkSMLiveInsituLinkProxy* linkProxy = insitu->linkProxy();
    
    if ( linkProxy ) {
      
      // Are we paused (note that we may not have stopped at a time step yet)
      if ( vtkSMPropertyHelper(linkProxy, "SimulationPaused").GetAsInt() ) {
        
        pqLiveInsituVisualizationManager* visManager =
          insitu->managerFromInsitu(insitu->selectedInsituServer());
        
        // Continue ( see ParaView/Qt/ApplicationComponents/pqCatalystPauseSimulationReaction.cxx )
        vtkSMPropertyHelper(linkProxy, "SimulationPaused").Set(false);
        linkProxy->UpdateVTKObjects();
        linkProxy->InvokeCommand("LiveChanged");
        
        // Run the event loop so that the simulations starts running again.
        // The simulation can't be super fast - must have at least a tenth of a
        // second delay between time steps.
        
        QEventLoop loop;
        QObject::connect(visManager, SIGNAL(nextTimestepAvailable()),
                         &loop, SLOT(quit()));
        loop.exec();

        // And pause
        vtkSMPropertyHelper(linkProxy, "SimulationPaused").Set(true);
        linkProxy->UpdateVTKObjects();
      }
    }
  }
}

