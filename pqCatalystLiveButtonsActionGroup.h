// -*- c++ -*-
/*=========================================================================
 CatalystLiveButtons - Adam L. Lyon, October 2015
 Fermitools License https://cdcvs.fnal.gov/redmine/projects/fermitools/wiki
 
 Derived from SLACTools and ParaView code.
 See Copyright & License notices therein.
 
 =========================================================================*/

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
