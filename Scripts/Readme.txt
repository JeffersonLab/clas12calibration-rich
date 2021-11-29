------- GasSTL ------

The Python script is written as a jupyter noteook, It requires to have stl mesh package installed, as well as numpy.
Given the path of the old GAS STL volume (formally Rich_S4). The script reduce the volume in the vertical direction by a factor reduction.
The Y component are replaced by that ammount times the tangent of the opening angle of the sector.
The Z omponent are replaced by the maximum Z value in the rich (given by the aluminum top corner piece



--- ShrinkSTL-----

The Python script is written as jupyter notebook. It required to have stl mesh package installed as well as  numpy.
Given a folder containing STL, it shring all the STL and save them in a Small subfolder (path given by hand).
The script identifies the center of gravity(COG) of the volume, translate the vertex in the COG and multiplies the verteces by a scale factor
(I used 0.997 factor to avoid overlap). Then the stl is moved back in the original position and saved as new STL  
