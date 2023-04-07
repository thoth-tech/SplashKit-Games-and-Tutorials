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

  ---------------------------------------------------------------------------------------------
  ---------------------------------------------------------------------------------------------

  ---------------------------------------------------------------------------------------------

**User Defined Data Types:**

*[Struct:]{.underline}*

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
data.

+-----------------------+-----------------------+-----------------------+
| > **Variable**        | > **Data Type**       | > **Definition**      |
+=======================+=======================+=======================+
| > World               | > World               | > This is a structure |
|                       |                       | > which hold the      |
|                       |                       | > properties of the   |
|                       |                       | > level               |
+-----------------------+-----------------------+-----------------------+
| > Status              | > Bool                | > This Boolean        |
|                       |                       | > variable holds      |
|                       |                       | > binary value which  |
|                       |                       | > defines the status  |
|                       |                       | > of the game         |
+-----------------------+-----------------------+-----------------------+

**World:**\
World is the level which player is playing, which also a structure
contains all the variables.

+-----------------------+-----------------------+-----------------------+
| > **Variable**        | > **Data Type**       | > **Definition**      |
+=======================+=======================+=======================+
| > Player              | > Player              | > This is a structure |
|                       |                       | > which hold the      |
|                       |                       | > properties of the   |
|                       |                       | > player              |
+-----------------------+-----------------------+-----------------------+
| > Obstacles           | > vector\<obstacle\>  | > This is a vector    |
|                       |                       | > obstacle structure  |
|                       |                       | > as single world can |
|                       |                       | > have more than one  |
|                       |                       | > obstacle.           |
+-----------------------+-----------------------+-----------------------+
| > Coins               | > vector\<coin\>      | > This is a vector    |
|                       |                       | > coin structure as   |
|                       |                       | > single world can    |
|                       |                       | > have more than one  |
|                       |                       | > coin.               |
+-----------------------+-----------------------+-----------------------+
| > Treasure            | > vector\<treasure\>  | > This is a vector    |
|                       |                       | > treasure structure  |
|                       |                       | > as single world can |
|                       |                       | > have more than one  |
|                       |                       | > treasure.           |
+-----------------------+-----------------------+-----------------------+
| > Background_X        | > Double              | > This variable holds |
|                       |                       | > the value of X      |
|                       |                       | > position of the     |
|                       |                       | > background.         |
+-----------------------+-----------------------+-----------------------+
| Background_Y          | > Double              | > This variable holds |
| \[double\]            |                       | > the value of Y      |
|                       |                       | > position of the     |
|                       |                       | > background.         |
+-----------------------+-----------------------+-----------------------+
| > Score               | > Integer             | > This variable holds |
|                       |                       | > the value of the    |
|                       |                       | > score of the        |
|                       |                       | > current level.      |
+-----------------------+-----------------------+-----------------------+
| > Backgroud_Static    | > Bitmap              | > This variable holds |
|                       |                       | > the image of the    |
|                       |                       | > static background   |
|                       |                       | > which does not move |
|                       |                       | > along with the      |
|                       |                       | > player.             |
+-----------------------+-----------------------+-----------------------+
| > Backgroud_Dynamic   | > Bitmap              | > This variable holds |
|                       |                       | > the image of the    |
|                       |                       | > dynamic background  |
|                       |                       | > which moves along   |
|                       |                       | > with the player.    |
+-----------------------+-----------------------+-----------------------+
| > Backgroud_Sound     | > String              | > This variable holds |
|                       |                       | > the name of the     |
|                       |                       | > background music.   |
+-----------------------+-----------------------+-----------------------+
| > Status              | > Bool                | > This Boolean        |
|                       |                       | > variable holds      |
|                       |                       | > binary value which  |
|                       |                       | > defines the status  |
|                       |                       | > of the current      |
|                       |                       | > level               |
+-----------------------+-----------------------+-----------------------+
| > Game_Timer          | > Integer             | > This variable holds |
|                       |                       | > the elapsed time of |
|                       |                       | > the current level.  |
+-----------------------+-----------------------+-----------------------+
| > Camera_Move         | > Integer             | > This variable holds |
|                       |                       | > the value of camera |
|                       |                       | > position which is   |
|                       |                       | > used to position    |
|                       |                       | > the background and  |
|                       |                       | > other dynamic       |
|                       |                       | > objects on the      |
|                       |                       | > scene.              |
+-----------------------+-----------------------+-----------------------+

**Player:**

Player is the structure of the main character sprite.

