 # Escape from Darchom Dungeon
  Authors:  [Jimmy Li](https://github.com/jli283-hub), [Bradley Morck](https://github.com/football3o), [Shreya Chitturi](https://github.com/sc004)

## Project Description
This project is interesting to us because it allows a lot of possibilities and creative freedom. We can also give the user more freedom and these interactions can change how one
might reach the conclusion. This project also seems challenging, yet fun at the same time because we get to apply the concepts we learned in class in a fun way.

Language: C++

Github

Hammer

We will prompt the user with a few choices to choose from. Once the user decides what they would like to do, they will input their choice into the console. Based upon
the user’s input, the program will output what will now happen to the user as well as any stats that they may need to make future decisions.

Composite: The composite design pattern is a structural design pattern that focuses on the composition of objects and classes. In this specific pattern, we can create a tree
structure to represent hierarchies and it is made of four parts, component, leaf, composite, and client. We picked the Composite pattern because it allows us to combine groups
of objects together. An issue that we could come across in our game is when we are trying to create a dungeon composed of different levels. In our game, we will be declaring a
class named Level which will act as a base class for the specific types of levels. It will simplify what is changed from level to level by adjusting variablevalues in the
subclasses of the main dungeon class. The base class Level will have an aggregate relationship with the DungeonManager class that stores a pointer to a level. 

Abstract Factory: The abstract factory pattern is a creational pattern that creates a factory of related objects and it is made up of AbstractFactory, ConcreteFactory,
AbstractProduct, ConcreteProduct, and the client. We picked this pattern because it allows us to efficiently create families of products. In our game, we will be using this 
pattern to create different products of encounters the player could face, such as a enemy, trap, or item encounter. The abstract factory class simplifies the creation of each of
the encounter abstract products and the implementation of the concrete products.



## Class Diagram
![alt text](https://github.com/cs100/final-project-bmorc001-jli283-schitt008/blob/master/Design%20Document.png)

Above this is the OMT diagram for our RPG project.  The program functions by generating a dungeon through the dungeon manager.  The client will designate to the manager how many levels they would like the dungeon to be.  On doing so the dungeon manager will call one of three level constructors for each level the client wanted to construct.  The level constructors will subsequently call one of three encounter concrete implementations of our abstract encounter factory class.  One of the three will be chosen at random in order to fill up the level's encounter vector.  These three are the enemy encounterfactory, loot encounter factory, and the trap encounter factory.  All of these generate an encounter of their specific type.  EnemyEncounterFactory will generate an enemy encounter and it will be populated with one of three enemies.  This enemy will be given an item dependent on a random itemID that will drop when the enemy is defeated.  ItemEncounterFactory will generate an itemEncounter and populate it with any one of the item subclasses dependent on the itemID it randomly generates.  TrapEncounterFactory will generate a TrapEncounter and populate it with one of three trap types.  Each generated encounter is subsequently added to the level's encounter vector in the order they were generated.  This process continues until all the levels have their encounter vectors populated.

From here the Dungeon class will take over and give the client a menu to build their player.  They will be asked to give a certain number for health within a range given, along with a certain number for attack, and a certain number for speed.  After the dungeon class receives valid data from the client, the player is generated and moved into a double loop that traverses every encounter in every level.  At this point the first encounter of the current level will have its encounterID read and depending on the result, one being an enemy encounter, two being a trap encounter, and three being an item encounter, the player object will be foisted into their interaction functions.  Once the interaction has concluded, if the player object still has hp, the next encounter in the level's encounter vector is interacted with.  This process will continue until everyone of the level's encounters has been passed or if the player runs out of health.  If the current level's encounters were passed, the dungeon advances a level and the process repeats with the new level's encounter vector.  Once the player has passed through every encounter in each level's encounter vector, the game will conclude.
 
 ## Screenshots
 Generating Dungeon and player:
 ![Generate Dungeon](https://github.com/cs100/final-project-bmorc001-jli283-schitt008/blob/master/Generate.png)
 
 In an Item Encounter:
 
 ![Item Encounter](https://github.com/cs100/final-project-bmorc001-jli283-schitt008/blob/master/ItemEncounter.png)
 
 In a Trap Encounter:
 
 ![Trap Encounter](https://github.com/cs100/final-project-bmorc001-jli283-schitt008/blob/master/TrapEncounter.png)
 
 In an Enemy Encounter:
 
 ![Enemy Encounter](https://github.com/cs100/final-project-bmorc001-jli283-schitt008/blob/master/EnemyEncounter.png)
 
 In the Player's backpack:
 
 ![Player Backpack](https://github.com/cs100/final-project-bmorc001-jli283-schitt008/blob/master/Backpack.png)
 
 ## Installation/Usage
 Using git, clone this repository and then `cd` into it.
 
```
git clone https://github.com/cs100/final-project-bmorc001-jli283-schitt008.git
cd final-project-bmorck001-jli283-schitt008
```

Our project uses 'cmake' as well as 'make', but on Hammer, the specific cmake is 'cmake3'.  These tools are available on Linux, and can be installed from their respective websites.  Once they are installed, the following commands can be executed.

```
cmake3 .
make
```

The following executables will be created

```
WeaponTest
EnemyTest
ArmorTest
PlayerTest
MainTest
```

Running `./MainTest` will run our dungeon exploring program.

The program can be operated by sending commands indicated by the text output to the screen.  
In creating the dungeon, you designate how many levels you would like it to contain.
In player creation, you send values to construct a unique player object that will explore the dungeon.
During all of the encounters and in between them, you interact with the program through inputing indicated responses such as '1' or '2'.

 ## Testing
 Testing was done through multiple testing executables, each designated towards a different type of object.  
 'WeaponTest' subjected every weapon that the player could interact with to tests designed to test the classes' functions.  
 'EnemyTest' confirmed that each different type of enemy its functinos working as intended.  
 'ArmorTest' was used to confirm that each different type of armor was returning accurate values when their functions were called.
 'PotionTest' confirmed that each subclass of potion was modifying the player in the way it was intended.
 'PlayerTest' ran through each of player's functions in order to confirm that they were being implemented properly and modifying the correct attributes and variables.
 
 <details><summary>Example of the WeaponTest</summary>
 <p>
  ```
  
[bmorc001@hammer final-project-bmorc001-jli283-schitt008]$ ./WeaponTest
[==========] Running 16 tests from 4 test suites.
[----------] Global test environment set-up.
[----------] 4 tests from SwordTest
[ RUN      ] SwordTest.Constructor
[       OK ] SwordTest.Constructor (0 ms)
[ RUN      ] SwordTest.advPointTest
[       OK ] SwordTest.advPointTest (0 ms)
[ RUN      ] SwordTest.DurabilityTest
[       OK ] SwordTest.DurabilityTest (0 ms)
[ RUN      ] SwordTest.NameTest
[       OK ] SwordTest.NameTest (0 ms)
[----------] 4 tests from SwordTest (0 ms total)

[----------] 4 tests from SpearTest
[ RUN      ] SpearTest.Constructor
[       OK ] SpearTest.Constructor (0 ms)
[ RUN      ] SpearTest.advPointTest
[       OK ] SpearTest.advPointTest (0 ms)
[ RUN      ] SpearTest.DurabilityTest
[       OK ] SpearTest.DurabilityTest (0 ms)
[ RUN      ] SpearTest.NameTest
[       OK ] SpearTest.NameTest (0 ms)
[----------] 4 tests from SpearTest (0 ms total)

[----------] 4 tests from BowTest
[ RUN      ] BowTest.Constructor
[       OK ] BowTest.Constructor (0 ms)
[ RUN      ] BowTest.advPointTest
[       OK ] BowTest.advPointTest (0 ms)
[ RUN      ] BowTest.DurabilityTest
[       OK ] BowTest.DurabilityTest (0 ms)
[ RUN      ] BowTest.NameTest
[       OK ] BowTest.NameTest (0 ms)
[----------] 4 tests from BowTest (0 ms total)

[----------] 4 tests from ShieldTest
[ RUN      ] ShieldTest.Constructor
[       OK ] ShieldTest.Constructor (0 ms)
[ RUN      ] ShieldTest.advPointTest
[       OK ] ShieldTest.advPointTest (0 ms)
[ RUN      ] ShieldTest.DurabilityTest
[       OK ] ShieldTest.DurabilityTest (0 ms)
[ RUN      ] ShieldTest.NameTest
[       OK ] ShieldTest.NameTest (0 ms)
[----------] 4 tests from ShieldTest (0 ms total)

[----------] Global test environment tear-down
[==========] 16 tests from 4 test suites ran. (1 ms total)
[  PASSED  ] 16 tests.
```
