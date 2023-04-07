# SplashKit Games and Tutorials
 
## Overview
Here, we will create a game using SplashKit SDK, along with a comprehensive tutorial. When we select the game to be developed, we will focus on how we can apply most of the functionalities available in the splashkit SDK. We will focus on the best practice of C++ programing and principles of secure coding.

In the development of tutorial, we will try to explain the concepts and the codes as simple as possible. We will target this tutorial to absolute beginners, so it will lead new programmers into game development.

## Background 
![11](https://user-images.githubusercontent.com/68922962/230664810-a6807531-24fe-4447-8be9-f1c8f32b97c8.JPG)

Resurrection is the story of a man attempting to return to the world of the “living”. Our story starts with Joe, an average, middle-aged man. He and his wife (Mary) have decided to have a working bee afternoon, completing a series of chores in the backyard of their suburban home with the help of their young son (Patrick). As dusk approaches, the family have almost completed their tasks. All that is left is for Joe to clear the gutters before the fire season starts. 

Joe places his ladder carefully against their home and ascends. He knows he needs to be careful and approaches the task with well-deserved caution. Patrick, being young, doesn’t understand the precautions taken and simply wants to play with his dad. Mary looks on in horror as Patrick runs to his father, bumping the ladder and knocking Joe to the ground. Joe suffers a massive head injury and as a result slips into a coma. 

Throughout the game, Joe is challenged to unlock his memory by outsmarting popular childhood video game villains. However, due to the nature of his injury, he is unable to conjure accurate depictions of these characters. With each level, he unlocks a core memory. 
### Level 1 

In level one, Joe has the image of a ring (which we know as Mary’s wedding ring). In this level, he is a blue hedgehog. As he runs, he sees gold coins which he collects. As he collects these, a positive ‘ding’ sounds, indicating that this is what he should be doing. In his path are small bushes which need to be jumped over, and birds will be flying at a low height which should be ducked under. If he runs into the bush or a bird, then he will respawn at the start of the level. In the background is a bright blue sky with clouds and a tall palm tree. 

#### Gameplay 

> •Must be able to collect gold rings. 

> •Must be able to jump over. 

> •Jumping should be both static and moving. 

> •Must be able to duck under. 

> •Ducking should be both static and moving. 

> •At the end of the level, a gold ring with a diamond is collected. This is a symbol of unlocking the memory of his wife, Mary who appears at the end of the level in a thought bubble. 

### Level 2 

In level two, Joe has unlocked the memory of his wife, Mary. Mary tells Joe how much she has missed him as he’s been asleep. He has an almost memory montage where he remembers meeting her, proposing, their wedding day and then a memory of Mary holding a pair of baby-sized sneakers. Joe is shocked and doesn’t know what she is talking about. In this level, Joe transforms into a bandicoot who wears surfer shorts, sneakers and a baseball cap. In this level, Joe collects apples, however during the level there are two boxes which need to be broken. Each of these contain a sneaker (one left, one right) and these boxes need to be broken and the sneaker collected, otherwise Joe cannot progress to the next level. The background will be set on a sandy beach with rocks and palm trees in the background. 


### Gameplay 

> •Must be able to collect apples. 

> •Must be able to break boxes containing sneakers. 

> •If the sneakers are not collected from the boxes at the end of the level, then the character should respawn at the start of the level. 

> •Boxes can be hidden in bushes. 

> •At the end of the level, the sneakers unlock the memory of Patrick, Joe’s son who appears again in a thought bubble. 

### Final Level 

In this level, both Patrick tells Joe how sorry he is for putting him in the hospital. Joe has a memory of falling off the ladder and things fade to black, however he can see his home as though it is a castle. He sees his happy family on the inside and feels he needs to escape his coma and save his family. This level is set with a blue background with bushes and warp pipes visible. Joe is dressed in overalls, wears a cap, and has a moustache. In this level, Joe simply must outrun the darkness that follows him. The darkness is very close and if he runs into any buses, bricks, or warp pipes then he will be engulfed by the sleep that follows him. 

### Gameplay 

> •Must be able to run. 

> •Must be able to jump over obstacles. 

> •Blackness should follow Joe as he runs. 

> •Ending 

> •After defeating the three levels, Joe awakens from his coma. He sees Mary and Patrick beside the hospital bed, Mary with her engagement/wedding ring and Patrick  with his sneakers. They return to their red brick house together. 


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

