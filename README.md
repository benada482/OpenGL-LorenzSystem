# Lorenz System Simulation:

## Intro:
This software uses particles to simulate a Lorenz System. It spawns a certain amount of particles that will then follow the differetial equations to update their positions. 
These equations were created by Edward Lorenz to show a simplified model of atmospheric convection. 

## Research Papers: 
I have compiled some important and worthwhile research papers into the given effect that I want to create and how the particle system can be improved and further developed to ensure a well made project. 
The webpage howstuffworks[1], has created a short article explaining the nature of a Lorenz System, how it was created and how it works. This is important for getting a baseline understanding of the project. 

The system was original created by meteorologist Edward Lorenz[2]This paper was researching weather patterns and the further they looked into the future to predict weather the lower the accuracy of the prediction. Lorenz simplified the atmospheric equations as much as possible to create a simple model that represented convection currents within the atmosphere. This then created the shape of the Lorenz System when the data was inputted into a simulation program. The result of this experiment showed that small changes in variables within this equation caused massive effects later on. This created an example of a chaos system and the phrase butterfly effect was later adopted due to this phenomena. This work has continued to be researched into simulating the effect further and analysing the characteristics that create it[3][4].

A particle system has been chosen to display this effect as it lends itself to display this effect well. It is important to have many particles on the screen as if there are only a few the general shape of the Lorenz System will be lost and the desired effect will not be achieved. The discussion of why particle systems can achieve the usage of millions of particles and the usage of them has been discussed for a long time[5]. From this article we can see there are important topics like the 6 main steps to ensure that particles can be rendered efficiently and well. The key steps that will be used within this project are the update positions, update velocities, transfering texture data and rendering particles. These steps are the key ones for ensuring that the particles move in the correct way and get displayed on the screen. 

A Lorenz System was created through the use of boiling water to represent atmospheric convection currents. It is important to look at literature for places where particle systems have been used to simulate liquid or air flows. This research can show how this project can be furthered[6]. This gives important context and examples on how particle systems are used to simulate different effects and howdata can be gathered from these to push forward science. It also shows how it can be easier to simulate a principle rather than try to carry it out in an experiment in the real world, as some phenomena can not easily be seen or replicated.  

To create the first instance of a particle system in worksheet2 a tutorial playlist[7] was used so that I could learn and understand more of OpenGl and SDL. This tutorial showed how to make a pixel based particle system that moved around the screen while staying within the window, allowing particles to bounce off the edges of the screen. The tutorial can be found here https://www.youtube.com/playlist?list=PLmpc3xvYSk4wDCP5zjt2QQXe8-JGHa4Kt

## Profiling:
Profiling has been carried on on this project so that further creation can be guided by facts and what is needed to be improved to get better results. 

<img src=https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet2/Profiling/RCode/ParticlesFpsGraph.png width="700" height="500" />
This graph shows the correlation between the amount of particles that are rendered in this system and the Frames Per Second (FPS). This is an important component to consider for a simulation like this since particles can be within games, film and scientific research. Using a large amount of particles creates a more impressive and detailed effect, leading to it being more believable while interacting with media including it. For scientific research it is important to have the correct amount of particles while not sacrificing time to accurately simulate them. The graph follows expected trends of the more particles there are the lower the amount of FPS. Sixty FPS is a common standard to adhere to within games and graphics, the graph tells us that around 400,000 particles is where the program starts dropping below 60fps. This is expected within this program as that many particles fills most the screen so the drop in performance is expected.

<img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet2/Profiling/CPU400000particles.png" width="700" height="500" />
This graph from the profilier built into Visual Studio shows the CPU usage. From this we can see that the functions that take the most computational power and time. The SDL_main function is the main loop within the program that handles the rendering and the primary draw functions. It also calls other classes. Particle::update() is responsible for moving the particles around the screen, this takes a lot of CPU usage due to having to update each particles position and calculating if they have reached the screen border so the speed can be reversed so they bounce inside the window. The Window::setPixel is also a large usage due to it having to run through each particle to draw them to the correct place within the window. 

<img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet2/Profiling/Memory400000.png" width="700" height="500" />
This is the memory usage of the program collected from the built in profiler within Visual Studio. From the snapshots that we can see the memory usage is stable and shows no evidence of memory leaks. As the memory stays the same this should not be consider a priority to fix or improve as it does not impact the performance of the program as it is. 

## Plan:
In worksheet 2 I have successfully create a way to render and display 2D particles within the window. From the profiling carried out it can be see that it runs well with the amount of particles that is in it. Since the amount of particles it is render and has been profiled at is more than needed to be on screen at once the program will be transitioned into a 3D enviroment to add a layer of complexity itno the code. The movement of the particles will then be changed to match the Lorenz Attractor differential equations so that they move in a way that resembles the attractor. After this has been completed and profiled worksheet 4 will have a focus on fixing any profiling issues that are found and adding user interaction through the usage of a GUI. 

## References
To create the first instance of a particle system in worksheet2 a tutorial playlist was used so that I could learn and understand more of OpenGl and SDL[8]. This tutorial showed how to make a pixel based particle system that moved around the screen while staying within the window, allowing particles to bounce off the edges of the screen.

[1] W. Harris, ‘How Chaos Theory Works’, HowStuffWorks. Accessed: Dec. 17, 2024. [Online]. Available: https://science.howstuffworks.com/math-concepts/chaos-theory.htm
[2] E. N. Lorenz, ‘Deterministic Nonperiodic Flow’, AMS, vol. 20, no. 2, pp. 130–141, Mar. 1963.
[3] Q. Yao and G. Liu, ‘Simulation and analysis of Lorenz system’s dynamics characteristics’, in 2009 International Conference on Image Analysis and Signal Processing, Apr. 2009, pp. 427–429. doi: 10.1109/IASP.2009.5054666.
[4] A. S. Elwakil, S. Ozoguz, and M. P. Kennedy, ‘Creation of a complex butterfly attractor using a novel Lorenz-Type system’, IEEE Transactions on Circuits and Systems I: Fundamental Theory and Applications, vol. 49, no. 4, pp. 527–530, Apr. 2002, doi: 10.1109/81.995671.
[5] L. Latta, ‘Building a Million-Particle System’, Game Developer. Accessed: Dec. 17, 2024. [Online]. Available: https://www.gamedeveloper.com/programming/building-a-million-particle-system
[6] J. Kruger, P. Kipfer, P. Konclratieva, and R. Westermann, ‘A particle system for interactive visualization of 3D flows’, IEEE Transactions on Visualization and Computer Graphics, vol. 11, no. 6, pp. 744–756, Nov. 2005, doi: 10.1109/TVCG.2005.87.
[7]	Cave of Programming, ‘Cave of Programming, C++ Tutorial for Beginners’, YouTube. Accessed: Dec. 19, 2024. [Online]. Available: https://www.youtube.com/channel/UCnAdXkr17iQS8YcYl0LhPdw


