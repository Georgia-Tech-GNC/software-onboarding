## GNC Software Onboarding

### Setup Instructions
Start by installing GCC using the os-specific instructions below. Then follow along with the general development setup instructions at the bottom.

#### Windows Instructions
1. Install Windows Subsystem for Linux (WSL) by running this command in powershell: `wsl --install`. You may be prompted to restart your laptop.
2. Open the newly-installed WSL app from the start bar. If you are prompted to type in a username and password, do so. The username and password you use does not have to match your laptop password. However, you will need to remember this password in order to log in. The password may not appear on the screen when you type it--this is normal.
3. Run the command `sudo apt update` and then the command `sudo apt upgrade` in WSL.
4. Install GCC by running `sudo apt-get install gcc -y` in WSL.
5. Run `gcc --version` to ensure that it was installed successfully.
    1. If this command fails, try step 4 again with the command `sudo apt install gcc -y`
6. From now on, all commands should be run inside WSL, not the normal powershell window.

#### MacOS Instructions
1. Install homebrew by running `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"` and following the steps on the screen. If prompted to install xcode-select, hit install.
2. Restart your terminal app, and then run `brew install gcc`
3. Run `gcc --version` to verify that GCC was installed successfully.
4. Run `brew install git` to install git.
5. Run

#### Linux Instructions
1. Run `sudo apt install gcc` in the terminal. You may need to run `sudo apt-get update` and `sudo apt-get upgrade` first.
2. Run `gcc --version` to verify that GCC was installed successfully.

Note that different linux distros may use different package managers.

#### Developement Setup
1. Install git from <https://git-scm.com/downloads>
2. Install VSCode from <https://code.visualstudio.com/download>
3. Open VSCode, navigate to the extensions tab (the 4 boxes on the left hand navigation bar), and search for C/C++. Install this extension (it should be from Microsoft).
4. Open a new VSCode project in new folder and clone the repository by running `git clone ...`



