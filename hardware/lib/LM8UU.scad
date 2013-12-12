include <shapes.scad>;



module R608zz(){
R = 22/2;
r = 8/2;
w = 7;

color("silver")
difference(){
	cylinder(r=R,h=w);
	cylinder(r=r,h=w*3,center=true);

}

}



module LM8UU(){
h = 24;
d = 15/2;
inner = 8/2; //m8
offset = 4;

difference(){
ring(h,"silver",d,d-1);

for(i = [offset,h-offset-1]) //why the -1?
translate([0,0,i]) ring(1,"silver",d+1,d-.5);

}


ring(h,"black",d-1,inner);








}


