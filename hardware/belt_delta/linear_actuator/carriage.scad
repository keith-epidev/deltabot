include <../../lib/LM8UU.scad>;
include <bracket.scad>;
include <../../hardware/extruder.scad>
$fn = 40;

carriage_clamp();

module carriage_clamp(){
color("white"){
difference(){
union(){
cube([8,12,4]);
translate([4,0,0]){
	cylinder(r=4,h=4);
	translate([0,12,0]) cylinder(r=4,h=4);
}
}

translate([4,0,-1]){
	cylinder(r=1.7,h=7);
	translate([0,12,0]) cylinder(r=1.7,h=7);
}

}}
}

module carriage(){
color("white"){

difference(){
union(){


difference(){
translate([0,10,8]) rotate([0,270,0])fillet(9,32);
for(j = [-10,3])
	translate([j,10,0])
		cube([7,10,20]);

for(j = [-22,15])
	translate([j,17,0])
		cube([7,10,20]);


}


difference(){
for(i = [0,1])
mirror([i,0,0]){
difference(){
translate([0,-10,0]) cube([41,20,24]);
translate([27,0,-1]) cylinder(r=15/2,h=26);
translate([27,-4,-1]) cube([20,8,26]);



translate([41,0,0]) rotate([270,180,0])fillet(5,25);
translate([41,0,24]) rotate([90,180,0])fillet(5,25);


}


//bearing
//translate([27,0,0]){LM8UU();}
}

translate([4,-7,-1]) cube([12,14,26]);
translate([-3,-3,-1]) cube([8,6,26]);
translate([-10,-3,-1]) cube([4,6,26]);
}
translate([0,4,0]) 
difference(){
traxxis_mount();
translate([0,-1,-1]) cube([20,5,12]);
}
}

for(j = [0,16])
for(i = [0,1])
translate([0,0,j])
mirror([i,0,0]){
translate([-37,20,4]) rotate([90,0,0]) cylinder(r=1.6,h=40);
translate([-37,13,4]) rotate([90,0,0]) cylinder(r=4,h=6);
translate([-37,-7,4]) rotate([90,0,0]) cylinder(r=4,h=6);
}

for(i = [0,1])
mirror([0,i,0]){
translate([-8,6,-1]){ rotate([0,0,0]) cylinder(r=1.7,h=30);
// hex(s=4,d=5);
cylinder(r=3.5,h=4);
}
}
//end stop pole
translate([0,13,-1]){ rotate([0,0,0]) cylinder(r=1.5,h=16);

}

}

}}


carriage();
//platform();
//translate([-12,-6,8]) carriage_clamp();
