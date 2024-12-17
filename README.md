# Lorenz System Simulation:

## Intro:
This software uses particles to simulate a Lorenz System. It spawns a certain amount of particles that will then follow the differetial equations to update their positions. 
These equations were created by Edward Lorenz to show a simplified model of atmospheric convection. 

## Research Papers: 
I have compiled some important and worthwhile research papers into the given effect that I want to create and how the particle system can be improved and further developed to ensure a well made project. 
The webpage howstuffworks, has created a short article explaining the nature of a Lorenz System, how it was created and how it works. This is important for getting a baseline understanding of the project. 
https://science.howstuffworks.com/math-concepts/chaos-theory4.htm

The system was original created by meteorologist Edward Lorenz in this paper: https://journals.ametsoc.org/view/journals/atsc/20/2/1520-0469_1963_020_0130_dnf_2_0_co_2.xml
This paper was researching weather patterns and the further they looked into the future to predict weather the lower the accuracy of the prediction. Lorenz simplified the atmospheric equations as much as possible to create a simple model that represented convection currents within the atmosphere. This then created the shape of the Lorenz System when the data was inputted into a simulation program. The result of this experiment showed that small changes in variables within this equation caused massive effects later on. This created an example of a chaos system and the phrase butterfly effect was later adopted due to this phenomena. 

A particle system has been chosen to display this effect as it lends itself to display this effect well. It is important to have many particles on the screen as if there are only a few the general shape of the Lorenz System will be lost and the desired effect will not be achieved. This paper, https://citeseerx.ist.psu.edu/document?repid=rep1&type=pdf&doi=0373e4c27a4221cdd5e680bba2516536334b03fd the discussion of why particle systems are used and how to achieve a particle system that can manage a million particles at once. It covers important topics like the 6 main steps to ensure that particles can be rendered efficiently and well. The key steps that will be used within this project are the update positions, update velocities, transfering texture data and rendering particles. These steps are the key ones for ensuring that the particles move in the correct way and get displayed on the screen. 

A Lorenz System was created through the use of boiling water to represent atmospheric convection currents. It is important to look at literature for places where particle systems have been used to simulate liquid or air flows. This research can show how this project can be furthered. https://ieeexplore.ieee.org/abstract/document/1512024 This gives important context and examples on how particle systems are used to simulate different effects and howdata can be gathered from these to push forward science. It also shows how it can be easier to simulate a principle rather than try to carry it out in an experiment in the real world, as some phenomena can not easily be seen or replicated.

To create the first instance of a particle system in worksheet2 a tutorial playlist was used so that I could learn and understand more of OpenGl and SDL. This tutorial showed how to make a pixel based particle system that moved around the screen while staying within the window, allowing particles to bounce off the edges of the screen. The tutorial can be found here https://www.youtube.com/playlist?list=PLmpc3xvYSk4wDCP5zjt2QQXe8-JGHa4Kt

## Profile:

## Plan:
In worksheet 2 I have successfully create a way to render and display 2D particles within the window. Since this runs quite well as evidenced by the profiling I will be transitioning to 3D to add an extra layer of complexity.
In worksheet 3 the model will be rendered in 3 dimensions with the differential equations put in place so that the Lorenz System will be working modelling the particles moving between the attractors.
The plan for worksheet 4 is to add user engagement so that there is a way to interact with the overall model. There is also a plan to review the profiling completed within worksheet 3 and improve and optimise the program to fix any issues that can be found.

