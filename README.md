# Sokoban-Project-Sem-IV
## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)
* [Instructions](#instructions)
* [Controls](#controls)
* [Rules](#rules)
* [Level editing](#level-editing)
* [Screenshots](#screenshots)

## General info
This is simple sokoban game made in C++ using object oriented paradigm.

## Technologies
Project is created with:
* SFML (Simple and Fast Multimedia Library) 



## Setup
To run this project, compile project using makefile in main directory, and run binary file created in bin/ directory

```
cd project-directory/
make
cd bin/
./sfml-app
```

## Instructions

After the play button is pressed, the game starts. The game starts from level1. The main goal of the game is to
somehow push brown boxes onto blue plates, and then stand on the green exit.

After everything is in its place, the level is finished and the congratulations screen is displayed which lasts for 3
seconds, and then immediately level 2 is displayed

## Controls
* Up arrow - player goes up
* Down arrow - player goes down
* Left arrow - player goes left
* Right arrow - player goes right
* R button - restarts level


## Rules
* Player cannot walk into walls.
* Player can push a box.
* Player cannot push a box if behind it is another box or a wall.
* Keys can open doors. If the key is pushed into the door, door and key disappears.

## Level editing
The game levels are stored in a .dat file.
It consists of only numbers that reflect the tiles in a game.
If a player or a designer wants to create more levels, he should create new file, called level**.dat, where ** is a
number 1 higher than the highest currently in the directory.

## Screenshots

![](https://i.ibb.co/TRKYMwB/Screenshot-4.png)
![](https://i.ibb.co/VTqDDyb/Screenshot-5.png)
