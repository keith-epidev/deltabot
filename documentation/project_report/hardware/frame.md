Frame
=====

We have selected two possible struts to build the framework. Both are made of aluminium so are reasonable light.

[System30 Beam](/img/system30_img.JPG)

Positives
- Very strong in any direction
- Simple mounting and joining
- Reusable
- Easy to modify / tune

Negatives
- Expensive at $25 per meter
- Hard to source

[H-Beam](img/H-Beam.png)

Positives
- Very strong in the vertical direction
- Cheap at $5 per meter
- Easy to obtain

Negatives
- Flexes in the horizontal direction
- Will have to drill to mount securely

Currently, the prototype material has not been decided. The H-Beam offers a significant reduction in price, and those savings can be passed on to other aspects of the project. However, System30s provide a better investment during the prototyping phase as they can be easily modified throughout the project. It should also be mentioned that System30 like beams are generally used for CNC machines, especially hobbyist versions.

[Frame Design](img/frame.svg)

The frame will have a small enclosed area for the electronics and power supply. The printer bed is mounted on top of the case. There is a beam on the top level that intersects the face in half. This is primarily for a place to mount the plastic feeder but also serves as a structural support beam.

We will need to know how much material to order. There is 3 equilateral triangles with side lengths of $D$  and there are 3 rails that need to be of $2D + 3*.03$. The later 0.03 is to allocate room for an enclosure so that we can maintain a symmetrical print area. But for practiacle purposes, we will not consider the extra length so that it is possible to use a multiple of the original materials length.
$$M = 3(3D) + 3(2D)  + {\sqrt{3}\over 2}D$$
$$M = (15 +  {\sqrt{3}\over 2} )D$$
Now, we need rewrite this by substituting the relationship between $D$ and the print bed radius $b$.
$$ D = 2\sqrt{3}(b+r) $$
$$M(r,b) = (15 +  {\sqrt{3}\over 2} ) ( 2\sqrt{3}(b+r)) $$
To minimise waste, $D$ needs to be a multiple of the purchased material's length. The H-Beam comes in one and three meter lengths. To further reduce waste, the purchased length should be close to a whole number.

</p>
<tab>
<table class='table  table-bordered'>
<tr class='info'><td>Print bed radius</td><td>diameter</td>	<td>Multiple</td>	<td>Purchased Length</td>	<td>D</td>	<td>Total Required</td>	<td>Cost</td></tr>
<tr><td>0.002075015</td>	<td>0.0041500299</td>	<td>9</td>	<td>1</td>	<td>0.1111111111</td>	<td>1.7566666667</td>	<td>8.7833333333</td></tr>
<tr><td>0.0060843918</td>	<td>0.0121687836</td>	<td>8</td>	<td>1</td>	<td>0.125</td>	<td>1.965</td>	<td>9.825</td></tr>
<tr><td>0.0112393049</td>	<td>0.0224786099</td>	<td>7</td>	<td>1</td>	<td>0.1428571429</td>	<td>2.2328571429</td>	<td>11.1642857143</td></tr>
<tr><td>0.0181125224</td>	<td>0.0362250449</td>	<td>6</td>	<td>1</td>	<td>0.1666666667</td>	<td>2.59</td>	<td>12.95</td></tr>
<tr><td>0.0277350269</td>	<td>0.0554700538</td>	<td>5</td>	<td>1</td>	<td>0.2	<td>3.09</td>	<td>15.45</td></tr>
<tr><td>0.0421687836</td>	<td>0.0843375673</td>	<td>4</td>	<td>1</td>	<td>0.25</td>	<td>3.84</td>	<td>19.2</td></tr>
<tr><td>0.0566025404</td>	<td>0.1132050808</td>	<td>10</td>	<td>3</td>	<td>0.3	<td>4.59</td>	<td>22.95</td></tr>
<tr><td>0.0662250449</td>	<td>0.1324500897</td>	<td>3</td>	<td>1</td>	<td>0.3333333333</td>	<td>5.09</td>	<td>25.45</td></tr>
<tr><td>0.0782531755</td>	<td>0.1565063509</td>	<td>8</td>	<td>3</td>	<td>0.375</td>	<td>5.715</td>	<td>28.575</td></tr>
<tr><td>0.0937179148</td>	<td>0.1874358297</td>	<td>7</td>	<td>3</td>	<td>0.4285714286</td>	<td>6.5185714286</td>	<td>32.5928571429</td></tr>
<tr class='success'><td>0.1143375673</td>	<td>0.2286751346</td>	<td>2</td>	<td>1</td>	<td>0.5	<td>7.59</td>	<td>37.95</td></tr>
<tr><td>0.1432050808</td>	<td>0.2864101615</td>	<td>5</td>	<td>3</td>	<td>0.6	<td>9.09</td>	<td>45.45</td></tr>
<tr class='success'><td>0.1865063509</td>	<td>0.3730127019</td>	<td>4</td>	<td>3</td>	<td>0.75</td>	<td>11.34</td>	<td>56.7</td></tr>
<tr><td>0.2586751346</td>	<td>0.5173502692</td>	<td>1</td>	<td>1</td>	<td>1</td>	<td>15.09</td>	<td>75.45</td></tr>
<tr><td>0.4030127019</td>	<td>0.8060254038</td>	<td>2</td>	<td>3</td>	<td>1.5</td>	<td>22.59</td>	<td>112.95</td></tr>
<tr><td>0.8360254038</td>	<td>1.6720508076</td>	<td>1</td>	<td>3</td>	<td>3</td>	<td>45.09</td>	<td>225.45</td></tr>
</table>
<div>List of lengths vs cost</div>
</tab>


