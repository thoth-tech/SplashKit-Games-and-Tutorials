# SplashKit Games and Tutorials
 
## Overview
Here, we will create a game using SplashKit SDK, along with a comprehensive tutorial. When we select the game to be developed, we will focus on how we can apply most of the functionalities available in the splashkit SDK. We will focus on the best practice of C++ programing and principles of secure coding.

In the development of tutorial, we will try to explain the concepts and the codes as simple as possible. We will target this tutorial to absolute beginners, so it will lead new programmers into game development.

**Data Types Definition**

**Introduction**

This document will provide detailed definitions of data types used in
this the game.

In developing the game, we have created several user-defined data types
using the C++ structure

which holds different properties in procedural version of the game.

![image](https://user-images.githubusercontent.com/68922962/230660137-f3a8cc1c-21d5-4ba6-8f2f-12549872e447.png)


**User Defined Data Types:**

*[Struct:]

Structures (also called structs) are a way to group several related
variables into one place. Structures

are used to create different objects in procedural version of the game.

> • Game
>
> • World
>
> • Player
>
> • Obstacle
>
> • Coin
>
> • Treasure

*[Enum:]{.underline}*

An enumeration is a user-defined data type that consists of integral
constants. Enumeration is used

to predefine the types of Obstacles and the Treasures in the game.

> • Obstacle_Type
>
> • Treasure_Type

**Game:**\
Game is parent structure, which hold other structures and global game
data.![1111](https://user-images.githubusercontent.com/68922962/230660876-5bacf7ee-c274-4bc6-a274-99e621d26c17.JPG)


**World:**\
World is the level which player is playing, which also a structure
contains all the variables.

![2](https://user-images.githubusercontent.com/68922962/230661076-c927e28e-3a62-424d-8ce0-896ec1af537a.JPG)


**Player:**

Player is the structure of the main character sprite.
![3](https://user-images.githubusercontent.com/68922962/230661229-0e9ff216-0bcb-4ee0-bd13-ab95b21f8d07.JPG)


**Obstacle:**

Obstacle is the structure of the enemy sprite.

![image](https://user-images.githubusercontent.com/68922962/230661359-47dad486-9177-4b8b-8935-f9df4953fc84.png)


**Coin:**

Coin is the structure of the gold coin sprite.

![5](https://user-images.githubusercontent.com/68922962/230661479-5b4acf95-e7b7-4348-a3ef-808f0961a4c2.JPG)


**Treasure:**\
Treasure is the structure of the treasure sprite.
![6](https://user-images.githubusercontent.com/68922962/230661582-ebdae5e8-4452-4fa5-86a2-5f5e3cd652e4.JPG)

