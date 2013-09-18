include <lib/nema.scad>;
include <threaded.scad>;
include <plate.scad>;
include <top_end.scad>;
use <carriage.scad>;


$fn = 10;
height = 330;
width = height /2;


module bracket(){
outer = 42/2;
inner = 31/2;
len = 0;
plate_height = 16;
outset = 26;

union(){
for(j = [0,180])
rotate([0,0,j])
color("white") {
translate([-inner,outer,0]){ 
	difference(){
	union(){
	cube([inner*2,5,plate_height]);
	rotate([0,90,0])
	translate([-8,5,0]){
		cylinder(r=8,h=inner*2);
		translate([-4,4,0])cube([10,8,inner*2]);
	}
	translate([0,0,-8]) cube([inner*2,10,10]);
	}
	rotate([0,90,0]) translate([-8,5,-1]) cylinder(r=4,h=inner*2+3);
	translate([-10,6,5]) cube([105,14,5]);
	


	for(i = [0,12,24]){
		translate([3+i,14,0]) cylinder(r=1.3, h=20);
	}

	}
}
}

difference(){
nema_plane(outer,inner,plate_height,1.5,"white");
color("white") {
cylinder(r=15,h=plate_height*2+1,center = true);
translate([0,-10,0]) rotate([0,0,90])  cube([20,30,25]);
}
}




}

}



bracket();
nema17();
