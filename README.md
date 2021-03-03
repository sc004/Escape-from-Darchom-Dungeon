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

From here the Dungeon class will take over and give the client a menu to build their player.  They will be allocated a certain number of points to be split between the player objects health, attack, defense, and speed.  After the dungeon class receives valid data from the client, the player is generated with a set number of items to start with.  At this point the first encounter of the current level will have its encounterID read and depending on the result, one being an enemy encounter, two being a trap encounter, and three being an item encounter, the player object will be foisted into their interaction functions.  Once the interaction has concluded, if the player object still has hp, the next encounter in the level's encounter vector is interacted with.  This process will continue until everyone of the level's encounters has been passed or if the player runs out of health.  If the current level's encounters were passed, the dungeon advances a level and the process repeats with the new level's encounter vector.  Once the player has passed through every encounter in each level's encounter vector, the game will conclude.

 
## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
