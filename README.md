# CatalystLiveButtons
ParaView Plugin - Some convenience buttons for Catalyst Live and ParaView

Adam L. Lyon (Fermi National Accelerator Laboratory/October 2015)

This ParaView plugin (tested with ParaView 4.4) brings up a toolbar with two buttons. The icons for the buttons are "borrowed"
from the ParaView "VCR" buttons. I need to make better icons one day. 

Connection button: ![ConnectionButton](https://github.com/lyon-fnal/CatalystLiveButtons/blob/master/Icons/connect.png) Clicking 
this button will bring up the connection dialog box. Once accepted, a Catalyst Live connection will be established. As an added feature, Catalyst Live will automatically pause on the first time step. 

Single step button: ![SingleStep](https://github.com/lyon-fnal/CatalystLiveButtons/blob/master/Icons/SingleStep.png) If Catalyst
Live is paused (thus pausing the simulation), then clicking on this button will allow the simulation to continue to the next
time step where it will be paused again. Using this button, you can "single step" through the time steps. 

Some caveats: If the simulation is very fast, then more than one time step may go by before the simulation is paused again on a Single Step. I had experimented with setting breakpoints, but these always seem to skip to one time step passed the desired one (need to open a bug report). If you are seeing this problem, have your simulation introduce a small delay (I use 0.1 sec). 

This code is derived from similar routines in ParaView and the SLACTools plugin. The [FermiTools](https://cdcvs.fnal.gov/redmine/projects/fermitools/wiki) license may apply here, as well as licenses covering the base routines. 

## Installation

The easiest way to install this plugin is to build your own ParaView with this repository checked out the `ParaView/Plugins` directory. You will need to set 

```
-DPARAVIEW_BUILD_PLUGIN_CatalystLiveButtons=ON
```

when you run `cmake`. Be sure to activate the plugin from the `Tools->Manage Plugins` menu option. 
