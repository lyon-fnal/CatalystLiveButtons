// -*- c++ -*-
/*=========================================================================
 CatalystLiveButtons - Adam L. Lyon, October 2015
 Fermitools License https://cdcvs.fnal.gov/redmine/projects/fermitools/wiki
 
 Derived from SLACTools and ParaView code.
 See Copyright & License notices therein.
 
 =========================================================================*/

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
