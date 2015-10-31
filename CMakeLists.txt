SET(PLUGIN_NAME CatalystLiveButtons)
SET(PLUGIN_VERSION "1.1")

INCLUDE_DIRECTORIES(
  ${VTK_INCLUDE_DIRS}
  )

SET(UI_FILES
  pqCatalystLiveButtonsActionHolder.ui
  )

SET(MOC_HEADERS
  pqCatalystLiveButtonsActionGroup.h
  pqCatalystLiveButtonsManager.h
  )

SET(CLIENT_SRCS
  pqCatalystLiveButtonsActionGroup.cxx
  pqCatalystLiveButtonsManager.cxx
  )

IF (PARAVIEW_BUILD_QT_GUI)

  IF (PARAVIEW_QT_VERSION VERSION_GREATER "4")
    SET (Qt5_FIND_COMPONENTS Widgets)
    INCLUDE (ParaViewQt5)
    QT5_WRAP_CPP(MOC_SRCS ${MOC_HEADERS})
    QT5_WRAP_UI(UI_SRCS ${UI_FILES})
  ELSE ()
    INCLUDE (${QT_USE_FILE})
    QT4_WRAP_CPP(MOC_SRCS ${MOC_HEADERS})
    QT4_WRAP_UI(UI_SRCS ${UI_FILES})
  ENDIF ()

  ADD_PARAVIEW_ACTION_GROUP(CatalystLiveButtons_TOOLBAR_IFACE CatalystLiveButtons_TOOLBAR_IFACE_SRCS
    CLASS_NAME pqCatalystLiveButtonsActionGroup
    GROUP_NAME "ToolBar/CatalystLiveButtons"
    )

  ADD_PARAVIEW_PLUGIN(${PLUGIN_NAME} ${PLUGIN_VERSION}
    GUI_INTERFACES ${CatalystLiveButtons_TOOLBAR_IFACE}
    GUI_RESOURCES CatalystLiveButtons.qrc
    SOURCES ${MOC_SRCS} ${UI_SRCS} ${CatalystLiveButtons_TOOLBAR_IFACE_SRCS} ${CLIENT_SRCS}
    )

ELSE ()
  ADD_PARAVIEW_PLUGIN(${PLUGIN_NAME} ${PLUGIN_VERSION}
    )
ENDIF ()

