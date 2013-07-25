include <nema.scad>;
include <threaded.scad>;
include <plate.scad>;
include <top_end.scad>;
use <carriage.scad>;


$fn = 10;
height = 330;
width = height /2;

module side(){

plate();
nema17();
translate([0,0,height/2]) carriage();
translate([0,0,30]) rotate([0,180,0]) coupler();
translate([0,0,height]) rotate([180,0,180]) top_end();

//center bar
translate([0,0,26]) threaded(h=height-30);

//vertical bars
for(i = [-16,16])
translate([i,0,0]) threaded(h=height);

//horizontal supports
for( z = [4,height-6])
translate([16,0,z]) 
rotate([90,0,30])
threaded(h=height/2);

//cross struts
for(r = [-1,1])
translate([r*16,0,4]) 
rotate([30,0,r*30])
threaded(h=height*sqrt(1.25),r=2);








}







for(i = [0:2])
rotate([0,0,(i*360)/3])
translate([0,width*sqrt(2)/2,0])
side();

