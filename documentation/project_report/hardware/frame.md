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
- Expensive at \$25 per meter
- Hard to source

[H-Beam](img/H-Beam.png)

Positives
- Very strong in the vertical direction
- Cheap at \$5 per meter
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



