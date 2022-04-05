# PersonalProjects
These are a few of my personal projects.
The Luxembourg project may have a few issues with the relative paths for the SFML framework and the boost files, but they can be easily fixed by:
-In the project properties , the Configuration is set to All Configurations
-In the C/C++ tab the Additional Include Directories should be set to ..\boost\boost_1_78_0;..\sfml\include
-In the Linker tab the Additional Library Directories should be set to ..\sfml\lib;..\boost\boost_1_78_0\stage\lib
-In the Linker tab , in the input sub directory the Configuration will need to look different for Release and Debug
-Debug should have the following Additional Dependencies: sfml-system-d.lib;sfml-graphics-d.lib;sfml-audio-d.lib;sfml-network-d.lib;sfml-window-d.lib;
-Release should have the following Additional Dependencies:sfml-system.lib;sfml-graphics.lib;sfml-audio.lib;sfml-network.lib;sfml-window.lib;
