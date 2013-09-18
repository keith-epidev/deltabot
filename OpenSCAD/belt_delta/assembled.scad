include <bracket3.scad>;
include <lib/nema.scad>;
include <lib/LM8UU.scad>;
include <carriage2.scad>;

height = 330;
width = height/2;
module side(){

rotate([90,0,180]){
	nema17();
	bracket_bottom();
color("white")
translate([0,0,20])
rotate([180,0,0])
import("18Tooth-GT2-Pulley.stl");
}


//upper
translate([0,0,330-42]){
rotate([90,0,180]){
	bracket_top();
}
for(i = [-1,1]){
color("silver"){
rotate([0,90,300])
translate([i*13,40,13])
cylinder(r=4,h=width+12);
}
}
/*
rotate([270,0,0])
translate([0,0,20])
color("white")
rotate([180,0,0])
import("18Tooth-GT2-Pulley.stl");
*/
}

translate([0,6,330/2]){
rotate([0,0,180]) carriage();

}

//horizontal
for(i = [-1,1]){
color("silver"){
rotate([0,90,300])
translate([i*13,40,13])
cylinder(r=4,h=width+12);
}


//vertical
color("silver")
translate([i*27,6,-42/2])
cylinder(r=4,h=height);




//belt
color("black")
translate([i*6,8,-42/2+20])
cube([2,3,height-40]);

}
/*
for(i = [-1,1])
translate([42/2,-42/2,i*42])
rotate([90,0,180]) color("silver") cylinder(r=4,h=330);
*/

}


//rotate
for(i = [0:2])
rotate([0,0,(i*360)/3])
translate([0,width*sqrt(2)/2,0])
side();

color("Wheat")
translate([0,0,42/2])
cylinder(r=width/2+20,h=2);

