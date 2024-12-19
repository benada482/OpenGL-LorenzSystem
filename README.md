# Lorenz Attractor
The Lorenz Attractor is now rendered within hte window by using a particles. These particles all start very near each other, with the spawn coordinates randomly selected to be between 0.0 and 0.09. At the beginning this creates a trail of particles that follows the same path. As the program goes on the difference in start positions becomes noticable as they seperate out to go on their own paths. This is due to the 3 differential equations that are vital to creating a Lorenz Attractor.  

# Profiling

<img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet3/Profiling/RCode/ws3particles.png" width="700" height="500" />
Since making the program operate within a three dimensional space and introducing the differential equations for the particle movement the frame rate has dropped drastically. This can be contributed to many factors that we can see through the use of profiling. The graph shows the amount of particles against the FPS, this is important to keep up as simulations can rely on having enough particles rendered to create data and create the desired pattern.

<img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet3/Profiling/Images/CPU400k.png" width="700" height="500" />
<img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet3/Profiling/Images/CPU400k2.png" width="700" height="500" />
<img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet3/Profiling/Images/CPUthread400k.png" width="700" height="500" />
<img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet3/Profiling/Images/Memory400k.png" width="700" height="500" />



<img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet3/Profiling/Images/CPU1million.png" width="700" height="500" />
<img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet3/Profiling/Images/CPU1million2.png" width="700" height="500" />
<img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet3/Profiling/Images/CPUthread1million.png" width="700" height="500" />
<img src="https://github.falmouth.ac.uk/GA-Undergrad-Student-Work-24-25/comp305-2203238/blob/worksheet3/Profiling/Images/Memory1million.png" width="700" height="500" />
