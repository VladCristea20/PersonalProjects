# PersonalProjects
These are a few of my personal projects.

The project may come with a few errors for the relative paths of the aditional include libraries and such.
I will leave a few instructions as to how to fix all the possible issues.
In the project properties :
-the c/c++ sub property should have the Aditional Include Directories set to the relative paths of "..\sfml\include;" ; The setting should be in All configurations mode
-the linker sub property should have the Aditional Library Directories set to the relative paths of "..\sfml\lib;" ;The setting should be in All configurations mode
-In Linker, in the input section , the Aditional Dependecies should be set to "sfml-system-d.lib;sfml-graphics-d.lib;sfml-audio-d.lib;sfml-network-d.lib;sfml-window-d.lib;" for Debug
- and "sfml-system.lib;sfml-graphics.lib;sfml-audio.lib;sfml-network.lib;sfml-window.lib" for Release
- The app should be run in Debug x86 since it's not a finished product and the dll's are set for it to run that way.