+-----------------------+-----------------------+-----------------------+
| > **Variable**        | > **Data Type**       | > **Definition**      |
+=======================+=======================+=======================+
| > Life                | > Integer             | > This variable holds |
|                       |                       | > the value of        |
|                       |                       | > player's life which |
|                       |                       | > will be deducted if |
|                       |                       | > character hits the  |
|                       |                       | > obstacle.           |
+-----------------------+-----------------------+-----------------------+
| > Stand               | > Bitmap              | > This variable holds |
|                       |                       | > the default image   |
|                       |                       | > of the player when  |
|                       |                       | > player is not       |
|                       |                       | > moving.             |
+-----------------------+-----------------------+-----------------------+
| > X                   | > Double              | > This variable holds |
|                       |                       | > X position of the   |
|                       |                       | > player.             |
+-----------------------+-----------------------+-----------------------+
| > Y                   | > Double              | > This variable holds |
|                       |                       | > Y position of the   |
|                       |                       | > player.             |
+-----------------------+-----------------------+-----------------------+
| > Jump_Action         | > Bool                | > This Boolean        |
|                       |                       | > variable holds      |
|                       |                       | > binary value which  |
|                       |                       | > defines if player   |
|                       |                       | > is performing a     |
|                       |                       | > jump action.        |
+-----------------------+-----------------------+-----------------------+
| > Jump_Anim           | > Animation           | > This variable holds |
|                       |                       | > the animation       |
|                       |                       | > sequence of the     |
|                       |                       | > player's jump       |
|                       |                       | > action.             |
+-----------------------+-----------------------+-----------------------+
| > Run_Anim            | > Animation           | > This variable holds |
|                       |                       | > the animation       |
|                       |                       | > sequence of the     |
|                       |                       | > player's run        |
|                       |                       | > action.             |
+-----------------------+-----------------------+-----------------------+
| > Direction           | > Bool                | > This Boolean        |
|                       |                       | > variable defines    |
|                       |                       | > which direction the |
|                       |                       | > player is moving.   |
+-----------------------+-----------------------+-----------------------+

**Obstacle:**

Obstacle is the structure of the enemy sprite.

+-----------------------+-----------------------+-----------------------+
| > **Variable**        | > **Data Type**       | > **Definition**      |
+=======================+=======================+=======================+
| > Obstacle_Type       | > Enum                | > This enumeration    |
|                       |                       | > defines the type of |
|                       |                       | > the obstacle.       |
+-----------------------+-----------------------+-----------------------+
| > Obsticle_Anim       | > Animation           | > This variable holds |
|                       |                       | > the animation       |
|                       |                       | > sequence of the     |
|                       |                       | > obstacle.           |
+-----------------------+-----------------------+-----------------------+
| > Obstacle_Sound      | > String              | > This variable holds |
|                       |                       | > the name of the     |
|                       |                       | > sound which will be |
|                       |                       | > played when player  |
|                       |                       | > hits the obstacle.  |
+-----------------------+-----------------------+-----------------------+
| > X                   | > Double              | > This variable holds |
|                       |                       | > X position of the   |
|                       |                       | > obstacle.           |
+-----------------------+-----------------------+-----------------------+
| > Y                   | > Double              | > This variable holds |
|                       |                       | > Y position of the   |
|                       |                       | > obstacle.           |
+-----------------------+-----------------------+-----------------------+

**Coin:**

Coin is the structure of the gold coin sprite.

+-----------------------+-----------------------+-----------------------+
| > **Variable**        | > **Data Type**       | > **Definition**      |
+=======================+=======================+=======================+
| > Coin_Anim           | > Animation           | > This variable holds |
|                       |                       | > the animation       |
|                       |                       | > sequence of the     |
|                       |                       | > coin.               |
+-----------------------+-----------------------+-----------------------+
| > Coin_Sound          | > String              | > This variable holds |
|                       |                       | > the name of the     |
|                       |                       | > sound\              |
|                       |                       | > which will be       |
|                       |                       | > played when player  |
|                       |                       | > hits the coin.      |
+-----------------------+-----------------------+-----------------------+
| > X                   | > Double              | > This variable holds |
|                       |                       | > X position of the   |
|                       |                       | > coin.               |
+-----------------------+-----------------------+-----------------------+
| > Y                   | > Double              | > This variable holds |
|                       |                       | > Y position of the   |
|                       |                       | > coin.               |
+-----------------------+-----------------------+-----------------------+

**Treasure:**\
Treasure is the structure of the treasure sprite.

+-----------------------+-----------------------+-----------------------+
| > **Variable**        | > **Data Type**       | > **Definition**      |
+=======================+=======================+=======================+
| > Treasure_Type       | > Enum                | > This enumeration    |
|                       |                       | > defines the type of |
|                       |                       | > the treasure.       |
+-----------------------+-----------------------+-----------------------+
| > Treasure_Anim       | > Animation           | > This variable holds |
|                       |                       | > the animation       |
|                       |                       | > sequence of the     |
|                       |                       | > treasure.           |
+-----------------------+-----------------------+-----------------------+
| > Treasure_Sound      | > String              | > This variable holds |
|                       |                       | > the name of the     |
|                       |                       | > sound which will be |
|                       |                       | > played when player  |
|                       |                       | > hits the treasure.  |
+-----------------------+-----------------------+-----------------------+
| > X                   | > Double              | > This variable holds |
|                       |                       | > X position of the   |
|                       |                       | > treasure.           |
+-----------------------+-----------------------+-----------------------+
| > Y                   | > Double              | > This variable holds |
|                       |                       | > Y position of the   |
|                       |                       | > treasure.           |
+-----------------------+-----------------------+-----------------------+
