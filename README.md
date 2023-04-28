# the_GOCE_satellite
Toy model for testing the sensitivity of the GOCE satellite.


The GOCE satellite orbited around the Earth from 2009 to 2013 at a 250km distance from Earth's ground. Its main duty was to analyse variations of the Earth's gravitational field. The sensitivity reached by the on-board instruments was of δg/g = 1E-13. 

A toy model of the physical problem is constructed: the Earth is place a the center of our reference frame. The GOCE's orbit is discretized with 1000 point. A fake montain range is placed on the earth's surfaces. The montain range is modeled with 100 consecutive circles placed on the surface of the Earth. If we imagine the Earth as a big circle of radius R, the little montains are placed on a countour of (-R,pi) where the first coordinate is the radial distance from the origin and the second coordinate is the angle in radiants. 

This program checks if the GOCE satellite is able to feel the presence of the montain range. 
First, the bare earth's gravitational field on the points of the GOCE orbit is computed. Second, we add point by point the gravitational field produced by the montain and the earth's gravitational field. Eventually, the variations of the modulus of the gravitational field are computed. 
There are 2 output files: a pdf file which is a graph showing the variations of the field as a function of the angle and a txt file printing all the variations that the GOCE satellite is able to feel (namely, only the components bigger than 1E-13).

The graph on the pdf file is produced using ROOT libraries. If you have ROOT install on your computer, you can drop out the // at the end of the main and produce your own canvas!     

For compiling the program, I added a simple makefile: just type "make" on the terminal addressed to the directory containing all the scripts.
