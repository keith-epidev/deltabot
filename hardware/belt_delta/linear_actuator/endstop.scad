$fn=100;

difference(){
union(){
	translate([-3,-1,0]) cube([10,2,10]);
	cylinder(r=2.5,h=5);
}

translate([0,0,-1])
cylinder(r=1.5,h=4);
}
