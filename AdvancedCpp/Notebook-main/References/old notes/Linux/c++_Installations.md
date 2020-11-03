# Install commands

## Update the package and the dependencies:
    $ sudo apt-get update
    $ sudo apt-get dist-upgrade
    
## Install bulid essential:
    $ sudo apt update
    $ sudo apt install build-essential

## Cmake file Install
    $ sudo apt-get install build-essential cmake

## Install gdb:
    $ sudo apt-get install gdb

## Install cppcheck​ :
    $ sudo apt-get install cppcheck

## Install valgrind :
    $ sudo apt-get install valgrind

##  Install git:
    $ sudo apt install git-all

## Ubuntu Google Test Installation Guide
    $ sudo apt-get install libgtest-dev                 # 1. Library Installation Commands
    $ cd /usr/src/gtest                                 # 2. Change Directory to Gtest 
    $ sudo cmake CMakeLists.txt                         # 3. Generate Make file
    $ sudo make                                         # 4. run make file
        
## OS UPdate to 20.04
    $ cat /etc/lsb-release                             # Verify Update
    $ sudo apt update
    $ sudo apt upgrade -y
    $ sudo reboot
    $ sudo apt --purge autoremove
    $ sudo apt install update-manager-core -y
    $ sudo do-release-upgrade
    $ sudo do-release-upgrade -d

sudo apt-get update && sudo apt-get dist-upgrade
sudo dpkg --configure -a

## Playonlinux for Documentation
    sudo apt-get install playonlinux winbind -y
    
### Reference links :
  https://www.srcmake.com/home/google-cpp-test-framework
  https://www.youtube.com/watch?v=kuglfQf17SA
  https://www.linuxtechi.com/upgrade-ubuntu-18-04-lts-to-ubuntu-20-04-lts/
  https://code.visualstudio.com/docs/setup/linux
