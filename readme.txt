POLARBEAR - Unreal Engine 5 Project

# Introduction
Welcome to POLARBEAR, an Unreal Engine 5 (UE5) game project! This project is a ["A First Person Horror Esacpe Game"]. This README will walk you through setting up, running, and packaging the game on your system.

# Prerequisites
Ensure your system meets these requirements before starting:

- Hardware:
  -Powerful enough to run Unreal Engine 5

- Software:
  - Epic Games Launcher: Install from [epicgames.com](https://www.epicgames.com/).
  - Unreal Engine 5: Install via the Epic Games Launcher (this project uses version [e.g., 5.5.4]).
  - C++ Development Environment (choose one):
    - Visual Studio 2022: Get it at [visualstudio.microsoft.com](https://visualstudio.microsoft.com/). Select the "Game development with C++" workload.
    - Rider IDE: Available at [jetbrains.com/rider](https://www.jetbrains.com/rider/).[I Used this for Development]



# Executing the Game
Follow these steps to run the game in the Unreal Engine editor:

1. Generate Project Files:
   - Find the `POLARBEAR.uproject` file in the project folder.
   - Right-click it and choose "Generate Visual Studio project files". This creates a `.sln` file for building.

2. Build the Project:
   - Open the `.sln` file in Visual Studio 2022 or Rider.
   - Build it: Build > Build Solution (or `Ctrl+Shift+B` in Visual Studio).
   - Wait for the build to finish (required for C++ code).

3. Open in Unreal Engine:
   - Double-click `POLARBEAR.uproject` to launch the UE5 editor.
   - Alternatively, use the Epic Games Launcher’s Library tab to open it.

4. Play the Game:
   - In the editor, hit the Play button in the toolbar to start the game.
   - Use the editor to test or tweak as needed.



#Packaging the Game
To create a standalone version (e.g., for Windows):

1. Open the Project:
   - Load the project in the Unreal Engine editor.

2. Package It:
   - Go to the Platforms menu in the toolbar.
   - Select your platform (e.g., Windows).
   - Click Package Project, choose a build type (e.g., Shipping), and pick an output folder.
   - Wait for packaging to complete—files will appear in the chosen directory.



#Troubleshooting
Run into problems? Try these fixes:

- **Project Won’t Open**:
  - Confirm you’re using UE5 version .
  - If it still fails, create a new UE5 project named "POLARBEAR" with the same version, then replace its `Content`, `Source`, and `Config` folders with this project’s versions.

- Missing Files or Errors:
  - Verify all folders (`Content`, `Source`, `Config`, etc.) are present.
  - Check for missing plugins in the `Plugins` folder if errors mention dependencies.

- Build Fails:
  - Ensure your C++ IDE (Visual Studio or Rider) is installed correctly.
  - Regenerate project files by right-clicking the `.uproject` file.

- Slow Performance:
  -UE5 is demanding—check your hardware against the prerequisites.
  -Close other apps to free up resources.

#Additional Tips
-Sharing: Zip the full project folder or use a file-sharing service (it’s large!).
-Engine Version: Stick to the version this project was built with to avoid issues.
-If Everything Fails Use ChatGpt,Grok etc prompt -> "How to Run a Zipped Project of Unreal Engine 5 in Another Machine "
#Key Mappings of Game
-i keyboard for help UI 
-W,A,S,D forward,left,backward,right 
-mouse to change camera angle
-F to turn on/off flashlight 
-Left click for interaction

