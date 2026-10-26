# A.I.M. 2 - Revision

A.I.M. 2 - Revision is an ongoing project dedicated to realizing more of the original game's potential. By combining gameplay improvements, expanded content, deeper storytelling, more engaging battles and enhanced visuals, the project aims to deliver a more complete and immersive A.I.M. 2: Clan Wars experience

## Goals/Improvements

- Content — Introduce new content and expand existing features.
- Storyline — Expand and develop existing storylines.
- Engaging battles — Improved weapons, better equipment, upgrades, harder enemies and more!
- Enhanced Visuals — Improve the graphical presentation through **_AimFX_** post-processing, featuring configurable effects.
- Technical Enhancements — Utilize custom DLL-based graphics enhancements and Direct3D 8-to-Direct3D 9 compatibility technology to support the visual improvements and modernize the game's rendering pipeline.

## AimFX.ini

A custom configuration file for the game's post-processing effects. It allows customization of visual effects such as motion blur, bloom, heat distortion, anti-aliasing, sharpening, color adjustments, depth effects, and sun rays.

## d3d8.dll

A custom Direct3D 8-to-Direct3D 9 wrapper created just for A.I.M. 2: Clan Wars, it translates Direct3D 8 calls into Direct3D 9-compatible operations. It provides AimFX post-processing effects to enhance the game's visuals. 

Created with: https://github.com/crosire/d3d8to9

## fix.bat

A script created to fix game crashes, can be found in **_bat_** directory, copy it and paste it in game directory, not in **_Data_** directory! make a shortcut to it on desktop and next time you want to run the game without facing crashes, run that shortcut. 

Created with: https://github.com/crosire/d3d8to9

## How to load A.I.M. 2 - Revision

- [Download ZIP](https://github.com/kamarov-therussiantank/AIM2-Revision/archive/refs/heads/main.zip)
- Extract
- Make a copy of your game directory (just in case if something goes wrong)
- Copy/paste **_Data_** directory inside game directory
- Delete **_AIMBIN_** and **_AIMLOC_** _.pak_ files
- Copy/paste files from **_dll_** and **_AimFX_** directories inside game diretory